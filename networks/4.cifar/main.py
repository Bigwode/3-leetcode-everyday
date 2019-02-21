# coding:utf-8
from __future__ import print_function

import torch
import torch.nn as nn
import torch.optim as optim
import torch.nn.functional as F
import torch.backends.cudnn as cudnn
import torchvision.transforms as transforms
import os
import argparse
from dataset.CIFAR10 import CIFAR10
from model.net import Semantic_Net
from utils.target_transform import target_transform, weights_init
from visdom import Visdom


parser = argparse.ArgumentParser(description='CIFAR10 Semantic Relationship Training')
parser.add_argument('--lr', default=1e-3, type=float, help='learning rate')
parser.add_argument('--resume', '-r', action='store_true', help='resume from checkpoint', default=False)
args = parser.parse_args()

device = 'cuda' if torch.cuda.is_available() else 'cpu'
best_acc = 0  # best test accuracy
start_epoch = 0  # start from epoch 0 or last checkpoint epoch

# Dataset Preparation
print('==> Preparing data..')
transform_train = transforms.Compose([
    # transforms.RandomCrop(32, padding=4),
    transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
    transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010)),
])

transform_test = transforms.Compose([
    transforms.ToTensor(),
    transforms.Normalize((0.4914, 0.4822, 0.4465), (0.2023, 0.1994, 0.2010)),
])


trainset = CIFAR10(root='/home/csce/桌面/data', pkl='./dataset/cifar_glove300.pickle',
                   train=True, transform=transform_train, target_transform=target_transform)
trainloader = torch.utils.data.DataLoader(trainset, batch_size=16, shuffle=True, num_workers=2)

testset = CIFAR10(root='/home/csce/桌面/data', pkl='./dataset/cifar_glove300.pickle',
                  train=False, transform=transform_test, target_transform=target_transform)
testloader = torch.utils.data.DataLoader(testset, batch_size=16, shuffle=False, num_workers=2)

classes = ('plane', 'car', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck')

# Model
print('==> Building model...')

net = Semantic_Net().to(device)
net.apply(weights_init)

# viz = Visdom(env='Semantic_CIFAR')

if device == 'cuda':
    net = torch.nn.DataParallel(net)
    cudnn.benchmark = True

if args.resume:
    # Load checkpoint.
    print('==> Resuming from checkpoint..')
    assert os.path.isdir('checkpoint'), 'Error: no checkpoint directory found!'
    checkpoint = torch.load('./checkpoint/ckpt.t7')
    net.load_state_dict(checkpoint['net'])
    best_acc = checkpoint['acc']
    start_epoch = checkpoint['epoch']

criterion = nn.CrossEntropyLoss()
optimizer = optim.Adam(net.parameters(), lr=args.lr, amsgrad=True)  # , weight_decay=5e-4

# viz.line([[0., 0.]], [0.], win='train', opts=dict(title='train loss', legend=['loss', 'acc']))


# Training
def train(epoch):
    print('\nEpoch: %d' % epoch)
    net.train()
    train_loss = 0
    correct = 0
    total = 0

    for batch_idx, (inputs, inputs_vec, targets) in enumerate(trainloader):
        inputs, inputs_vec, targets = inputs.to(device), inputs_vec.float().to(device), targets.to(device)
        optimizer.zero_grad()
        outputs = net(inputs, inputs_vec)
        loss = criterion(outputs, targets)
        loss.backward()
        optimizer.step()
        
        train_loss += loss.item()
        _, predicted = outputs.max(1)
        total += targets.size(0)
        correct += predicted.eq(targets).sum().item()
        # viz.line([[loss.item(), correct / total]], [epoch*(len(trainloader))+batch_idx], win='train', update='append')
        
        print(batch_idx, len(trainloader), 'Loss: %.3f | Acc: %.3f%% (%d/%d)'
            % (train_loss/(batch_idx+1), 100.*correct/total, correct, total))


def test(epoch):
    global best_acc
    net.eval()
    test_loss = 0
    correct = 0
    total = 0

    with torch.no_grad():
        for batch_idx, (inputs, inputs_vec, targets) in enumerate(testloader):
            inputs, inputs_vec, targets = inputs.to(device), inputs_vec.float(). to(device), targets.long().to(device)
            outputs = net(inputs, inputs_vec)
            loss = criterion(outputs, targets)

            # test_loss += loss.item()
            _, predicted = outputs.max(1)
            total += targets.size(0)
            correct += predicted.eq(targets).sum().item()

            print(batch_idx, len(testloader), 'Acc: %.3f%% (%d/%d)'
                % (100.*correct/total, correct, total))

    # Save checkpoint.
    acc = 100.*correct/total
    if acc > best_acc:
        print('Saving..')
        state = {
            'net': net.state_dict(),
            'acc': acc,
            'epoch': epoch,
        }
        if not os.path.isdir('checkpoint'):
            os.mkdir('checkpoint')
        torch.save(state, './checkpoint/ckpt.t7')
        best_acc = acc


for epoch in range(start_epoch, start_epoch+200):
    train(epoch)
    test(epoch)


