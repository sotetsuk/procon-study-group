import java.util.Scanner;

public class ALDS1_9_A {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int[] H = new int[300];
    public static final int NULL = 2 << 31 - 1;

    public static void main(String[] args) {
        read();
        solve();
    }

    public static void read() {
        n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            H[i + 1] = sc.nextInt();
        }
    }

    public static void solve() {
        for (int i = 1; i <= n; i++) {
            int key, leftKey, rightKey, parentKey;
            key = getKey(i);
            leftKey = getLeftKey(i);
            rightKey = getRightKey(i);
            parentKey = getParentKey(i);

            String s;
            s = String.format("node %d: key = %d, ", i, key);
            if (parentKey != NULL) {
                s += String.format("parent key = %d, ", parentKey);
            }
            if (leftKey != NULL) {
                s += String.format("left key = %d, ", leftKey);
            }
            if (rightKey != NULL) {
                s += String.format("right key = %d, ", rightKey);
            }
            System.out.println(s);
        }
    }

    public static int getKey(int ix) {
        if (ix > n) {
            return NULL;
        }
        return H[ix];
    }

    public static int getLeftKey(int ix) {
        int leftIx = ix * 2;
        return getKey(leftIx);
    }

    public static int getRightKey(int ix) {
        int rightIx = ix * 2 + 1;
        return getKey(rightIx);
    }

    public static int getParentKey(int ix) {
        if (ix == 1) {
            return NULL;
        }

        int parentIx = ix / 2;
        return getKey(parentIx);
    }
}
