import java.util.*;

public class ALDS1_11_C {

    static Scanner sc = new Scanner(System.in);

    static final int N = 100;
    static final int NOT_VISITED = -1;
    static int n;
    static int[][] mat = new int[N][N];
    static Queue<Integer> q = new ArrayDeque<Integer>();
    static int[] d = new int[N];

    public static void main(String[] args) {
        read();
        init();
        bfs();
        out();
    }

    static void read() {
        int u, k, v;

        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            u = sc.nextInt();
            k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                v = sc.nextInt();
                mat[u - 1][v - 1] = 1;
            }
        }
    }

    static void init() {
        for (int i = 0; i < n; i++) {
            d[i] = NOT_VISITED;
        }
        d[0] = 0;
    }

    static void bfs() {
        q.add(0);
        while (!q.isEmpty()) {
            int e = q.element(); q.remove();
            for (int i = 0; i < n; i++) {
                if (mat[e][i] == 1) {
                    if (d[i] == NOT_VISITED) {
                        d[i] = d[e] + 1;
                        q.add(i);
                    }
                }
            }
        }
    }

    static void out() {
        for (int i = 0; i < n; i++) {
            System.out.println(String.format("%d %d", i + 1, d[i]));
        }
    }
}
