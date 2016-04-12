#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

N = int(raw_input())
A = list(map(int, raw_input().split()))

def swap(A, i, j):
    piv = A[i]
    A[i] = A[j]
    A[j] = piv
    return A

count = 0
for i in xrange(1,N):
    flg = True
    while flg:
        flg = False
        for j in reversed(xrange(1, N)):
            if A[j] < A[j-1]:
                A = swap(A, j, j-1)
                count += 1
                flg = True
print(" ".join(map(str, A)))
print(count)
