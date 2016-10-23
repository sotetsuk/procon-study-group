import java.util.Scanner;

public class ALDS1_9_B {
    static Scanner sc = new Scanner(System.in);
    static int n;
    static int[] H = new int[500005];

    public static void main(String[] args) {
        read();
        buildMaxHeap();
        for (int i = 1; i <= n; i++) {
            System.out.print(" " + String.valueOf(H[i]));
        }
        System.out.print("\n");
    }

    public static void read() {
        n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            H[i] = sc.nextInt();
        }
    }

    public static void maxHeapify(int i) {
        int l = i * 2;
        int r = i * 2 + 1;

        int largest;
        if (l <= n && H[l] > H[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r <= n && H[r] > H[largest]) {
            largest = r;
        }

        if (largest != i) {
            int tmp = H[i];
            H[i] = H[largest];
            H[largest] = tmp;

            maxHeapify(largest);
        }
    }

    public static void buildMaxHeap() {
        for (int i = n / 2; i >= 1; i--) {
            maxHeapify(i);
        }
    }
}
