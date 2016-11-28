#include <iostream>
using namespace std;
int getParentKey(int i, int* A, int n)
{
    int parentkey = i / 2;
    return parentkey;
}
int getLeftKey(int i, int* A, int n)
{
    int leftkey = 2 * i;
    return leftkey;
}
int getRightKey(int i, int* A, int n)
{
    int rightkey = (2 * i) + 1;
    return rightkey;
}
int main()
{
    int* A;
    int n;
    cin >> n;
    A = (int*)malloc((n + 1) * sizeof(int));
    //input
    for (int i = 1; i <= n; i++) {
	cin >> A[i];
    }

    //output
    for (int i = 1; i <= n; i++) {
	cout << "node " << i << ": ";
	cout << "key = " << A[i] << ", ";
	int pk = getParentKey(i, A, n);
	if (pk >= 1) {
	    cout << "parent key = " << A[pk] << ", ";
	}
	int lk = getLeftKey(i, A, n);
	if (lk <= n) {
	    cout << "left key = " << A[lk] << ", ";
	}
	int rk = getRightKey(i, A, n);
	if (rk <= n) {
	    cout << "right key = " << A[rk] << ", ";
	}
	cout << endl;
    }
}
