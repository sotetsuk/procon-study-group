import java.util.Scanner;

public class ALDSl_5_A {

    private static Scanner sc = new Scanner(System.in);
    private static int n, q;
    private static int[] A = new int[20];
    private static int[] M = new int[200];

    public static void main(String[] args) {
        input();

        for (int i = 0; i < q; i++) {
            int m = M[i];
            String ans = solve(m, 0, 0) ? "yes" : "no";
            System.out.println(ans);
        }
    }

    private static boolean solve(int m, int depth, int s) {
        if (depth == n) {
            return m == s;
        }

        return solve(m, depth + 1, s + A[depth]) || solve(m, depth + 1, s);
    }

    private static void input() {
        n = sc.nextInt();
            for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
        q = sc.nextInt();
            for (int i = 0; i < q; i++) {
            M[i] = sc.nextInt();
        }
    }
}
