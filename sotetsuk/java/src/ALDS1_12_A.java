import java.util.Scanner;

public class ALDS1_12_A {

    static Scanner sc = new Scanner(System.in);
    static int V;
    static int[][] G = new int[105][105];
    static final int INF = 1 << 31 - 1;

    public static void main(String[] args) {
        V = sc.nextInt();

        int v;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                v = sc.nextInt();
                G[i][j] = v != -1 ? v : INF;
            }
        }

        int ans = solvePrim();
        System.out.println(ans);
    }

    /*
    This function find the Minimum Spanning Tree (MST) in O(V^2).

      V: Number of vertexes.
      G: Costs between two vertexes (values of edges). If the edge does not exists, INF should be set.

    Return the total cost of the MST, T.


    EXAMPLE
    -------

    V = 5
    G =
      INF   2   3   1 INF
        2 INF INF   4 INF
        3 INF INF   1   1
        1   4   1 INF   3
      INF INF   1   3 INF

    Ans = 5
    */
    static int solvePrim() {

        int[] cost = new int[V];  // the cost for adding vertex v in G - T to T
        boolean[] used = new boolean[V];  // whether the vertex v exists in T

        for (int i = 0; i < V; i++) {
            cost[i] = INF;
            used[i] = false;
        }

        cost[0] = 0;
        int ret = 0;

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
            ret += cost[v];

            for (int u = 0; u < V; u++) {
                cost[u] = Math.min(cost[u], G[u][v]);
            }
        }

        return ret;
    }
}
