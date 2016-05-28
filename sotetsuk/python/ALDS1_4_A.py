def linear_search(l, key):
    _l = l + [key]

    i = 0
    while key != _l[i]:
        i += 1

    if i == len(_l) - 1:
        return -1

    return i


if __name__ == '__main__':
    n = input()
    s = input().split()
    q = input()
    t = input().split()

    ans = 0
    for c1 in t:
        if linear_search(s, c1) >= 0:
            ans += 1

    print(ans)