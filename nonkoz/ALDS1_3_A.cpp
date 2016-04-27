#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define MAX_SIZE 200;

class Stack{
  
public:
  void initialize();
  bool isEmpty();
  bool isFull();
  void push(string n);
  string pop();  
private:
  int top;
  string stack[MAX_SIZE];
};
  
  void Stack::initialize(){
    top = 0;
    for(int i=0;i<MAX_SIZE;i++){
      stack[i] = "";
    }
  }

bool Stack::isEmpty(){
  if(top == 0)return true;
  else return false;
}

bool Stack::isFull(int max_size){
  if(top > max_size)return true;
  return false;
}

void Stack::push(int n){
  top++;
  stack[top] = n;
}

string Stack::pop(){
  top--;
  return stack[top+1];
}

int main()
{
  int num_number = 100;
  int num_op = 99;
  
  string number[num_number];
  string op[num_op];

  Stack stk;
  

  return 0;
  
}
