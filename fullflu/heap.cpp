#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>

using namespace std;

void heap_print(vector<int> &v){
	int n = v.size();
	for(int i=0; i < n;i++){
		if(i==0){
			int li = (i+1)*2 - 1;
			int ri = (i+1)*2;
			cout << "node " << i+1 << ": key = " <<  v.at(i) << ", left key = " << v.at(li) << ", right key = " << v.at(ri) << ", " << endl; 
		}
		else{
			int pi = (i+1)/2 - 1;
			int li = (i+1)*2 - 1;
			int ri = (i+1)*2;
			if(li >= n)
				cout << "node " << i+1 << ": key = " <<  v.at(i) << ", parent key = " << v.at(pi) <<  ", " << endl; 
			else if(ri >= n)
				cout << "node " << i+1 << ": key = " <<  v.at(i) << ", parent key = " << v.at(pi) << ", left key = " << v.at(li) << ", " << endl; 
			else
				cout << "node " << i+1 << ": key = " <<  v.at(i) << ", parent key = " << v.at(pi) << ", left key = " << v.at(li) << ", right key = " << v.at(ri) << ", " << endl; 

		}
	}
}

void heap_max(int i, std::vector<int> &v){
	int n = v.size();
	int li = (i+1)*2 - 1;
	int ri = (i+1)*2;
	int largest = i;
	if(li < n && v.at(i) < v.at(li)){
		largest = li;
	}
	if(ri < n && v.at(largest) < v.at(ri)){
		largest = ri;
	}
	if(largest != i){
		int tmp = v.at(i);
		v.at(i) = v.at(largest);
		v.at(largest) = tmp;
		heap_max(largest,v);
	}
}

void heap_max_build(int n, std::vector<int> &v){
	for(int i=n-1; i>=0; i--){
		heap_max(i, v);
	}
}

void heap_exe(int q){
	int n, value;
	vector<int>::iterator it3;
	cin >> n;
	vector<int> v(n);
	for(it3 = v.begin(); it3 != v.end(); it3++){
		cin >> value;
		*it3 = value;
	}
	if(q == 0)
		heap_print(v);
	else if(q == 1){
		heap_max_build(n/2,v);
		for(int i=0; i<n; i++)
			cout << " " << v.at(i);
		cout << endl;
	}
}

int main(){
	heap_exe(0);
	heap_exe(1);
	return 0;
}
