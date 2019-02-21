import torch
import torch.nn as nn
from torchsummary import summary


class Semantic_Net(nn.Module):

    def __init__(self):
        super(Semantic_Net, self).__init__()
        self.features = nn.Sequential(
            nn.Conv2d(3, 64, kernel_size=3),  # 30
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),  # 15
            nn.Conv2d(64, 128, kernel_size=3),  # 13
            nn.ReLU(inplace=True),
            nn.MaxPool2d(2),  # 6
            nn.Conv2d(128, 256, kernel_size=3),  # 4
            nn.ReLU(inplace=True),
            nn.Conv2d(256, 256, kernel_size=3),  # 2
            nn.AvgPool2d(2)
        )
        self.result = nn.Sequential(
            nn.Linear(554, 5)
        )
        self.c = nn.Conv1d(5, 1, 3)

    def forward(self, img, vec):
        v = self.c(vec)
        v = v.view(v.size(0), 1*298)
        x = self.features(img)
        x = x.view(x.size(0), 256*1)
        x = torch.cat([x, v], dim=1)
        x = self.result(x)
        return x


if __name__ == 'main':
    device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
    vgg = Semantic_Net().to(device)

