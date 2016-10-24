package aoj.part12.ALDS1_11_A;

import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();
        int[][] mat = new int[n][n];

        int u, k, v;
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt();
                mat[u-1][v-1] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(mat[i][j]);
                if (j != n - 1)
                    System.out.print(" ");
            }
            System.out.print("\n");
        }
    }
}
