import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.Stream;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_2_C'>安定なソート</a>
 */
public class ALDS1_2_C {
	private static Scanner in = new Scanner(System.in);
	private static final String STABLE = "Stable";
	private static final String NOT_STABLE = "Not stable";

	public static void main(String[] args) throws Exception {
		ALDS1_2_C main = new ALDS1_2_C();
		main.run();
	}

	private void run() {
		int n = in.nextInt();
		String[] vals = Stream.generate(() -> in.next()).limit(n).collect(Collectors.toList()).toArray(new String[]{});

		String[] bubble = bubbleSort(vals);
		String[] selection = selectionSort(vals);
		Arrays.sort(vals, (o1, o2) -> o1.charAt(1) - o2.charAt(1));

		printResult(bubble, vals);
		printResult(selection, vals);
	}

	private void printResult(String[] sorted, String[] stable) {
		System.out.println(Arrays.stream(sorted).collect(Collectors.joining(" ")));
		System.out.println(Arrays.equals(sorted, stable) ? STABLE : NOT_STABLE);
	}

	private String[] bubbleSort(String[] vals) {
		String[] sorted = Arrays.stream(vals).collect(Collectors.toList()).toArray(new String[]{});
		for (int i = 0; i < sorted.length; i++) {
			for (int j = sorted.length - 1; j > i; j--) {
				if (sorted[j].charAt(1) < sorted[j - 1].charAt(1)) {
					swap(j, j - 1, sorted);
				}
			}
		}
		return sorted;
	}

	private String[] selectionSort(String[] vals) {
		String[] sorted = Arrays.stream(vals).collect(Collectors.toList()).toArray(new String[]{});
		for (int i = 0; i < sorted.length; i++) {
			int minj = i;
			for (int j = i; j < sorted.length; j++) {
				if (sorted[j].charAt(1) < sorted[minj].charAt(1)) {
					minj = j;
				}
			}
			swap(i, minj, sorted);
		}
		return sorted;
	}

	private void swap(int i, int j, String[] vals) {
		String temp = vals[i];
		vals[i] = vals[j];
		vals[j] = temp;
	}
}
