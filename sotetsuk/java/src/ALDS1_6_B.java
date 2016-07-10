import java.util.Scanner;

public class ALDS1_6_B {

    static Scanner sc = new Scanner(System.in);
    static int n, x;
    static Card[] A, B;

    public static void main(String[] args) {
        read();
        quickSort(A, 0, n - 1);
        mergeSort(B, 0, n);

        boolean stable = same(A, B);
        String strStable = stable ? "Stable" : "Not stable";
        System.out.println(strStable);

        for (int i = 0; i < n; i++) {
            System.out.println(A[i]);
        }
    }

    static boolean same(Card[] A, Card[] B) {
        for (int i = 0; i < n; i++) {
            if (A[i].p != B[i].p) {
                return false;
            }
        }
        return true;
    }

    static void merge(Card[] A, int l, int m, int r) {
        int n1 = m - l, n2 = r - m;
        Card[] L = new Card[n1 + 1];
        Card[] R = new Card[n2 + 1];

        for (int i = 0; i < n1; i++) {
            L[i] = A[l + i];
        }

        for (int i = 0; i < n2; i++) {
            R[i] = A[m + i];
        }

        L[n1] = new Card(' ', 1 << 31 - 1);
        R[n2] = new Card(' ', 1 << 31 - 1);

        int i = 0, j = 0;
        for (int k = l; k < r; k++) {
            if (L[i].n <= R[j].n) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
        }
    }

    static void mergeSort(Card[] A, int l, int r) {
        if (l + 1 < r) {
            int m = (r + l) / 2;
            mergeSort(A, l, m);
            mergeSort(A, m, r);
            merge(A, l, m, r);
        }
    }

    static void quickSort(Card[] A, int p, int r) {
        if(p < r) {
            int q = partition(A, p, r);
            quickSort(A, p, q - 1);
            quickSort(A, q + 1, r);
        }
    }

    static int partition(Card[] A, int p, int r) {
        x = A[r].n;
        int i = p - 1;
        for (int j = p; j < r; j++) {
            if (A[j].n <= x) {
                i++;
                Card tmp = A[j]; A[j] = A[i]; A[i] = tmp;
            }
        }
        Card tmp = A[i + 1]; A[i + 1] = A[r]; A[r] = tmp;

        return i + 1;
    }

    static void read() {
        n = sc.nextInt();
        A = new Card[n];
        B = new Card[n];
        for (int i = 0; i < n; i++) {
            char p = sc.next().toCharArray()[0];
            int n = sc.nextInt();
            A[i] = new Card(p, n);
            B[i] = new Card(p, n);
        }
    }
}

class Card {
    char p;
    int n;

    public Card(char p, int n) {
        this.p = p;
        this.n = n;
    }

    @Override
    public String toString() {
        return String.format("%c %d", this.p, this.n);
    }
}
