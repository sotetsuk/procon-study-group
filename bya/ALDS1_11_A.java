package aoj;

import java.util.Scanner;

public class ALDS1_11_A {
    public static final int N = 100;

    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] m = new int[N][N];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                m[i][j] = 0;
            }
        }

        int u, k, v;
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt();
                m[u-1][v-1] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != 0)
                    System.out.print(" ");
                System.out.print(m[i][j]);
            }
            System.out.println();
        }
    }
}
