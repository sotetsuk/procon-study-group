CONST_INF = 1e+9 + 1


def merge(A, left, mid, right, cnt):
    n1 = mid - left
    n2 = right - mid
    L = range(n1 + 1)
    R = range(n2 + 1)
    for i in range(n1):
        L[i] = A[left + i]
    for i in range(n2):
        R[i] = A[mid + i]
    L[n1] = CONST_INF
    R[n2] = CONST_INF
    i = 0
    j = 0

    for k in range(left, right):
        if L[i] <= R[j]:
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1
        cnt += 1
    return cnt


def merge_sort(A, left, right, cnt):
    if left + 1 < right:
        mid = (left + right) / 2
        (A, cnt) = merge_sort(A, left, mid, cnt)
        (A, cnt) = merge_sort(A, mid, right, cnt)
        cnt = merge(A, left, mid, right, cnt)
    return A, cnt

if __name__ == '__main__':
    n = input()
    s = map(int, raw_input().split())
    cnt = 0
    ans, cnt = merge_sort(s, 0, n, cnt)

    print ' '.join(map(str, ans))
    print(cnt)









