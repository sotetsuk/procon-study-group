# -*- coding: utf_8 -*-
level = False
def debug(v):
    if level:
        print(v)

n = int(input())
g = []

for i in range(n):
    v = input().split()
    g.append([int(x) for x in v]) 

debug(g)

def prim(n):
    visited = [False] * n
    d = [0] + [2001] * (n - 1)
    p = [-1] * n

    while True:
        mincost = 2001

        for i in range(n):
            if (not visited[i]) and (d[i] < mincost):
                mincost = d[i]
                u = i
        if mincost == 2001:
            break
        visited[u] = True

        for v in range(n):
            if (not visited[v]) and (g[u][v] != -1):
                if g[u][v] < d[v]:
                    d[v] = g[u][v]
                    p[v] = u

    print(sum(d))

prim(n)

