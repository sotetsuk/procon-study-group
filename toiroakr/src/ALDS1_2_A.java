import java.util.Arrays;
import java.util.stream.Collectors;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_2_A'>バブルソート</a>
 */
public class ALDS1_2_A {
	static FastReader in = new FastReader();

	public static void main(String[] args) throws Exception {
		ALDS1_2_A ALDS12A = new ALDS1_2_A();
		ALDS12A.run();
	}

	void run() {
		int n = in.nextInt();
		int[] nums = in.nextIntArray(n);
		int count = 0;
		boolean swapped = true;
		while (swapped) {
			swapped = false;
			for (int i = 0; i < n - 1; i++) {
				if (nums[i] > nums[i + 1]) {
					swapped = true;
					count++;

					int temp = nums[i];
					nums[i] = nums[i + 1];
					nums[i + 1] = temp;
				}
			}
		}
		System.out.println(Arrays.stream(nums).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
		System.out.println(count);
	}
}