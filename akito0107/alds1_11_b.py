# -*- coding: utf_8 -*-

level = True
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
stack = []
results = [[0 for i in range(2)] for j in range(n)]
results[0][0] = 0
time = 0

def depth_first_search(v):
    debug(results)
    debug(v)
    global time
    time += 1

    adj = a[v - 1]
    if len(adj) == 0:
        results[v - 1][1] = time
        if len(stack) == 0:
            return
        depth_first_search(stack.pop())

    if results[v - 1][0] == 0:
        results[v - 1][0] = time

    stack.append(v)
    depth_first_search(adj.pop(0))

depth_first_search(1)
debug(results)

