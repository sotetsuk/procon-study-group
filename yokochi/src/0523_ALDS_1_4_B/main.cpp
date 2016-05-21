#include <iostream>
#include <stdlib.h>

using namespace std;
int ceil(double x)
{
    return (int)(x + 0.9);
}
int binarySearch(int n, int* s, int q, int* t)
{
    int sum = 0;

    for (int i = 0; i < q; i++) {
	int mid = n / 2;
	int left = 0;
	int right = n;
	while (left != right) {
	    if (s[mid] == t[i]) {
		sum++;
		break;
	    }
	    if (s[mid] > t[i]) {
		right = mid;
		mid = (left + right) / 2;
	    }
	    if (s[mid] < t[i]) {
		left = mid;
		mid = (left + right) / 2;
	    }
	    if (left == mid || right == mid) {
		break;
	    }
	}
    }
    return sum;
}
int main()
{
    int n = 0;
    int q = 0;
    cin >> n;

    int* s = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
	scanf("%d", &s[i]);
    }
    cin >> q;
    int* t = (int*)malloc(sizeof(int) * q);
    for (int i = 0; i < q; i++) {
	scanf("%d", &t[i]);
    }
    int sum = binarySearch(n, s, q, t);
    printf("%d\n", sum);
    return 0;
}
