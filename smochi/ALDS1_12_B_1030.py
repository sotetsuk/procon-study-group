__author__ = '01010381'
CONST_INF = int(1e+9 + 1)

# import pprint as pp
# import pdb
from collections import deque


def dijkstra(vnum, s, m):
    dist = [CONST_INF for i in range(vnum)]
    status = ['new' for j in range(vnum)]
    # p = [-1 for k in range(vnum)]
    dist[s] = 0
    status[0] = 'checked'

    while True:
        minc = CONST_INF
        u = -1
        for i in range(vnum):
            if status[i] != 'fixed' and dist[i] < minc:
                minc = dist[i]
                u = i

        if u == -1:
            break

        status[u] = 'fixed'

        for v in range(vnum):
            if status != 'fixed' and m[u][v] != CONST_INF:
                if dist[u] + m[u][v] < dist[v]:
                    dist[v] = dist[u] + m[u][v]
                    status[v] = 'checked'

    for i in range(n):
        print str(i) + ' ' + str(dist[i] if dist[i] != CONST_INF else -1)

if __name__ == '__main__':
    n = input()
    rows = []
    for i in range(n):
        rows.append(map(int, raw_input().split()))

    adjMat = [[CONST_INF for i in range(n)] for j in range(n)]

    for j in range(n):
        r = rows[j].pop(0)
        for k in range(rows[j].pop(0)):
            # pdb.set_trace()
            adjMat[r][rows[j][2 * k]] = rows[j][2 * k + 1]

    # pp.pprint(adjMat)

    dijkstra(vnum=n, s=0, m=adjMat)
