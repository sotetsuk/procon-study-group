import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class ALDS1_5_D {

    static FastScanner sc = new FastScanner();
    static int n;
    static int[] A;

    public static void main(String[] args) {
        read();
        System.out.println(mergeSort(0, n));
    }

    static void read() {
        n = Integer.parseInt(sc.next());
        A = new int[n];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(sc.next());
        }
    }

    static long merge(int l, int m, int r) {
        long ret = 0;

        int n1 = m - l, n2 = r - m;
        int[] L = new int[n1 + 1];
        int[] R = new int[n2 + 1];

        for (int i = 0; i < n1; i++) {
            L[i] = A[l + i];
        }

        for (int i = 0; i < n2; i++) {
            R[i] = A[m + i];
        }

        L[n1] = 1 << 31 - 1;
        R[n2] = 1 << 31 - 1;

        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            } else {
                ret += m - l - i;
                A[k] = R[j];
                j++;
            }
        }

        return ret;
    }

    static long mergeSort(int l, int r) {
        long ret = 0;
        if (l + 1 < r) {
            int m = (r + l) / 2;
            ret += mergeSort(l, m);
            ret += mergeSort(m, r);
            ret += merge(l, m, r);
        }

        return ret;
    }


    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;

        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            } else {
                ptr = 0;
                try {
                    buflen = in.read(buffer);
                } catch (IOException e) {
                    e.printStackTrace();
                }
                if (buflen <= 0) {
                    return false;
                }
            }
            return true;
        }

        private int readByte() {
            if (hasNextByte()) return buffer[ptr++];
            else return -1;
        }

        private static boolean isPrintableChar(int c) {
            return 33 <= c && c <= 126;
        }

        private void skipUnprintable() {
            while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
        }

        public boolean hasNext() {
            skipUnprintable();
            return hasNextByte();
        }

        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while (isPrintableChar(b)) {
                sb.appendCodePoint(b);
                b = readByte();
            }
            return sb.toString();
        }

        public long nextLong() {
            if (!hasNext()) throw new NoSuchElementException();
            long n = 0;
            boolean minus = false;
            int b = readByte();
            if (b == '-') {
                minus = true;
                b = readByte();
            }
            if (b < '0' || '9' < b) {
                throw new NumberFormatException();
            }
            while (true) {
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                } else if (b == -1 || !isPrintableChar(b)) {
                    return minus ? -n : n;
                } else {
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
    }
}
