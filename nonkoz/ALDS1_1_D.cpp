#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int findMax(vector<int> ary);

int findMax(vector<int> ary){
  int maxv = ary[1] - ary[0];
  int minv = ary[0];
 
  for(int i=1;i<ary.size();i++){
    maxv = max(maxv, (ary[i] - minv));
    minv = min(minv, ary[i]);
  }
  return maxv;
}

int main(){
  int n;
  cin >> n;
  vector<int> numAry;
  
  for(int i=0;i<n;i++){
    int x;
    cin >> x;
    numAry.push_back(x);
  }

  cout << findMax(numAry) << endl;
  return 0;
}

