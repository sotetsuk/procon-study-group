import util.FastReader;

import java.util.Arrays;
import java.util.stream.Collectors;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_7_D'>木の復元</a>
 */
public class ALDS1_7_D {
    private static FastReader in = new FastReader();

    public static void main(String[] args) throws Exception {
        ALDS1_7_D main = new ALDS1_7_D();
        main.run();
    }

    private int[] preOrder, inOrder, postOrder;
    private int pos = 0, count = 0;

    private void run() {
        int n = in.nextInt();
        preOrder = in.nextIntArray(n);
        inOrder = in.nextIntArray(n);
        postOrder = new int[n];

        restore(0, n);
        System.out.println(Arrays.stream(postOrder)
                .mapToObj(String::valueOf)
                .collect(Collectors.joining(" ")));
    }

    private void restore(int left, int right) {
        if (left >= right) return;
        int root = preOrder[pos++];
        int middle = 0;
        while (inOrder[middle] != root) {
            middle++;
        }
        restore(left, middle);
        restore(middle + 1, right);
        postOrder[count++] = root;
    }
}
