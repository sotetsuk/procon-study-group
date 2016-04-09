import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int a[];

    public static void main(String[] args) {
        read();
        output();
        solve();
    }

    public static void read() {
        n = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
    }

    public static void solve() {
        for (int i = 1; i < n; i++) {
            int v = i;
            while (v > 0) {
                if (a[v - 1] > a[v]) {
                    int tmp = a[v];
                    a[v] = a[v - 1];
                    a[v - 1] = tmp;
                }
                v--;
            }
            output();
        }
    }

    public static void output() {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]);
            if (i + 1 < a.length) {
                System.out.print(" ");
            }
        }
        System.out.println();
    }
}

