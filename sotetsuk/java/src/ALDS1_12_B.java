import java.util.Scanner;

public class ALDS1_12_B {

    static Scanner sc = new Scanner(System.in);
    static int V;
    static int[][] G = new int[105][105];
    static final int INF = 1 << 31 - 1;

    public static void main(String[] args) {
        V = sc.nextInt();

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                G[i][j] = INF;
            }
        }

        int u, k, v, c;
        for (int i = 0; i < V; i++) {
            u = sc.nextInt();
            k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                v = sc.nextInt();
                c = sc.nextInt();
                G[u][v] = c;
            }
        }

        int[] ans = solveDijkstra(0);
        for (int i = 0; i < V; i++) {
            System.out.println(String.format("%d %d", i, ans[i]));
        }
    }

    static int[] solveDijkstra(int start) {

        int[] cost = new int[V];
        boolean[] used = new boolean[V];

        for (int i = 0; i < V; i++) {
            cost[i] = INF;
            used[i] = false;
        }

        cost[start] = 0;

        while (true) {
            int v = -1;
            for (int u = 0; u < V; u++) {
                if (used[u]) {
                    continue;
                }
                if (v == -1 && cost[u] != INF) {
                    v = u;
                    continue;
                }
                if (v != -1 && cost[u] < cost[v]) {
                    v = u;
                }
            }

            if (v == -1) {
                break;
            }

            used[v] = true;
            for (int u = 0; u < V; u++) {
                cost[u] = Math.min(cost[u], cost[v] + G[v][u]);
            }
        }

        return cost;
    }
}
