#include <algorithm>
#include <iostream>

int minimumCountSort(int n, int* a)
{
    int sum_a = 0;
    int min = 100000;
    int B[1000], T[10001];
    bool V[1000];
    int ans = 0;
    int min_a = 10000;

    //初期化
    for (int i = 0; i < n; i++) {
	B[i] = a[i];
	V[i] = false;
	if (min_a > a[i]) {
	    min_a = a[i];
	}
    }
    std::sort(B, B + n);
    for (int i = 0; i < n; i++) {
	T[B[i]] = i;
    }
    int minSolve = sum_a + (n - 2) * min;
    int* b = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
	if (V[i]) {
	    continue;
	}
	int cur = i;
	int sum = 0;
	int min = 10000;
	int an = 0;
	while (1) {
	    V[cur] = true;
	    an++;
	    int v = a[cur];
	    min = std::min(min, v);
	    sum += a[cur];
	    cur = T[v];
	    if (V[cur]) {
		break;
	    }
	}
	ans += std::min(sum + (an - 2) * min, min + sum + (an + 1) * min_a);
    }
    return ans;
}

int main()
{
    int n = 0;
    std::cin >> n;
    int* a = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
	std::cin >> a[i];
    }
    int answer = minimumCountSort(n, a);
    std::cout << answer << std::endl;
}
