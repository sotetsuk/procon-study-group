import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int a[];
    static int answer = -1000000000;
    static int minv;


    public static void main(String[] args) {
        read();
        solve();
        System.out.println(answer);
    }

    public static void read() {
        n = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        minv = a[0];

    }

    public static void solve() {
        for (int i = 1; i < n; i++) {
            if (a[i] - minv > answer) {
                answer = a[i] - minv;
            }
            if (minv > a[i]) {
                minv = a[i];
            }
        }
    }
}

