from collections import deque

if __name__ == '__main__':
    s = input()
    d = deque()
    l = deque()

    for i, c in enumerate(s):
        if c == "\\":
            d.append(i)
        if c == "/":
            if len(d) == 0:
                continue

            j = d.pop()

            s = i - j
            while len(l) > 0:
                _j, _i, _s = l.pop()
                if j < _j:
                    s += _s
                else:
                    l.append((_j, _i, _s))
                    break

            l.append((j, i, s))

    # sum all areas
    ans = str(len(l))
    sum_area = 0
    for j, i, s in l:
        ans += " " + str(s)
        sum_area += s

    # print answer
    print(sum_area)
    print(ans)
