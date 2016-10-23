import java.util.Scanner;

public class ALDS1_10_A {
    static Scanner sc = new Scanner(System.in);
    static int[] dp = new int[100];

    public static void main(String[] args) {
        int n = sc.nextInt();
        System.out.println(fib(n));
    }

    static int fib(int n) {
        if (n == 0 || n == 1) return 1;
        if (dp[n] > 0) return dp[n];
        dp[n] = fib(n - 1) + fib(n - 2);
        return dp[n];
    }
}