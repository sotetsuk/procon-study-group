import java.util.Scanner;

public class ALDS1_11_B {

    static Scanner sc = new Scanner(System.in);
    static final int N = 100;
    static int n, c;
    static int[][] Mat = new int[N][N];
    static int[] dp = new int[N];
    static int[] visited = new int[N];
    static int[] done = new int[N];

    static final int NOT_FOUND_YET = 0;
    static final int VISITED = 1;
    static final int DONE = 2;

    public static void main(String[] args) {
        read();
        for (int i = 0; i < n; i++) {
            dfs(i);
        }
        out();
    }

    static void read() {
        n = sc.nextInt();
        int u, k, v;
        for (int i = 0; i < n; i++) {
            u = sc.nextInt();
            k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                v = sc.nextInt();
                Mat[u - 1][v - 1] = 1;
            }
        }
    }

    static void out() {
        for (int i = 0; i < n; i++) {
            System.out.println(String.format("%d %d %d", i + 1, visited[i], done[i]));
        }
    }

    static void dfs(int i) {
        if (dp[i] != NOT_FOUND_YET) {
            return;
        }

        c++;
        dp[i] = VISITED;
        visited[i] = c;

        for (int j = 0; j < n; j++) {
            if (Mat[i][j] == 1) {
                dfs(j);
            }
        }

        c++;
        dp[i] = DONE;
        done[i] = c;
    }
}
