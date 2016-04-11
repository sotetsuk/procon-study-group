#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

N = int(raw_input())
A = list(map(int, raw_input().split()))

for i in xrange(1,N):
    j, p = i-1, A[i]
    while j >= 0 and A[j] > p:
        A[j+1] = A[j]
        j -= 1
    A[j+1] = p
    print(" ".join(map(str, A)))
