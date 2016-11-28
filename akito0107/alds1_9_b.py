# -*- coding: utf_8 -*-

def maxHeapify(A, i):
    l = 2 * i - 1
    r = 2 * i
    largest = i - 1

    if l < len(A):
        largest = largest if A[largest] > A[l] else l

    if r < len(A):
        largest = largest if A[largest] > A[r] else r

    if largest != i - 1:
        A[largest], A[i - 1] = A[i - 1], A[largest]
        maxHeapify(A, largest + 1)

if __name__ == "__main__":
    H = int(input())
    a = [int(x) for x in input().split()]

    for i in range(int(H / 2), 0, -1):
        maxHeapify(a, i)

    print(" " + " ".join(str(x) for x in a)),

