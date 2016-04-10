#coding: utf-8;
from __future__ import division, print_function, unicode_literals
from future_builtins import *

N = int(raw_input())
V = []

min_v, max_diff = (1 << 32), -(1 << 32)
for i in xrange(N):
    v = int(raw_input())
    diff = v - min_v
    max_diff = diff if diff > max_diff else max_diff
    min_v = v if v < min_v else min_v

print(max_diff)
