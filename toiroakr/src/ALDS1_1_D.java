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
		int ans = Integer.MIN_VALUE;
		int min = Integer.MAX_VALUE;
		for (int num : nums) {
			ans = Math.max(ans, num - min);
			min = Math.min(min, num);
		}
		System.out.println(ans);
	}
}
