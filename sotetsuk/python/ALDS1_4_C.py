class Dict(object):

    m1 = 2 ** 24 - 1
    m2 = m1 - 1

    def __init__(self):
        self._dict = ["" for _ in range(self.m1)]

    def insert(self, k):
        i = 0

        while True:
            ix = self._h(k, i)
            if self._dict[ix] == "":
                self._dict[ix] = k
                return
            else:
                i += 1

    def find(self, k):
        i = 0

        while True:
            ix = self._h(k, i)
            if self._dict[ix] == k:
                return ix
            elif self._dict[ix] == "":
                return -1
            else:
                i += 1

    def _h(self, k, i):
        return self._h1(k) + i * self._h2(k)

    def _h1(self, k):
        return k % self.m1

    def _h2(self, k):
        return k % self.m2 + 1


def to_int(s):
    _s = s[::]

    ret = 0
    i = 1
    for e in _s:
        if e == 'A':
            ret += 1 * i
        elif e == 'C':
            ret += 2 * i
        elif e == 'G':
            ret += 3 * i
        elif e == 'T':
            ret += 4 * i
        i *= 4

    return ret


if __name__ == '__main__':
    n = int(input())

    d = Dict()

    for _ in range(n):
        cmd, val = input().split()

        if cmd == "insert":
            d.insert(to_int(val))
        else:
            ans = "yes" if d.find(to_int(val)) != -1 else "no"
            print(ans)
