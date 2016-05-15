#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct card {
    char suit;
    int value;
} card_t;

void swap(card_t* source, card_t* dist) {
    card_t tmp = *source;
    *source = *dist;
    *dist = tmp;
}

void print_arr(card_t* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i].suit << arr[i].value;
        if (i != size - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void bubble_sort(card_t* arr, int size) {
    int counter = 0;
    int flag = 1;
    while (flag) {
        flag = 0;
        for (int j = size - 1; j >= 1; --j) {
            if (arr[j].value < arr[j - 1].value) {
                counter++;
                swap(&arr[j], &arr[j - 1]);
                flag = 1;
            }
        }
    }
}

void selection_sort(card_t* arr, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        int minj = i;
        for (int j = i; j < size; j++) {
            if (arr[j].value < arr[minj].value) {
                minj = j;
            }
        }
        if (i == minj) continue;

        ++count;
        swap(&arr[i], &arr[minj]);
    }
}

card_t* arr_copy(card_t* source, int size) {
    card_t* dist = (card_t*)malloc(size * sizeof(card_t));
    for (int i = 0; i < size; i++) {
        dist[i] = source[i];
    }
    return dist;
}

int compare_arr(card_t* source, card_t* sorted, int size) {
    int test[14] = {};
    for (int i = 0; i < size; i++) {
        if (test[source[i].value] == 0) {
            test[source[i].value] = (int)source[i].suit;
            continue;
        }
        int j = 0;
        while((int)source[i].suit != 0 && source[i].value != sorted[j].value) j++;
        if ((int)sorted[j].suit != test[source[i].value]) return 0;
        source[i].suit = 0;
        test[source[i].value] = (int)source[i].suit;
    }
    return 1;
}

void check_stable(void (*sort) (card_t*, int), card_t* arr, int size) {
    card_t* sorted = arr_copy(arr, size);
    sort(sorted, size);
    print_arr(sorted, size);
    if (!compare_arr(arr, sorted, size)) {
        cout << "Not Stable" << endl;
        free(sorted);
        return;
    }
    cout << "Stable" << endl;
    free(sorted);
    return;
}

int main() {
    int N = 0;
    cin >> N;
    card_t* arr = (card_t*)malloc(N * sizeof(card_t));

    for(int i = 0; i < N; i++) {
        cin >> arr[i].suit >> arr[i].value;
    }
    check_stable(bubble_sort, arr, N);
    check_stable(selection_sort, arr, N);

    return 0;
}
