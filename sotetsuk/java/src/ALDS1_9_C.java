import java.util.Scanner;

public class ALDS1_9_C {
    static Scanner sc = new Scanner(System.in);
    static int H = 0;
    static int[] A = new int[2000005];

    public static void main(String[] args) {
        int k;
        while(true) {
            String cmd = sc.next();
            if (cmd.equals("insert")) {
                k = sc.nextInt();
                insert(k);
            } else if (cmd.equals("extract")) {
                System.out.println(extract());
            } else if (cmd.equals("end")) {
                return;
            }
        }
    }

    public static void insert(int k) {
        H++;
        A[H] = k;
        int i = H;
        while(i > 1 && A[i/2] < A[i]) {
            int tmp = A[i/2];
            A[i/2] = A[i];
            A[i] = tmp;

            i = i / 2;
        }
    }

    public static int extract() {
        if (H < 1) return -1;

        int ret = A[1];
        A[1] = A[H];
        H--;
        maxHeapify(1);

        return ret;
    }

    public static void maxHeapify(int i) {
        int l = i * 2;
        int r = i * 2 + 1;

        int largest;
        if (l <= H && A[l] > A[i]) {
            largest = l;
        } else {
            largest = i;
        }
        if (r <= H && A[r] > A[largest]) {
            largest = r;
        }

        if (largest != i) {
            int tmp = A[i];
            A[i] = A[largest];
            A[largest] = tmp;

            maxHeapify(largest);
        }
    }
}