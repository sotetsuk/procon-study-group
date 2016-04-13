#include <iostream>
#include <stdlib.h>
using namespace std;

long N = 0;
long* values;

int main() {

    cin >> N;
    values = (long*)malloc(N * sizeof(long));
    for (int  i = 0; i < N; i++) {
        cin >> values[i];
    }
    long max = values[1] - values[0];
    long min = values[0];

    for (int i = 1; i < N; i++) {
        if (min > values[i]){
            min = values[i];
            continue;
        }

        if (max < (values[i] - min))
            max = values[i] - min;
    }

    cout << max << "\n";
    return 0;
}
