# -*- coding: utf_8 -*-

level = False
def debug(v):
    if level:
        print(v)

n = int(input())
a = [0]

for i in range(n):
    v = input().split()
    v.pop(0)
    v.pop(0)
    a.append([int(x) for x in v]) 

debug(a)
stack = [1]
results = [[0 for i in range(2)] for j in range(n + 1)]
results[0][0] = 0
time = 0

def depth_first_search(a, stack):
    debug(a)
    debug(results)
    debug(stack)
    global time
    if len(stack) == 0:
        return

    v = stack.pop()
    if results[v][0] == 0:
        time += 1
        results[v][0] = time

    es = a[v]
    if len(es) == 0 and results[v][1] == 0:
        time += 1
        results[v][1] = time

    if len(es) != 0:
        stack.append(v)
        next_vert = es.pop(0)
        if results[next_vert][0] == 0:
            stack.append(next_vert)

    depth_first_search(a, stack)

for i in range(n):
    stack = [i + 1]
    depth_first_search(a, stack)

debug(results)

results.pop(0)

i = 1
for row in results:
    print(str(i) + " " + str(row[0]) + " " + str(row[1]))
    i += 1

