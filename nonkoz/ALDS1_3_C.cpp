#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Cell{
public:
  Cell(int number){data = number;};
  int getData(){return data;};
  Cell* getNext(){return next;};
  Cell* getBack(){return back;};
  void setNext(Cell* cell){next = cell;};
  void setBack(Cell* cell){back = cell;};
private:
  int data;
  Cell* next;
  Cell* back;
};

class DLinkedList{
 public:
  DLinkedList();
  void insertX(int x);
  void deleteX(int x);
  void deleteFirst();
  void deleteLast();
  void printDLinkedList();
 private:
  Cell* dummy;
};

DLinkedList::DLinkedList(){
  dummy = new Cell(-1);
  dummy->setNext(dummy);
  dummy->setBack(dummy);
}

void DLinkedList::insertX(int x){
  Cell* first = new Cell(x);

  first->setNext(dummy->getNext());
  dummy->setBack(first);
  first->setBack(dummy);
  first->getNext()->setBack(first);
  dummy->setNext(first);
}


void DLinkedList::deleteX(int x){
  Cell* cell = dummy;
  while(1){
    cell = cell->getNext();
    if(cell == dummy)return;
    if(cell->getData() == x)break;
  }

  cell->getBack()->setNext(cell->getNext());
  cell->getNext()->setBack(cell->getBack());
  delete cell;
}

void DLinkedList::deleteFirst(){
  Cell* first = dummy->getNext();
  if(first == dummy)return;

  dummy->setNext(first->getNext());
  first->getNext()->setBack(dummy);

  delete first;
}

void DLinkedList::deleteLast(){
  Cell* cell = dummy->getBack();
  if(cell == dummy)return;

  cell->getBack()->setNext(dummy);
  dummy->setBack(cell->getBack());

  delete cell;
}

void DLinkedList::printDLinkedList(){
  Cell* cell = dummy;
  if(dummy->getNext() == dummy)return;

  while(1){
    cell = cell->getNext();
    if(cell->getNext() == dummy) break;

    printf("%d ", cell->getData());
  }
  cout << cell->getData() << endl;
}
int main()
{
  int n;
  cin >> n;

  string command;
  int number;
  DLinkedList* dll = new DLinkedList();
  for(int i=0;i<n;i++){
    cin >> command;
    if(command == "insert"){
      cin >> number;
      dll->insertX(number);
    }else if(command == "delete"){
      cin >> number;
      dll->deleteX(number);
    }else if(command == "deleteFirst"){
      dll->deleteFirst();
    }else{
      dll->deleteLast();
    }
  }

  dll->printDLinkedList();

  return 0;
}
