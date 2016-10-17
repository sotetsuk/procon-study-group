# -*- coding: utf_8 -*-

level = False
def debug(v):
    if level:
        print(v)

n = int(input())
a = []

for i in range(n):
    v = input().split()
    v.pop(0)
    v.pop(0)
    a.append([int(x) for x in v]) 

debug(a)

for i in range(0, n):
    v = a[i]
    for j in range(n):
        if (j + 1) in v:
            print(str(1), end="")
        else:
            print(str(0), end="")
        if j != n - 1:
            print(" ", end="")
    print()

