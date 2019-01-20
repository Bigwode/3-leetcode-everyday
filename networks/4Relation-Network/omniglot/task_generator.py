# coding:utf-8
import torchvision
import torchvision.datasets as dset
import torchvision.transforms as transforms
import torch
from torch.utils.data import DataLoader,Dataset
import random
import os
from PIL import Image
import matplotlib.pyplot as plt
import numpy as np
from torch.utils.data.sampler import Sampler


def imshow(img):
    npimg = img.numpy()
    plt.axis("off")
    plt.imshow(np.transpose(npimg,(1,2,0)))
    plt.show()


class Rotate(object):
    def __init__(self, angle):
        self.angle = angle

    def __call__(self, x, mode="reflect"):
        x = x.rotate(self.angle)
        return x


def omniglot_character_folders():
    """
    character_folders:a list contains 1623 path_to_images;
    :return: split it into 1200 as meta-train and 423 as meta-test
    """
    data_folder = '../datas/omniglot_resized/'

    character_folders = [os.path.join(data_folder, family, character) \
                for family in os.listdir(data_folder) \
                if os.path.isdir(os.path.join(data_folder, family)) \
                for character in os.listdir(os.path.join(data_folder, family))]
    random.seed(1)
    random.shuffle(character_folders)

    num_train = 1200
    metatrain_character_folders = character_folders[:num_train]
    metaval_character_folders = character_folders[num_train:]

    return metatrain_character_folders,metaval_character_folders


class OmniglotTask(object):
    """
    This class is for task generation for both meta training and meta testing.
    For meta training, we use all 20 samples without valid set (empty here).
    For meta testing, we use 1 or 5 shot samples for training, while using the same number of samples for validation.
    If set num_samples = 20 and chracter_folders = metatrain_character_folders, we generate tasks for meta training
    If set num_samples = 1 or 5 and chracter_folders = metatest_chracter_folders, we generate tasks for meta testing
    """

    def __init__(self, character_folders, num_classes, train_num, test_num):
        """
        :param character_folders : metatrain_character_folders
        :param num_classes: 5
        :param train_num: 1
        :param test_num: 19
        task:{  character_folder : [1200 path_to_images_classes],
                test_labels      : [19*5(0-1)],
                test_roots       : [19*5 path_to_images],
                train_labels     : [0,1,2,3,4],
                train_roots      : [5 path_to_images] }
        """
        self.character_folders = character_folders
        self.num_classes = num_classes
        self.train_num = train_num
        self.test_num = test_num

        class_folders = random.sample(self.character_folders, self.num_classes)  # 随机从1200中挑选出5个类
        labels = np.array(range(len(class_folders)))
        labels = dict(zip(class_folders, labels))  # 每个类别对应标签
        samples = dict()

        self.train_roots = []
        self.test_roots = []
        for c in class_folders:

            temp = [os.path.join(c, x) for x in os.listdir(c)]  # 找到每一个类别的图片路径
            samples[c] = random.sample(temp, len(temp))

            self.train_roots += samples[c][:train_num]  # 1个作为train
            self.test_roots += samples[c][train_num:train_num+test_num]  # 19个作为test

        self.train_labels = [labels[self.get_class(x)] for x in self.train_roots]
        self.test_labels = [labels[self.get_class(x)] for x in self.test_roots]

    def get_class(self, sample):
        return os.path.join(*sample.split('/')[:-1])


class FewShotDataset(Dataset):

    def __init__(self, task, split='train', transform=None, target_transform=None):
        self.transform = transform # Torch operations on the input image
        self.target_transform = target_transform
        self.task = task
        self.split = split
        self.image_roots = self.task.train_roots if self.split == 'train' else self.task.test_roots
        self.labels = self.task.train_labels if self.split == 'train' else self.task.test_labels

    def __len__(self):
        return len(self.image_roots)

    def __getitem__(self, idx):
        raise NotImplementedError("This is an abstract class. Subclass this class for your particular dataset.")


class Omniglot(FewShotDataset):

    def __init__(self, *args, **kwargs):
        super(Omniglot, self).__init__(*args, **kwargs)

    def __getitem__(self, idx):
        image_root = self.image_roots[idx]
        image = Image.open(image_root)
        image = image.convert('L')
        image = image.resize((28,28), resample=Image.LANCZOS)  # per Chelsea's implementation
        # image = np.array(image, dtype=np.float32)
        if self.transform is not None:
            image = self.transform(image)
        label = self.labels[idx]
        if self.target_transform is not None:
            label = self.target_transform(label)
        return image, label


class ClassBalancedSampler(Sampler):
    """
    Samples 'num_inst' examples each from 'num_cl' pools
        of examples of size 'num_per_class'
    """

    def __init__(self, num_per_class, num_cl, num_inst,shuffle=True):
        # super(ClassBalancedSampler, self).__init__(Sampler)
        self.num_per_class = num_per_class  # 1
        self.num_cl = num_cl  # 5
        self.num_inst = num_inst  # 1 for 'train'/ 19 for 'test'
        self.shuffle = shuffle

    def __iter__(self):
        # return a single list of indices, assuming that items will be grouped by class
        if self.shuffle:  # 'test'
            batch = [[i+j*self.num_inst for i in
                      torch.randperm(self.num_inst)[:self.num_per_class]]
                     for j in range(self.num_cl)]  # 95个数打乱顺序
        else:  # 'train'
            batch = [[i+j*self.num_inst for i in range(self.num_inst)[:self.num_per_class]]
                     for j in range(self.num_cl)]  # [[0],[1],[2],[3],[4]]
        batch = [item for sublist in batch for item in sublist]

        if self.shuffle:
            random.shuffle(batch)
        return iter(batch)

    def __len__(self):
        return 1


def get_data_loader(task, num_per_class=1, split='train', shuffle=True, rotation=0):
    """
    NOTE: batch size here is # instances PER CLASS
    :param num_per_class: 1 for 'train' / 19 for 'test'
    :param task.num_classes=5; task.train_num=1; task.test_num=19.
    :return:
    """

    normalize = transforms.Normalize(mean=[0.92206, 0.92206, 0.92206],
                                     std=[0.08426, 0.08426, 0.08426])

    dataset = Omniglot(task, split=split, transform=transforms.Compose([
                                                                        Rotate(rotation),
                                                                        transforms.ToTensor(),
                                                                        normalize]))

    if split == 'train':
        sampler = ClassBalancedSampler(num_per_class, task.num_classes,
                                       task.train_num, shuffle=shuffle)  # (1, 5, 1, )
    else:
        sampler = ClassBalancedSampler(num_per_class, task.num_classes,
                                       task.test_num, shuffle=shuffle)  # (1, 5, 19, )
    loader = DataLoader(dataset, batch_size=num_per_class*task.num_classes, sampler=sampler)

    return loader
