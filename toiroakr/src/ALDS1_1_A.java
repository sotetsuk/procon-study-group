import java.util.Arrays;
import java.util.StringJoiner;
import java.util.stream.Collectors;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?lang=jp&id=ALDS1_1_A'>挿入ソート</a>
 */
public class ALDS1_1_A {
	static FastReader in = new FastReader();

	public static void main(String[] args) throws Exception {
		ALDS1_1_A ALDS11A = new ALDS1_1_A();
		ALDS11A.run();
	}

	void run() {
		int n = in.nextInt();
		int[] nums = in.nextIntArray(n);
		for (int i = 0; i < n; i++) {
			int num = nums[i];
			int j = i - 1;
			while (j >= 0 && nums[j] > num) {
				nums[j + 1] = nums[j];
				j -= 1;
			}
			nums[j + 1] = num;

			System.out.println(Arrays.stream(nums).mapToObj(String::valueOf).collect(Collectors.joining(" ")));
		}
	}
}
