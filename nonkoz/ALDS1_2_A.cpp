#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

void swap(int *a,int *b);
int bubbleSort(vector<int> ary);
void printAry(vector<int> ary);

void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
};

int bubbleSort(vector<int> ary){
  int num_swap = 0;
  for(int i=0;i<ary.size()-1;i++){
    for(int j=0;j<ary.size()-i-1;j++){
      if(ary[j] <= ary[j+1])continue;
      swap(&ary[j], &ary[j+1]);
      num_swap++;
    }
  }
  printAry(ary);
  return num_swap;
};

void printAry(vector<int> ary){
  for(int i=0;i<ary.size()-1;i++)cout << ary[i] << " ";
  cout << ary[ary.size()-1] << endl;
};

int main(){
  int lengthAry;
  vector<int> numAry;
  cin >> lengthAry;

  for(int i=0;i<lengthAry;i++){
    int n;
    cin >> n;
    numAry.push_back(n);
  }
  int numSwap = bubbleSort(numAry);
  cout << numSwap << endl;;
}
