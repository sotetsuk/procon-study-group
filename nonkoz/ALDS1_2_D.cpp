#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int cnt = 0;


void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printAry(int *ary,int size){
  for(int i=0;i< size;i++)
    cout << ary[i] << endl;
}

void insertionSort(int* ary,int g,int size){
    for(int i = g-1;i<size;i++){
        int j = i;
        while(j-g>=0 && ary[j-g]>ary[j]){
	  swap(&ary[j-g], &ary[j]);
	  j=j-g;
	  cnt++;
        }
    }
}
void shellSort(int* ary,int size){
    int h = 1;
    vector<int> G;
    while(h <= size){
        G.push_back(h);
        h=3*h+1;
    }
    for(int i = G.size()-1;i>=0;i--){
        insertionSort(ary,G[i],size);
    }
    cout << G.size() << endl;
    for(int i=G.size()-1;i>0;i--)cout << G[i] << " ";
    cout << G[0] << endl;    
}

int main(){

  int n;
  cin>>n;
  int numAry[n];
  for(int i=0;i<n;i++){
    cin >> numAry[i];
  }
  
  shellSort(numAry,n);
  cout << cnt << endl;
  printAry(numAry,n);
  
  return 0;
}
