import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int a[];
    static int count = 0;

    public static void main(String[] args) {
        read();
        solve();
        output();
    }

    public static void read() {
        n = sc.nextInt();
        a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
    }

    public static void solve() {
        boolean flag= true;
        while(flag) {
        flag = false;
            for (int i = n-1; i > 0; i--) {
                if (a[i - 1] > a[i]) {
                    int tmp = a[i];
                    a[i] = a[i - 1];
                    a[i - 1] = tmp;
                    flag = true;
                    count++;
                }
            }
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
        System.out.println(count);
    }
}

