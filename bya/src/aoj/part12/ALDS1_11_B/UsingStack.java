package aoj.part12.ALDS1_11_B;

import java.util.Scanner;
import java.util.Stack;

public class UsingStack {

    private static final int N = 100;
    private static Scanner scanner = new Scanner(System.in);
    private static int[][] Mat = new int[N][N];
    private static int[] Start = new int[N];
    private static int[] Finish = new int[N];
    private static int[] Next = new int[N];
    private static int[] Color = new int[N];

    private static int n;
    private static int time = 1;



    public static void main(String[] argss){

        graph_input();
        for (int i = 0; i < n; i++) {
            if (Color[i] == 0)
                dfs(i);
        }
        print_answer();
    }

    private static void print_answer() {
        for (int i = 0; i < n; i++) {
            System.out.print((i+1) + " ");
            System.out.print(Start[i] + " ");
            System.out.print(Finish[i] + "\n");
        }
    }

    private static void dfs(int u) {
        for (int i = 0; i < n; i++) {
            Next[i] = 0;
        }
        Stack<Integer> stack = new Stack<>();
        int v;

        stack.push(u);
        Start[u] = time++;
        Color[u] = 1;

        while (!stack.empty()){
            u = stack.peek();
            v = next_vertex(u);

            if (v != -1){
                if (Color[v] == 0){
                    Color[v] = 1;
                    Start[v] = time++;
                    stack.push(v);
                }
            }
            else {
                Color[u] = 2;
                stack.pop();
                Finish[u] = time++;
            }
        }
    }

    private static int next_vertex(int u) {
        for (int v = Next[u]; v < n; v++) {
            Next[u] = v + 1;
            if (Mat[u][v] == 1)
                return v;
        }
        return -1;
    }

    public static void graph_input() {

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
