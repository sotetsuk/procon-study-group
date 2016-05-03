#include <iostream>
#include <stdlib.h>

using namespace std;

int head = 0;
int tail = 0;
int t = 0;

typedef struct process {
    string name;
    int time;
} process_t;

void enqueue(process_t* arr, int h)
{
    tail++;
    arr[tail] = arr[h];
}

int dequeue(process_t* arr) { return head++; }

void print_arr(string name, int time) { cout << name << " " << time << endl; }

void solve(process_t* arr, int q)
{
    if (head > tail) {
	return;
    }
    int tmp = dequeue(arr);
    if (arr[tmp].time > q) {
	arr[tmp].time = arr[tmp].time - q;
	t += q;
	enqueue(arr, tmp);
    } else {
	t += arr[tmp].time;
	print_arr(arr[tmp].name, t);
    }
    solve(arr, q);
}

int main()
{
    int N = 0;
    int q = 0;
    cin >> N;
    cin >> q;
    tail = N - 1;

    process_t* arr = (process_t*)malloc(100 * sizeof(process_t));
    for (int i = 0; i < N; i++) {
	cin >> arr[i].name >> arr[i].time;
    }
    solve(arr, q);
    return 0;
}
