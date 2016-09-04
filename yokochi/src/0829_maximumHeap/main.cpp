#include <iostream>
using namespace std;

int left(int i)
{
    return i * 2;
}

int right(int i)
{
    return (i * 2) + 1;
}

void maxHeapify(int* A, int i, int n)
{
    int l = left(i);
    int r = right(i);
    int largest;
    if (l <= n && A[l] > A[i]) {
	largest = l;
    } else {
	largest = i;
    }
    if (r <= n && A[r] > A[largest]) {
	largest = r;
    }
    if (largest != i) {
	int temp = A[i];
	A[i] = A[largest];
	A[largest] = temp;
	maxHeapify(A, largest, n);
    }
}
void buildMaxHeap(int* A, int n)
{
    for (int i = n / 2; i >= 1; i--) {
	maxHeapify(A, i, n);
    }
}
int main()
{
    int n;
    int* A;
    cin >> n;
    A = (int*)malloc(sizeof(n + 1));
    for (int i = 1; i <= n; i++) {
	cin >> A[i];
    }
    buildMaxHeap(A, n);
    //出力
    for (int i = 1; i <= n; i++) {
	cout << A[i]<<" ";
    }
}
