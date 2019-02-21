import torch
import torch.nn as nn

m = nn.Conv1d(5, 1, 3, stride=2)
input = torch.randn(8, 5, 300)
output = m(input)
print(output.shape)
