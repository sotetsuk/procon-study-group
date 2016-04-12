import java.util.List;
import java.util.Optional;

import util.FastReader;

/**
 * @see <a href='http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_D'>最大の利益</a>
 */
public class ALDS1_1_D {
	static FastReader in = new FastReader();

	public static void main(String[] args) throws Exception {
		ALDS1_1_D main = new ALDS1_1_D();
		main.run();
	}

	void run() {
		int n = in.nextInt();
		List<Integer> nums = in.nextIntList(n);
		int ans = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		for (int num : nums) {
			ans = Math.max(ans, num - min);
			min = Math.min(min, num);
		}
		System.out.println(ans);

		run8(nums);
	}

	void run8(List<Integer> nums) {
		int[] a = nums.stream().map(i -> new int[]{i, Integer.MIN_VALUE})
				.reduce(new int[]{Integer.MIN_VALUE, Integer.MAX_VALUE},
						(ints, integer) -> new int[]{Math.max(ints[0], integer[0] - ints[1]), Math.min(ints[1], integer[0])});
		System.out.println(a[0]);
	}
}
