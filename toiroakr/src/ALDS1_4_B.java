import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_4_B'>Binary Search</a>
 */
public class ALDS1_4_B {
    private static FastReader in = new FastReader();

    public static void main(String[] args) throws Exception {
        ALDS1_4_B main = new ALDS1_4_B();
        main.run();
    }

    private void run() {
        int n = in.nextInt();
        int[] s = in.nextIntArray(n);
        int q = in.nextInt();
        int[] t = in.nextIntArray(q);

        int count = 0;
        for (int target : t) {
            if (binarySearch(s, target)) count++;
        }
        System.out.println(count);
    }

    private boolean binarySearch(int[] array, int target) {
        int left = 0;
        int right = array.length;
        while (left < right) {
            int mid = (left + right) / 2;
            int temp = array[mid];
            if (target < temp) {
                right = mid;
                continue;
            }
            if (temp < target) {
                left = mid + 1;
                continue;
            }
            return true;
        }
        return false;
    }
}
