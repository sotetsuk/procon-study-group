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

void sort(int* arr, int size) {
    int counter = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = size - 1; j >= 1; --j) {
            if (arr[j] < arr[j - 1]) {
                counter++;
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
                flag = 1;
            }
        }
    }
    print_arr(arr, size);
    cout << counter << "\n";
}

int main() {

    int N = 0;
    cin >> N;
    int* arr = (int*)malloc(N * sizeof(int));

    int i = 0;
    while (i < N && scanf("%d", &arr[i]) == 1)
        i++;

    sort(arr, N);
    return 0;
}
