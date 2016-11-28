#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <typeinfo>

using namespace std;

void heap_climb(int i, std::vector<int> &v){
	if(i != 0){
		int pi = (i+1)/2 - 1;
		//cout << "come" << endl;
		//cout << v.at(0) << endl;
		//cout << v.at(1) << endl;
		if(v.at(i) > v.at(pi)){
			int tmp = v.at(pi);
			v.at(pi) = v.at(i);
			v.at(i) = tmp;
			heap_climb(pi, v);
		}
	}
}

void heap_extract_max(int i, std::vector<int> &v){
	int n = v.size();
	int largest = -1;
	int li = (i+1)*2 - 1;
	int ri = (i+1)*2;
	if(li < n){
		largest = li;
	}
	if(ri < n && v.at(li) < v.at(ri)){
		largest = ri;
	}
	if(largest != -1){
		v.at(i) = v.at(largest);
		heap_extract_max(largest, v);
	}
	if(largest == -1){
		if(i == n-1){
			v.pop_back();
		}
		else{
			//int last = v.at(n-1);
			v.at(i) = v.at(n-1);
			v.pop_back();
			//int parent = 
			heap_climb(i,v);
		}

	}

}

void priority_queue(){
	string com = "None";
	std::vector<int> v;
	while(com != "end"){
		cin >> com;
		if(com == "insert"){
			int value;
			cin >> value;
			v.push_back(value);
			//cout << "yaa" << endl;
			int n = v.size();
			if(n != 1){
				//cout << "n = "<< n << endl;
				heap_climb(n-1, v);
				//cout << "n = "<< n << endl;
			}
			//for(int i=0; i<n; i++){
				//cout << v.at(i) << " ";
			//}
			//cout << endl;
		}
		if(com == "extract"){
			cout << v[0] << endl;
			heap_extract_max(0,v);
		}
	}
	//cout << endl;
}


int main(){

	//binary_search_tree();
	//heep_exe(0);
	//heep_exe(1);
	priority_queue();
	return 0;
}



