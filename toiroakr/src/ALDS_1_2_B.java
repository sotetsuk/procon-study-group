import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.stream.Collectors;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_2_B'>選択ソート</a>
 */
public class ALDS_1_2_B {
	static FastReader in = new FastReader();

	public static void main(String[] args) throws Exception {
		ALDS_1_2_B main = new ALDS_1_2_B();
		main.run();
	}

	void run() {
		int n = in.nextInt();
		int[] num = in.nextIntArray(n);

		int count = 0;
		for (int i = 0; i < n - 1; i++) {
			int minIndex = i;
			for (int j = i; j < n; j++) {
				if (num[j] < num[minIndex]) {
					minIndex = j;
				}
			}
			if (i != minIndex) {
				count++;
				int temp = num[i];
				num[i] = num[minIndex];
				num[minIndex] = temp;
			}
		}
		System.out.println(Arrays.stream(num).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
		System.out.println(count);
	}
}
