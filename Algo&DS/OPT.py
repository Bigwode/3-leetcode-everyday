# coding:utf-8
# Problem: Select some numbers no adjacent in an array to make max sum
import numpy as np
arr = [1, 2, 4, 1, 7, 8, 3]


# recursion but make overlap sub problem.
def opt(i):
    if i == 0:
        return arr[0]
    elif i == 1:
        return max(arr[0], arr[1])
    return max(opt(i-1), opt(i-2)+arr[i])


def opt2():
    opt = np.zeros(len(arr))
    opt[0] = arr[0]
    opt[1] = max(arr[0], arr[1])
    for i in range(2, len(arr)):
        opt[i] = max(opt[i-1], opt[i-2] + arr[i])
    return opt[-1]


print(opt2())
