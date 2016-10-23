# -*- coding: utf_8 -*-

level = False
def debug(v):
    if level:
        print(v)

NOT_FOUND = 0
ENQUEUED = 1
FOUND = 2

def bfs(graph, start, target):
    debug(graph)
    if start == target:
        return True
    
    queue = []
    status = [NOT_FOUND] * len(graph)
    queue.append(start)

    while len(queue) != 0:
        debug("----------------------------")
        node = queue.pop(0)
        status[node] = FOUND
        edges = graph[node]
        debug(queue)
        debug(status)
        debug(edges)
        for e in edges:
            if e == target:
                return True
            if status[e] == NOT_FOUND:
                status[e] = ENQUEUED
                queue.append(e)

    return False

if __name__ == "__main__":
    n, m = [int(x) for x in input().split()]

    g = [[] for i in range(n)]
    for i in range(m):
        u, e = [int(x) for x in input().split()]
        g[u].append(e)
        g[e].append(u)

    n = int(input())
    for i in range(n):
        s, d = [int(x) for x in input().split()]
        if bfs(g, s, d):
            print("yes")
        else:
            print("no")

