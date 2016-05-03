#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

#define MAX_SIZE 200

class Stack{ 
public:
  void initialize();
  bool isEmpty();
  bool isFull();
  void push(int n);
  int pop();  
private:
  int top;
  int stack[MAX_SIZE];
};
  
void Stack::initialize(){
  top = 0;
  for(int i=0;i<MAX_SIZE;i++){
    stack[i] = 0;
  }
}

bool Stack::isEmpty(){
  if(top == 0)return true;
  else return false;
}

bool Stack::isFull(){
  if(top > MAX_SIZE)return true;
  return false;
}

void Stack::push(int n){
  top++;
  stack[top] = n;
}

int Stack::pop(){
  top--;
  return stack[top+1];
}

int main()
{

  Stack *stk = new Stack();
  

  string line,in;
  getline(cin ,line);
  stringstream ss(line);

  while(getline(ss, in, ' ')){
    int a,b;
    if(in == "+"){
      a = stk->pop();
      b = stk->pop();
      a = b + a;      
    }else if(in == "-"){
      a = stk->pop();
      b = stk->pop();
      a = b - a;      
    }else if(in == "*"){
      a = stk->pop();
      b = stk->pop();
      a = b * a;
    }else{
      sscanf(in.c_str(), "%d", &a);
    }
    stk->push(a);
  }
  cout << stk->pop() << endl;
  return 0;
  
}
