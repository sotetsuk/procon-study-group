class Queue(object):

    def __init__(self, l):
        self._queue = l
        self._n = len(l)
        self._head = 0
        self._tail = 0

    def pop_left(self):
        if self._head == self._n:
            self._head = 0
        ret = self._queue[self._head][::]
        self._head += 1

        return ret

    def push_right(self, x):
        if self._tail == self._n:
            self._tail = 0
        self._queue[self._tail] = x
        self._tail += 1

if __name__ == '__main__':
    n, q = [int(x) for x in raw_input().split()]
    ps_list = []
    for _ in range(n):
        raw = raw_input().split()
        ps_list.append([raw[0], int(raw[1])])

    queue = Queue(ps_list)

    n_end_process = 0
    acc_time = 0
    while n_end_process < n:
        h = queue.pop_left()
        if h[1] <= q:
            n_end_process += 1
            acc_time += h[1]
            print "{} {}".format(h[0], acc_time)
        else:
            h[1] -= q
            acc_time += q
            queue.push_right(h)
