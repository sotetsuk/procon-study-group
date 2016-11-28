# -*- coding: utf_8 -*-
import sys

level = False
def debug(v):
    if level:
        print(v)

class PriorityQueue:
    def __init__(self, size):
        self.queue = [-1] * size
        self.tail = 0

    def insert(self, key):
        self.queue[self.tail] = key
        self.tail += 1
        self.heapIncreaseKey()
        debug(self.queue)

    def heapIncreaseKey(self):
        h = self.tail - 1
        parent = get_parent(h)
        while parent >= 0 and self.queue[parent] < self.queue[h]:
            self.queue[parent], self.queue[h] = self.queue[h], self.queue[parent]
            h = parent
            parent = get_parent(h)

    def extract(self):
        root = self.queue[0]
        if len(self.queue) > 0:
            self.queue[0], self.queue[self.tail - 1] = self.queue[self.tail - 1], -1
        self.tail -=1
        maxHeapify(self.queue, self.tail)
        debug(self.queue)
        return root

def maxHeapify(A, size):
    for i in range(int(size / 2), 0, -1):
        maxHeapify2(A, i, size)

def maxHeapify2(A, i, size):
    l = 2 * i - 1
    r = 2 * i
    largest = i - 1

    if l < size:
        largest = largest if A[largest] > A[l] else l

    if r < size:
        largest = largest if A[largest] > A[r] else r

    if largest != i - 1:
        A[largest], A[i - 1] = A[i - 1], A[largest]
        maxHeapify2(A, largest + 1, size)


def get_parent(size):
    size += 1
    return int(size/2) - 1

if __name__ == "__main__":

    queue = PriorityQueue(2000000)

    while True:
        command = input().split()
        if len(command) == 2:
            queue.insert(int(command[1]))

        if command[0] == "extract":
            print(queue.extract())

        if command[0] == "end":
            sys.exit()

