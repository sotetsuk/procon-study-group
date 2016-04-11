import java.io.IOException;
import java.util.Arrays;
import java.util.StringJoiner;

import util.FastReader;

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

			StringJoiner joiner = new StringJoiner(" ");
			Arrays.stream(nums).mapToObj(String::valueOf).forEach(joiner::add);
			System.out.println(joiner.toString());
		}
	}

	void printExit(Object msg) {
		System.out.println(msg.toString());
		System.exit(0);
	}
}
