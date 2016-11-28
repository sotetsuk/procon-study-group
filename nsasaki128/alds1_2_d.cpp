#include <stdlib.h>
#include <iostream>
#include <list>
using namespace std;

void insertion_sort(int *array, int n, int g, int &cnt);
void shell_sort(int *array, int n);
void print_array(int *array, int size);
int main(){
	int n;

	cin >> n;

	int* array = (int*)malloc(n * sizeof(int));

	if(n < 1){
		return 0;
	}

	for(int i = 0; i < n; i++){
		cin >> array[i];
	}
	shell_sort(array, n);
	return 0;
}
void insertion_sort(int *array, int n, int g, int &cnt){
	//gは比較の幅
	for(int i = g; i < n; i++){
		int v = array[i];
		int j = i - g;
		//g離れた変数に対して挿入ソートi=4gのとき、4gと3g 3gと2g 2gとg gと0
		while(j >= 0 && array[j] > v){
			array[j+g] = array[j];
			j -= g;
			++cnt;
		}
		array[j+g] = v;
	}
}

void shell_sort(int *array, int n){
	int* G = (int*)malloc(n * sizeof(int));
	int g = 1;
	int m = 0;
	int cnt = 0;
	do{
		G[m] = g;
		++m;
		g *= 3;
		g += 1;
	}
	while(g < n);

	for(int i = 0; i < m - i; ++i){
		swap(G[i], G[m-i-1]);
	}
	for(int i = 0; i < m; ++i){
		insertion_sort(array, n, G[i], cnt);
	}
	cout << m << endl;
	print_array(G, m);
	cout << cnt << endl;
	for(int i = 0; i < n; ++i){
		cout << array[i] << endl;
	}

}

void print_array(int *array, int size){
	for(int i = 0; i < size; i++){
		cout <<  array[i];
		if(i != size - 1){
		cout << " " ;
		}
	}
	cout << endl;
}