import util.FastReader;

import java.util.HashSet;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_4_C'>Dictionary</a>
 */
public class ALDS1_4_C {
    private static FastReader in = new FastReader();

    public static void main(String[] args) throws Exception {
        ALDS1_4_C ALDS14C = new ALDS1_4_C();
        ALDS14C.run();
    }

    private void run() {
        int[] dictionary = new int[16777216];
        int n = in.nextInt();
        for (int i = 0; i < n; i++) {
            String order = in.next();
            String word = in.next();
            int index = toInt(word);
            switch (order) {
                case "insert":
                    dictionary[index]++;
                    break;
                case "find":
                    System.out.println(dictionary[index] > 0 ? "yes" : "no");
                    break;
            }
        }
    }

    private int toInt(String word) {
        int i = 0;
        int mul = 1;
        for (char charactor : word.toCharArray()) {
            switch (charactor) {
                case 'A':
                    i += mul;
                    break;
                case 'C':
                    i += mul * 2;
                    break;
                case 'T':
                    i += mul * 3;
                    break;
                case 'G':
                    i += mul * 4;
                    break;
            }
            mul *= 5;
        }
        return i;
    }
}
