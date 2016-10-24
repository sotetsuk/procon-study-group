import java.util.Scanner;

public class ALDS1_11_A {

    static Scanner sc = new Scanner(System.in);


    public static void main(String[] args) {
        int n = sc.nextInt();

        int[][] Mat = new int[n][n];

        int u, k, v;
        for (int i = 0; i < n; i++) {
            u = sc.nextInt();
            k = sc.nextInt();
            for (int j = 0; j < k; j++) {
                v = sc.nextInt();
                Mat[u - 1][v - 1] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(Mat[i][j]);
                if (j != n - 1) {
                    System.out.print(" ");
                }
            }
            System.out.print("\n");
        }
    }
}
