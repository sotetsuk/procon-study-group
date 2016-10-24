package aoj.part12.ALDS1_11_B;

import java.util.Scanner;

public class UsingRecursive {

    private static final int N = 100;
    private static Scanner scanner = new Scanner(System.in);
    private static int[][] Mat = new int[N][N];
    private static int[] Start = new int[N];
    private static int[] Finish = new int[N];

    private static int n;
    private static int time = 1;



    public static void main(String[] argss){

        graph_input();

        for (int i = 0; i < n; i++) {
            if (Finish[i] == 0)
                dfs_recursive(i);
        }

        print_answer();
    }

    private static void dfs_recursive(int u) {

        Start[u] = time++;

        for (int v = 0; v < n; v++) {
            if (Mat[u][v] == 1 && Start[v] == 0){
                dfs_recursive(v);
            }
        }

        Finish[u] = time++;

    }

    private static void print_answer() {
        for (int i = 0; i < n; i++) {
            System.out.print((i+1) + " ");
            System.out.print(Start[i] + " ");
            System.out.print(Finish[i] + "\n");
        }
    }


    private static void graph_input() {

        n = scanner.nextInt();

        int u, k, v;
        for (int i = 0; i < n; i++) {
            u = scanner.nextInt();
            k = scanner.nextInt();
            for (int j = 0; j < k; j++) {
                v = scanner.nextInt();
                Mat[u-1][v-1] = 1;
            }
        }
    }
}
