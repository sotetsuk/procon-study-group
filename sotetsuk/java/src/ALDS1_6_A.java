import java.io.IOException;
import java.io.InputStream;
import java.util.NoSuchElementException;

public class ALDS1_6_A {

    static final int MAX_A = 10000 + 10;
    static int n;

    public static void main(String[] args) throws IOException{
        FastScanner sc = new FastScanner();
        n = Integer.parseInt(sc.next());

        int[] A = new int[n + 10];
        for (int i = 0; i < n; i++) {
            A[i] = Integer.parseInt(sc.next());
        }

        int[] B = new int[n + 10];
        CountingSort(A, B);

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; i++){
            sb.append(i == 0 ? "" : " ");
            sb.append(B[i]);
        }
        System.out.println(sb.toString());
    }

    static void CountingSort(int[] A, int[] B) {
        int[] C = new int[MAX_A];

        for (int i = 0; i < n; i++) {
            C[A[i]]++;
        }

        for (int i = 1; i < MAX_A; i++) {
            C[i] += C[i - 1];
        }

        for (int i = n - 1; i >= 0; i--) {
            C[A[i]]--;
            B[C[A[i]]] = A[i];
        }
    }

    public static class FastScanner {
        private final InputStream in = System.in;
        private final byte[] buffer = new byte[1024];
        private int ptr = 0;
        private int buflen = 0;
        private boolean hasNextByte() {
            if (ptr < buflen) {
                return true;
            }else{
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
        private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
        private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
        private void skipUnprintable() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;}
        public boolean hasNext() { skipUnprintable(); return hasNextByte();}
        public String next() {
            if (!hasNext()) throw new NoSuchElementException();
            StringBuilder sb = new StringBuilder();
            int b = readByte();
            while(isPrintableChar(b)) {
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
            while(true){
                if ('0' <= b && b <= '9') {
                    n *= 10;
                    n += b - '0';
                }else if(b == -1 || !isPrintableChar(b)){
                    return minus ? -n : n;
                }else{
                    throw new NumberFormatException();
                }
                b = readByte();
            }
        }
    }
}
