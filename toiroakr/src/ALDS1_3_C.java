import util.FastReader;

import java.util.StringJoiner;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_3_C'>問題</a>
 */
public class ALDS1_3_C {
    private static FastReader in = new FastReader();

    public static void main(String[] args) throws Exception {
        ALDS1_3_C main = new ALDS1_3_C();
        main.run();
    }

    private void run() {
        int n = in.nextInt();
        DoublyLinkedList first = null;
        DoublyLinkedList last = null;
        for (int i = 0; i < n; i++) {
            String command = in.next();
            if (command.equals("insert")) {
                DoublyLinkedList insert = new DoublyLinkedList(in.nextInt());
                if (first == null) {
                    first = insert;
                    last = insert;
                } else {
                    insert.next = first;
                    first.prev = insert;
                    first = insert;
                }
            }
            if (command.equals("delete")) {
                int delete = in.nextInt();
                DoublyLinkedList temp = first;
                while (temp != null && temp.value != delete) {
                    temp = temp.next;
                }
                if (temp == null) {
                    continue;
                }
                if (temp.prev != null) {
                    temp.prev.next = temp.next;
                } else {
                    first = temp.next;
                }
                if (temp.next != null) {
                    temp.next.prev = temp.prev;
                } else {
                    last = temp.prev;
                }
            }
            if (command.equals("deleteFirst")) {
                if (first.next != null) {
                    first.next.prev = null;
                } else {
                    last = null;
                }
                first = first.next;
            }
            if (command.equals("deleteLast")) {
                if (last.prev != null) {
                    last.prev.next = null;
                } else {
                    first = null;
                }
                last = last.prev;
            }
        }
        System.out.println(first);
    }
}

class DoublyLinkedList {
    public DoublyLinkedList prev;
    public DoublyLinkedList next;
    public int value;

    DoublyLinkedList(int value) {
        this.value = value;
    }

    @Override
    public String toString() {
        StringJoiner joiner = new StringJoiner(" ");
        DoublyLinkedList temp = this;
        while (temp != null) {
            joiner.add(String.valueOf(temp.value));
            temp = temp.next;
        }
        return joiner.toString();
    }
}
