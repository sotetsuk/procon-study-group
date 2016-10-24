import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class ALDS1_11_D implements Runnable {

    static Scanner sc = new Scanner(System.in);
    static final int N = 100005;
    static final int UNVISITED = -1;
    static int n, m, q;
    static ArrayList<ArrayList<Integer>> G;
    static int[] c = new int[N];

    public static void main(String[] args) {
        new Thread(null, new ALDS1_11_D(), "", 16 * 1024 * 1024).start();
    }

    @Override
    public void run() {
        read();
        for (int i = 0; i < n; i++) {
            dfs(i, i);
        }
        out();

    }

    static void init(int n) {
        G = new ArrayList<ArrayList<Integer>>(n);
        for (int i = 0; i < n; i++) {
            G.add(new ArrayList<Integer>());
            c[i] = UNVISITED;
        }
    }

    static void read() {
        n = sc.nextInt();
        m = sc.nextInt();

        init(n);

        int u, v;
        for (int i = 0; i < m; i++) {
            u = sc.nextInt();
            v = sc.nextInt();

            G.get(u).add(v);
            G.get(v).add(u);
        }

        q = sc.nextInt();
    }

    static void dfs(int v, int cls) {
        if (c[v] != UNVISITED) {
            return;
        }

        c[v] = cls;
        for (int i = 0; i < G.get(v).size(); i++) {
            dfs(G.get(v).get(i), cls);
        }
    }

    static void out() {
        int u, v;
        for (int i = 0; i < q; i++) {
            u = sc.nextInt();
            v = sc.nextInt();

            if (c[u] == c[v]) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }
        }
    }
}
