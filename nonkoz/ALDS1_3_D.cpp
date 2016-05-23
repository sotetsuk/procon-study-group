#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
int totalArea(string str){

  stack<int> position;
  stack<pair <int,int> > oneArea;
  int total = 0;
  for(int i=0;i<20000;i++){  
    if(str[i] == '\0')break;
    if(str[i] == '\\'){    
      position.push(i);
    }else if(str[i] == '/' && position.size() > 0){
      int pTop = position.top();
      position.pop();
      total += i - pTop;
      int diff = i - pTop;
      while( oneArea.size() > 0 && oneArea.top().first > pTop){
	diff += oneArea.top().second;
	oneArea.pop();
      }
      oneArea.push(make_pair(pTop, diff));
    }
  }

  vector<int> ans;
  
  while(oneArea.size() > 0){
    ans.push_back(oneArea.top().second);
    oneArea.pop();
  }
  
  cout << total << endl;
  cout << ans.size();
  for(int i=ans.size()-1;i >=0;i--){
    cout << " " << ans[i];
    }
  cout << endl;
  return -1;
}

int main()
{
  string str;
  int i=0;
  
  cin >> str;
  totalArea(str);
  return 0;
}
