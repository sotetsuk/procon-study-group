import java.util.Scanner;

public class ALDS1_10_B {

    static Scanner sc = new Scanner(System.in);
    static int n;
    static int[] p = new int[105];
    static int[][] dp = new int[105][105];

    public static void main(String[] args) {
        read();
        System.out.println(solve());
    }

    public static void read() {
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            p[i - 1] = sc.nextInt();
            p[i] = sc.nextInt();
        }
    }

    public static int solve() {
        for (int i = 0; i < 105; i++) {
            for (int j = 0; j < 105; j++) {
                dp[i][j] = 1 << 31 - 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            dp[i][i] = 0;
        }

        for (int l = 2; l <= n; l++) {
            for (int i = 1; i <= n - l + 1; i++) {
                int j = i + l - 1;
                for (int k = i; k <= j; k++) {
                    dp[i][j] = Math.min(dp[i][j], dp[i][k] + dp[k + 1][j] + (p[i - 1] * p[k] * p[j]));
                }
            }
        }

        return dp[1][n];
    }
}
