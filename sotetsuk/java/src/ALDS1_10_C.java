import java.util.Scanner;

public class ALDS1_10_C {

    static Scanner sc = new Scanner(System.in);
    static int[][] dp = new int[1005][1005];
    static String x, y;

    public static void main(String[] args) {
        int N = sc.nextInt();
        for (int i = 0; i < N; i++) {
            read();
            clear();
            System.out.println(lcs(0, 0));
        }
    }

    public static void read() {
        x = sc.next();
        y = sc.next();
    }

    public static int lcs(int i, int j) {
        if (dp[i][j] >= 0) {
            return dp[i][j];
        } else if (x.length() == i || y.length() == j) {
            return dp[i][j] = 0;
        } else if (x.charAt(i) == y.charAt(j)) {
            return dp[i][j] = lcs(i + 1, j + 1) + 1;
        } else {
            return dp[i][j] = Math.max(lcs(i + 1, j), lcs(i, j + 1));
        }
    }

    public static void clear() {
        for (int i = 0; i < 1005; i++) {
            for (int j = 0; j < 1005; j++) {
                dp[i][j] = -1;
            }
        }
    }
}
