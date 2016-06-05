#include <iostream>
#include <cstdio>
#include <cstdlib>

int num_com = 0;
void merge(int *array, int *tmp, int left, int right, int mid){
  for(int i=left;i<= mid;i++)tmp[i] = array[i];
  for(int i=mid+1,j=right;i<=right;i++,j--)tmp[i] = array[j];  
  int i= left;
  int j= right;
  for(int k=left;k <= right;k++){
    if(tmp[i] <= tmp[j])array[k] = tmp[i++];
    else array[k] = tmp[j--];
    num_com++;
    }
}
  
void mergeSort(int *array, int *tmp,int left, int right){
  if(left >= right)return;

  int mid = (left+right)/2;
  //前半と後半の要素をそれぞれソート
  mergeSort(array, tmp, left, mid);
  mergeSort(array, tmp, mid+1,right);
  
  merge(array, tmp, left, right, mid);
  
}


int main(){
  int n;
  scanf("%d\n", &n);
  char dummy;
  int array[n];
  int tmp[n];

  for(int i=0;i<n;i++)scanf("%d%c", &array[i], &dummy);
  
  mergeSort(array, tmp, 0, n-1);
  
  for(int i=0;i<n-1;i++)printf("%d ", array[i]);
  printf("%d\n",array[n-1]);
  printf("%d\n",num_com);
  return 0;
}
