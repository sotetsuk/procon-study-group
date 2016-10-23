# -*- coding: utf_8 -*-

level = False
def debug(v):
    if level:
        print(v)

NOT_FOUND = 0
ENQUEUED = 1
FOUND = 2

def bfs(graph, status, results):
    queue = []
    queue.append(1)
    while len(queue) != 0:
        node = queue.pop(0)
        status[node] = FOUND
        d = results[node]
        for edge in graph[node]:
            if status[edge] != NOT_FOUND:
                continue
            status[edge] = ENQUEUED
            queue.append(edge)
            results[edge] = d + 1

    return results

if __name__ == "__main__":
    n = int(input())
    status = [NOT_FOUND] * (n + 1)
    results = [-1] * (n + 1)
    results[1] = 0
    g = [[0]]

    for i in range(n):
        row = [int(x) for x in input().split()]
        row.pop(0)
        row.pop(0)
        g.append(row)

    bfs(g, status, results)
    results.pop(0)

    for idx, v in enumerate(results):
        print(idx + 1, v)
        
