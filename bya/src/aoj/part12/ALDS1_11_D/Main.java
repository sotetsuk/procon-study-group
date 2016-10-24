package aoj.part12.ALDS1_11_D;

import java.util.Scanner;

public class Main {

    public static class QuickUnionUF {

        private int[] id;
        private int[] sz;

        public QuickUnionUF(int N) {
            id = new int[N];
            sz = new int[N];
            for (int i = 0; i < N; i++) {
                id[i] = i;
                sz[i] = 0;
            }
        }

        public void union(int p, int q) {
            int i = root(p);
            int j = root(q);

            if (i == j) return;
            if (sz[i] < sz[j]){
                id[i] = j;
                sz[j] += sz[i];
            }
            else {
                id[j] = i;
                sz[i] += sz[j];
            }
        }

        private int root(int i) {
            while (i != id[i])
                i = id[i];
            return i;
        }

        public boolean connected(int p, int q) {
            return root(p) == root(q);
        }
    }


    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        int N = scanner.nextInt();
        int M = scanner.nextInt();
        QuickUnionUF uf = new QuickUnionUF(N);

        // input
        for (int i = 0; i < M; i++) {
            int p = scanner.nextInt();
            int q = scanner.nextInt();
            uf.union(p, q);
        }

        // Query
        int Q = scanner.nextInt();
        for (int i = 0; i < Q; i++) {
            int p = scanner.nextInt();
            int q = scanner.nextInt();
            if (uf.connected(p,q))
                System.out.print("yes\n");
            else
                System.out.print("no\n");
        }
    }
}
