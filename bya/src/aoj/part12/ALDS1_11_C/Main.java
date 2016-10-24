package aoj.part12.ALDS1_11_C;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Main {
    private static Scanner scanner = new Scanner(System.in);
    private static final int N = 100;
    private static final int INF = -1;
    private static int[][] Mat = new int[N][N];
    private static int[] Distance = new int[N];
    private static Queue<Integer> queue = new LinkedList<>();
    private static int n;

    public static void main(String[] args){

        graph_input();

        bfs(0);

        for (int i = 0; i < n; i++) {
            System.out.print((i+1) + " " + Distance[i] + "\n");
        }
    }

    private static void bfs(int s) {
        queue.add(s);

        for (int i = 0; i < n; i++) {
            Distance[i] = INF;
        }

        Distance[s] = 0;

        int u;
        while (!queue.isEmpty()){
            u = queue.peek();
            queue.remove();

            for (int v = 0; v < n; v++) {
                if (Mat[u][v] == 0) continue;
                if (Distance[v] != INF) continue;
                queue.add(v);
                Distance[v] = Distance[u] + 1;
            }
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
