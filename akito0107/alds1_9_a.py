# -*- coding: utf_8 -*-

def complete_bin_tree(A, i):
    key = i - 1
    left = (i * 2) - 1 if (i * 2) - 1 < len(A) else -1
    right = i * 2 if i * 2 < len(A) else -1
    parent = int(i/2) - 1 if int(i/2) > 0 else -1

    print("node " + str(i) + ": key = " + str(A[key]) + ", ", end = "")
    if parent >= 0:
        print("parent key = " + str(A[parent]) + ", ", end = "")
    if left >= 0:
        print("left key = " + str(A[left]) + ", ", end = "")
    if right >= 0:
        print("right key = " + str(A[right]) + ", ", end = "")

    print()


if __name__ == "__main__":
    H = int(input())
    a = [int(x) for x in input().split()]

    for i in range(1, H + 1):
        complete_bin_tree(a, i)

