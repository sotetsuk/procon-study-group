def binary_search(key, a):
    l = 0
    r = len(a)
    ix = (r - l) // 2

    while r - l > 0:
        if key == a[ix]:
            return True

        if key < a[ix]:
            r = ix
        else:
            l = ix + 1
        ix = l + (r - l) // 2

    return False

if __name__ == '__main__':
    n = input()
    s = [int(x) for x in input().split()]
    q = input()
    t = [int(x) for x in input().split()]

    ans = 0
    for e in t:
        ans += 1 if binary_search(e, s) else 0

    print(ans)
