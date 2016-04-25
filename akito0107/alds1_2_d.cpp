#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int cnt = 0;

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

void insertion_sort(int* arr, int size, int unit) {
    for (int i = unit; i < size; i++) {
        int v = arr[i];
        int j = i - unit;
        while (j >= 0 && arr[j] > v) {
            arr[j + unit] = arr[j];
            j = j - unit;
            cnt++;
        }
        arr[j + unit] = v;
    }
}

void shell_sort(int* arr, int size) {
    int g[100] = {};
    g[0] = 1;
    int c = 0;
    for (c = 1; g[c - 1] < size; c++) {
        g[c] = g[c - 1] * 3 + 1;
    }

    print_arr(g, c - 1);

    for (int i = c - 1; i >= 0; i--) {
        insertion_sort(arr, size, g[i]);
        print_arr(arr, size);
    }
    cout << cnt << endl;
}

int main() {

    int N = 0;
    cin >> N;
    int* arr = (int*)malloc(N * sizeof(int));
    int i = 0;
    while (i < N) {
        cin >> arr[i];
        i++;
    }

    shell_sort(arr, N);
    return 0;
}
