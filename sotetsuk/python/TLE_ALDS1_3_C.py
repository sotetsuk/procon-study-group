class DoublyLinkedList(object):

    def __init__(self):
        nil_node = Node(-1, -1, -1)
        self.nil_node = nil_node
        self.nil_node.prev = nil_node
        self.nil_node.next = nil_node

    def insert(self, x):
        inserted = Node(x, self.nil_node, self.nil_node.next)
        self.nil_node.next.prev = inserted
        self.nil_node.next = inserted

    def _delete_node(self, node):
        node.prev.next, node.next.prev = node.next, node.prev

    def _search_node(self, val):
        cur = self.nil_node.next
        while cur.val != self.nil_node.val:
            if cur.val == val:
                return cur
            cur = cur.next

    def delete(self, val):
        node = self._search_node(val)
        if node is not None:
            self._delete_node(node)

    def delete_first(self):
        self._delete_node(self.nil_node.next)

    def delete_last(self):
        self._delete_node(self.nil_node.prev)

    def show(self):
        ans = ""
        cur = self.nil_node.next

        while cur.val != self.nil_node.val:
            ans += "{} ".format(cur.val)
            cur = cur.next

        print ans.strip()


class Node(object):

    def __init__(self, val, prev, _next):
        self.val = val
        self.prev = prev
        self.next = _next

    def __repr__(self):
        return "val: {}, prev: {}, next: {}\n".format(self.val, self.prev.val, self.next.val)

if __name__ == '__main__':
    n = int(raw_input())
    commands = [raw_input().split() for _ in range(n)]

    d = DoublyLinkedList()

    for command in commands:
        if command[0] == "insert":
            d.insert(int(command[1]))
        elif command[0] == "delete":
            d.delete(int(command[1]))
        elif command[0] == "deleteFirst":
            d.delete_first()
        elif command[0] == "deleteLast":
            d.delete_last()

    d.show()
