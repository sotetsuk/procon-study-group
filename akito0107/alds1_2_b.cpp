#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void print_arr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << " ";
        }
    }
    cout << "\n";
}

int selection_sort(int* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int minj = i;
        for (int j = i; j < size; j++) {
            if (arr[j] < arr[minj]) {
                minj = j;
            }
        }
        if (i == minj) continue;

        ++count;
        int tmp = arr[i];
        arr[i] = arr[minj];
        arr[minj] = tmp;
    }
    print_arr(arr, size);

    return count;
}

int main() {

    int N = 0;
    cin >> N;
    int* arr = (int*)malloc(N * sizeof(int));

    int i = 0;
    while (i < N && scanf("%d", &arr[i]) == 1) i++;
    cout << selection_sort(arr, N) << endl;

    return 0;
}
