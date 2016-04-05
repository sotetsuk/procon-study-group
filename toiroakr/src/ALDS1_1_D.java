import java.util.List;

import util.FastReader;

public class ALDS1_1_D {
	static FastReader in = new FastReader();

	public static void main(String[] args) throws Exception {
		ALDS1_1_D main = new ALDS1_1_D();
		main.run();
	}

	void run() {
		int n = in.nextInt();
		List<Integer> nums = in.nextIntList(n);

		int[] min = new int[n];
		int[] max = new int[n];
		min[0] = nums.get(0);
		for (int i = 1; i < n; i++) {
			min[i] = Math.min(nums.get(i), min[i - 1]);
		}
		max[n - 1] = nums.get(n - 1);
		for (int i = n - 2; i >= 0; i--) {
			max[i] = Math.max(nums.get(i), max[i + 1]);
		}

		int ans = Integer.MIN_VALUE;
		for (int i = 1; i < n; i++) {
			ans = Math.max(max[i] - min[i - 1], ans);
		}

		System.out.println(ans);
	}
}
