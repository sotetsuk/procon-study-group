import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Set;

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
        int n = in.nextInt();
        int[][] matrix = in.nextIntArray2D(n, n);
        PriorityQueue<Edge> edges = new PriorityQueue<>(n * n, new Comparator<Edge>() {
            @Override
            public int compare(Edge o1, Edge o2) {
                return o1.range - o2.range;
            }
        });
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
        Set<Integer> used = new HashSet<>();
        Edge e = edges.poll();
        used.add(e.x);
        used.add(e.y);

        int sum = e.range;
        while (used.size() < n) {
            e = null;
            List<Edge> list = new ArrayList<>(n);
            while(e == null) {
                Edge temp = edges.poll();
                boolean containX = used.contains(temp.x);
                boolean containY = used.contains(temp.y);
                if (containX && containY) {
                    continue;
                }
                if(!containX && !containY){
                    list.add(temp);
                    continue;
                }
                e = temp;
            }
            used.add(e.x);
            used.add(e.y);
            sum += e.range;
            edges.addAll(list);
        }
        System.out.println(sum);
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

class FastReader {
    private InputStream in = System.in;
    private byte[] buf = new byte[1024];
    private int charNum;
    private int charLen;
    private StringBuilder sb = new StringBuilder();

    public int read() {
        if (charLen == -1)
            throw new InputMismatchException();
        if (charNum >= charLen) {
            charNum = 0;
            try {
                charLen = in.read(buf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (charLen <= 0)
                return -1;
        }
        return buf[charNum++];
    }

    public String next() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        sb.setLength(0);
        do {
            sb.appendCodePoint(c);
            c = read();
        } while (!isWhitespace(c));
        return sb.toString();
    }

    public char[] nextCharArray() {
        return next().toCharArray();
    }

    public int nextInt() {
        return (int) nextLong();
    }

    public int[] nextIntArray(int n) {
        int[] array = new int[n];
        for (int i = 0; i < n; i++)
            array[i] = nextInt();
        return array;
    }

    public List<Integer> nextIntList(int n) {
        Integer[] array = new Integer[n];
        for (int i = 0; i < n; i++)
            array[i] = nextInt();
        return Arrays.asList(array);
    }

    public int[][] nextIntArray2D(int n, int m) {
        int[][] array = new int[n][m];
        for (int i = 0; i < n; i++)
            array[i] = nextIntArray(m);
        return array;
    }

    public List<int[]> nextIntsList(int n, int m) {
        List<int[]> list = new ArrayList<int[]>(n);
        for (int i = 0; i < n; i++)
            list.add(nextIntArray(m));
        return list;
    }

    public long nextLong() {
        int c = read();
        while (isWhitespace(c)) {
            c = read();
        }
        int sgn = 1;
        if (c == '-') {
            sgn = -1;
            c = read();
        }
        long res = 0;
        do {
            if (c < '0' || c > '9')
                throw new InputMismatchException();
            res *= 10;
            res += c - '0';
            c = read();
        } while (!isWhitespace(c));
        return res * sgn;
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public double[] nextDoubleArray(int n) {
        double[] array = new double[n];
        for (int i = 0; i < n; i++)
            array[i] = nextDouble();
        return array;
    }

    public boolean isWhitespace(int c) {
        return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
    }
}
