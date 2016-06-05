#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int sum = 0;

void binarySearch(int start,int end,int* s,int search);

void binarySearch(int start,int end,int* s,int search){
  int mid = start+(int)((end-start)/2);
  if(start > end)return;
  if(s[mid] == search){
    sum++;
    return;
  }else if(search < s[mid]){
    binarySearch(start, mid-1,s,search);
  }else{
    binarySearch(mid+1, end, s, search);
  }
}
int main(){
  int n,q;
  cin >> n;

  int s[n];
  for(int i=0;i<n;i++)
    cin >> s[i];

  cin >> q;
  int t[q];
  for(int i=0;i<q;i++){
    cin >> t[i];
  }

  for(int i=0;i<q;i++){
    binarySearch(0, n,s,t[i]);
  }

  cout << sum << endl;
  
  
}
