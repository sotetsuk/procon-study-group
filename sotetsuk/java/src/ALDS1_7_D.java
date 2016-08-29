import java.util.ArrayList;
import java.util.Scanner;

public class ALDS1_7_D {
    static Scanner sc = new Scanner(System.in);
    static int n, pos;
    static ArrayList<Integer> preorder = new ArrayList<Integer>();
    static ArrayList<Integer> inorder = new ArrayList<Integer>();

    public static BinaryTree reconstruction(int l, int r) {
        if (l >= r) {
            return new BinaryTree();
        }

        int node = preorder.get(pos++);
        int i = inorder.indexOf(node);

        BinaryTree left = reconstruction(l, i);
        BinaryTree right = reconstruction(i + 1, r);

        return new BinaryTree(node, left, right);
    }

    public static void read() {
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            preorder.add(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            inorder.add(sc.nextInt());
        }
    }

    public static void main(String[] args) {
        read();
        pos = 0;
        BinaryTree bt = reconstruction(0, preorder.size());
        System.out.println(bt);
    }

    public static class BinaryTree {
        boolean isEmpty;
        int node;
        BinaryTree left;
        BinaryTree right;

        public BinaryTree(int node, BinaryTree left, BinaryTree right) {
            this.isEmpty = false;
            this.node = node;
            this.left = left;
            this.right = right;
        }

        public BinaryTree() {
            this.isEmpty = true;
        }

        public String toString() {
            if (this.isEmpty) return "";
            String l = this.left.toString() + " ";
            String r = this.right.toString() + " ";

            if (l.trim().equals("")) {
                l = "";
            }
            if (r.trim().equals("")) {
                r = "";
            }

            return l + r + this.node;
        }
    }
}
