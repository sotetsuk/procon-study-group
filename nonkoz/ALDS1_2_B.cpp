#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
void swap(int *a,int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void printAry(vector<int> ary){
  for(int i=0;i<ary.size()-1;i++)
    cout << ary[i] << " ";
  cout << ary[ary.size()-1] << endl;
}
int  selectionSort(vector<int> ary){
  int swapNum = 0;
  for(int i=0;i<ary.size()-1;i++){
    int minIndex = i;
    
    for(int j=i+1;j<ary.size();j++){
      if(ary[minIndex] <= ary[j])continue;
      minIndex = j;
      }
    if(minIndex == i)continue;
    swap(&ary[i], &ary[minIndex]);
    swapNum++;
  }
    printAry(ary);
    return swapNum;
}
int main()
{
  int n;
  cin >> n;
  vector<int> numAry;
  
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    numAry.push_back(x);
  }
  cout << selectionSort(numAry) << endl;;

  return 0;
}
