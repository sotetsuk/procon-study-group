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
        int n = in.nextInt();
        HashSet<String> dictionary = new HashSet<>();
        for (int i = 0; i < n; i++) {
            String order = in.next();
            String word = in.next();
            switch (order) {
                case "insert":
                    dictionary.add(word);
                    break;
                case "find":
                    System.out.println(dictionary.contains(word) ? "yes" : "no");
            }
        }
    }
}
