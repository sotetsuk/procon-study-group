import java.util.Scanner;

public class ALDS1_4_D {

    static private Scanner sc = new Scanner(System.in);
    static private int n, k;
    static private int[] w;

    public static void main(String[] args) {
        input();
        int p = solve();
        System.out.println(p);
    }

    private static int solve() {
        int l = 0;
        int r = 10000 * n / k + 10;

        int p;
        while (l < r) {
            p = (r + l) / 2;
            if (check(p)) {
                r = p;
            } else {
                l = p + 1;
            }
        }

        return l;
    }

    private static boolean check(int p) {
        int c = 0;
        int t = 1;
        for (int i = 0; i < n; i++) {
            if (w[i] > p) {
                return false;
            }

            if (c + w[i] <= p) {
                c += w[i];
            } else {
                t += 1;
                c = w[i];
            }
        }

        return t <= k;
    }

    private static void input() {
        n = sc.nextInt();
        k = sc.nextInt();
        w = new int[100000];

        for (int i = 0; i < n; i++) {
            w[i] = sc.nextInt();
        }
    }
}
