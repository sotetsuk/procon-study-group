import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_12_A'>問題</a>
 */
public class ALDS1_12_A {
    private static FastReader in = new FastReader();

    public static void main(String[] args) throws Exception {
        ALDS1_12_A main = new ALDS1_12_A();
        main.run();
    }

    private void run() {
        // 初期化
        int n = in.nextInt();
        PriorityQueue<Edge> edges = initEdges(n);

        // 最初の枝
        Set<Integer> used = new HashSet<>();
        Edge e = edges.poll();
        used.add(e.x);
        used.add(e.y);

        int ans = e.range;
        // 最小全域木の構築
        while (used.size() < n) {
            e = nextEdge(edges, used);
            used.add(e.x);
            used.add(e.y);
            ans += e.range;
        }
        System.out.println(ans);
    }

    private PriorityQueue<Edge> initEdges(int n) {
        int[][] matrix = in.nextIntArray2D(n, n);

        PriorityQueue<Edge> edges = new PriorityQueue<>(n * n, (o1, o2) -> o1.range - o2.range);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (i == j || matrix[i][j] < 0) {
                    continue;
                }
                Edge e = new Edge(i, j, matrix[i][j]);
                if (edges.contains(e)) {
                    continue;
                }
                edges.add(e);
            }
        }
        return edges;
    }

    private Edge nextEdge(PriorityQueue<Edge> edges, Set<Integer> used) {
        List<Edge> list = new ArrayList<>();
        while (true) {
            Edge temp = edges.poll();
            boolean containX = used.contains(temp.x);
            boolean containY = used.contains(temp.y);
            if (containX && containY) {
                continue;
            }
            if (!containX && !containY) {
                list.add(temp);
                continue;
            }
            edges.addAll(list);
            return temp;
        }
    }
}

class Edge {
    int x;
    int y;
    int range;

    public Edge(int x, int y, int range) {
        this.x = x;
        this.y = y;
        this.range = range;
    }

    public boolean equals(Object o) {
        if (o == null || !(o instanceof Edge)) {
            return false;
        }
        Edge e = (Edge) o;
        return e.x == this.x && e.y == this.y || e.x == this.y && e.y == this.x;
    }

    public String toString() {
        return String.format("[%s, %s, %s]", x, y, range);
    }
}
