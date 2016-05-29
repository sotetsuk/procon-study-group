#include <iostream>
#include <cstdio>
#include <cstdlib>

bool solve(int *a, int n, int m,int index){
  if(m == 0)return 1;
  if(index >= n)return 0;
  return (solve(a,n, m, index+1) || solve(a,n,m-a[index],index+1));
}

int main(){
  char dummy;
  int n;
  scanf("%d\n", &n);
  int a[n];
  for(int i=0;i<n;i++)scanf("%d%c", &a[i],&dummy);
  int q;
  scanf("%d\n", &q);
  int m;
  
  for(int i=0;i<q;i++){
    scanf("%d%c", &m,&dummy);
    if(solve(a,n, m,0))printf("yes\n");
    else printf("no\n");
  }
  return 0;
}
