#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

void solve(int* w,int n,int wMin){
  int ans = 0;
  int tmpAry[n], subAry[n];
  bool b[n];
  
  for(int i=0;i<n;i++){    
    b[i] = false;
    subAry[i] = w[i];
  }
  
  sort(subAry, subAry+n);
  for(int i=0;i<n;i++){
    tmpAry[subAry[i]] = i;
  }
  
  for(int i=0;i<n;i++){
    if(b[i])continue;
    int index = i;
    int sum=0;
    int m=10000;
    int subans=0;
    while(1){
      b[index] = true;
      subans++;
      m = min(m, w[index]);
      sum += w[index];
      index = tmpAry[w[index]];
      if(b[index])break;
    }
    ans += min(sum+(subans-2)*m, sum+m+(subans+1)*wMin);
  }
  //要素全体の最小値を用いた場合と用いない場合の比較

  printf("%d\n", ans);
}

int main(){
  int n;
  scanf("%d", &n);
  int w[n];
  int wMin = 10000;
  char dummy;
  for(int i=0;i<n;i++){
    scanf("%d%c", &w[i], &dummy);
    wMin = min(wMin,w[i]);
  }

  solve(w, n, wMin);
  return 0;
}
