#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

/* insertion sort */

void swap(int a,int b);
void insertionSort(vector<int> ary);
void printAry(vector<int> ary);

void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void insertionSort(vector<int> ary){
  int v;
  for(int i=1;i<ary.size();i++){
    int v = ary[i];
    int j = i-1;
    while((j >= 0) && (ary[j] > v)){      
      swap(&ary[j], &ary[j+1]);
      j--;
    }
    printAry(ary);
    ary[j+1] = v;
  }
}


void printAry(vector<int> ary){
  for(int i=0;i<ary.size()-1;i++){
    cout << ary[i] << " ";
  }
  cout << ary[ary.size()-1] << endl;
}

int main()
{
  int num;
  cin >> num;
  vector<int> numAry;
  
  for(int i=0;i<num;i++){
    int number;
    cin >> number;
    numAry.push_back(number);
  }
  printAry(numAry);
  insertionSort(numAry);
  
  return 0;
  
}
