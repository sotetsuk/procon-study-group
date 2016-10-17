# -*- coding: utf_8 -*-

n = int(input()) + 1
arr = [-1] * n

arr[0] = 1
arr[1] = 1

for i in range(2, len(arr)):
    arr[i] = arr[i - 1] + arr[i - 2]

print(arr[n - 1])

