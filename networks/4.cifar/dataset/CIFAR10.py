from __future__ import print_function
from PIL import Image
import os
import os.path
import numpy as np
import sys
if sys.version_info[0] == 2:
    import cPickle as pickle
else:
    import pickle

import torch.utils.data as data


class CIFAR10(data.Dataset):

    base_folder = 'cifar-10-batches-py'
    url = "https://www.cs.toronto.edu/~kriz/cifar-10-python.tar.gz"
    filename = "cifar-10-python.tar.gz"
    tgz_md5 = 'c58f30108f718f92721af3b95e74349a'
    train_list = [
        ['data_batch_1', 'c99cafc152244af753f735de768cd75f'],
        ['data_batch_2', 'd4bba439e000b95fd0a9bffe97cbabec'],
        ['data_batch_3', '54ebc095f3ab1f0389bbae665268c751'],
        ['data_batch_4', '634d18415352ddfa80567beed471001a'],
        ['data_batch_5', '482c414d41f54cd18b22e5b47cb7c3cb'],
    ]

    test_list = [
        ['test_batch', '40351d587109b95175f43aff81a1287e'],
    ]

    def __init__(self, root,  pkl=None, train=True,
                 transform=None, target_transform=None,
                 ):
        self.root = os.path.expanduser(root)
        self.transform = transform
        self.target_transform = target_transform
        self.train = train
        self.data  = []
        self.labels= []
        self.train_split = []
        self.test_split  = []
        with open(pkl, 'rb') as df:
            self.pkl = pickle.load(df)
        self.pkl = self.pkl/self.pkl.max()

        for fentry in self.train_list:
            f = fentry[0]
            file = os.path.join(self.root, self.base_folder, f)
            fo = open(file, 'rb')
            if sys.version_info[0] == 2:
                entry = pickle.load(fo)
            else:
                entry = pickle.load(fo, encoding='latin1')
            self.data.append(entry['data'])
            if 'labels' in entry:
                self.labels += entry['labels']
            else:
                self.labels += entry['fine_labels']
            fo.close()

        self.data   = np.concatenate(self.data)  # [50000, 3072]
        self.labels = np.array(self.labels)

        self.train_split = [i for i in range(len(self.labels)) if self.labels[i] < 5]  # train_test split
        self.test_split  = [i for i in range(len(self.labels)) if self.labels[i] >= 5]

        self.train_data  = self.data[self.train_split, :]
        self.train_labels= self.labels[self.train_split]

        self.train_data = self.train_data.reshape((-1, 3, 32, 32))
        self.train_data = self.train_data.transpose((0, 2, 3, 1))  # convert to HWC

        self.test_data  = self.data[self.test_split, :]
        self.test_labels= self.labels[self.test_split]

        self.test_data = self.test_data.reshape((-1, 3, 32, 32))
        self.test_data = self.test_data.transpose((0, 2, 3, 1))  # convert to HWC

    def __getitem__(self, index):

        if self.train:
            img, target = self.train_data[index], self.train_labels[index]
        else:
            img, target = self.test_data[index], self.test_labels[index]

        img = Image.fromarray(img)

        if self.transform is not None:
            img = self.transform(img)
        if self.target_transform is not None:
            img_vec, target = self.target_transform(self.pkl, self.train, target)

        return img, img_vec, target

    def __len__(self):
        if self.train:
            return len(self.train_data)
        else:
            return len(self.test_data)

