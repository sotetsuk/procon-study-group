import java.util.Scanner;

public class ALDS1_6_C {

    static Scanner sc = new Scanner(System.in);
    static int n, x;
    static int[] A;

    public static void main(String[] args) {
        read();
        int i = partition(A, 0, n - 1);
    }

    static int partition(int[] A, int p, int r) {
        x = A[r];
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (A[j] <= x) {
                i++;
                int tmp = A[j]; A[j] = A[i]; A[i] = tmp;
            }
        }
        int tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;

        return i + 1;
    }

    static void read() {
        n = sc.nextInt();
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = sc.nextInt();
        }
    }
}
