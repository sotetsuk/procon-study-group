#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n;
    
    int str[n];
    for (int i = 0; i < n; i++) {
      cin >> str[i];
    }
    cin >> m;
    int str2[m];
    for (int i = 0; i < m; i++) {
      cin >> str2[i];
    }
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (str[j] == str2[i]) {
                count++;
                break;
            }
        }
    }

    printf("%d\n",count);
    return 0;
}
