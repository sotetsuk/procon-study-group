# -*- coding: utf_8 -*-

from itertools import repeat
from itertools import combinations

def rec(s, i, total, m):
    if total == m:
        return 1

    if len(s) == i or total > m:
        return 0

    return rec(s, i + 1, total, m) + rec(s, i + 1, total + s[i], m)


def makeCache(s):
    cache = {}
    for i in range(len(s)):
        comb = list(combinations(s, i))
        for c in comb:
            cache[sum(c)] = 1

    return cache

def loop(s, m):
    for i in range(len(s)):
        comb = list(combinations(s, i))
        for c in comb:
            if sum(c) == m:
                return 1

    return 0

if __name__ == "__main__":
    n = int(input())
    a = [int (x) for x in input().split()]
    q = int(input())
    m = [int (x) for x in input().split()]
    s = makeCache(a)
    for i in m:
        #print("yes") if rec(a, 0, 0, i) > 0 else print("no")
        #print("yes") if loop(a, i) > 0 else print("no")
        print("yes") if i in s else print("no")

