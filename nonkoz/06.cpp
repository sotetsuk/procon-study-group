#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

vector<int> lastOrder;

void print(){
  for(int i=0;i<lastOrder.size()-1;i++){
    printf("%d ", lastOrder[i]);
  }
  printf("%d\n", lastOrder[lastOrder.size()-1]);
  
}

void solve(int *preOrder, int *midOrder, int n,int position, int left, int right){
  if( left >= right)return;
  //次の基準とするノード
  int root = preOrder[position++];
  //中間順でのrootの位置
  int midPosRoot = distance(&(midOrder[0]),find(&(midOrder[0]), &(midOrder[n]), root));
  //左部分木と右部分木復元
  solve(preOrder, midOrder, n, position, left, midPosRoot);
  // solve(preOrder, midOrder, n, position, midPosRoot+1, right-1);
  lastOrder.push_back(root);

}

int main(){
  int n;
  scanf("%d", &n);
  int preOrder[n], midOrder[n];
  char dummy;
  for(int i=0;i<n;i++){
    scanf("%d%c", &preOrder[i], &dummy);
    
  }
  for(int i=0;i<n;i++){
    scanf("%d%c", &midOrder[i], &dummy);
  }
  
  solve(preOrder, midOrder, n, 0, 0, n);
  print();
}
