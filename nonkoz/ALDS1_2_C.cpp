#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Card{
public:
  void setCards(char mark,int number){
    this->mark = mark;
    this->number = number;
  }
  char mark;
  int number;
};

void swap(Card* a,Card* b){
  Card tmp = *a;
  *a = *b;
  *b = tmp;
}

void printCards(Card* cards,int size){
  for(int i=0;i<size-1;i++){
    cout << cards[i].mark << cards[i].number << " ";
  }
  cout << cards[size-1].mark << cards[size-1].number << endl;

}

void bubbleSort(Card* cards,int size){
  for(int i=0;i<size-1;i++){
    for(int j=size-1;j>=i+1 ;j--){
      if(cards[j].number < cards[j-1].number)
	swap(&cards[j], &cards[j-1]);
    }
  }
  printCards(cards,size);
}

void selectionSort(Card *cards, int size){
  for(int i=0;i<size-1;i++){
    int min = i;
    for(int j=i;j<size;j++){
      if(cards[j].number < cards[min].number)min = j;
    }
    swap(&cards[i],&cards[min]);
  }
  printCards(cards,size);
}
bool sameCheckCards(Card a,Card b){
  if(a.number == b.number && a.mark == b.mark)return true;
  return false;
}
void checkStable(Card *in,Card *out,int size){
  
  for(int i=0;i<size;i++){
    for(int j=i+1;j<size;j++){
      for(int a=0;a<size;a++){
	for(int b=a+1;b<size;b++){
	  if(in[i].number != in[j].number || in[i].number != out[a].number || in[i].number != out[b].number)continue;
	  if(sameCheckCards(in[i],out[b]) && sameCheckCards(in[j],out[a])){	    
	    cout << "Not stable" << endl;
	    return;
	  }
	}
      }
    }
  }
  cout << "Stable" << endl;
  return;
}
int main(){
  int n;
  cin >> n;
  Card cardsSource[n];
  Card cardsBubble[n];
  Card cardsSelection[n];
  for(int i=0;i<n;i++){
    int number;
    char mark;
    cin >> mark >> number;
    cardsSource[i].setCards(mark,number);
    cardsBubble[i].setCards(mark,number);
    cardsSelection[i].setCards(mark,number);
  }
  
  bubbleSort(cardsBubble, n);
  checkStable(cardsBubble, cardsSource, n);  
  selectionSort(cardsSelection,n);
  checkStable(cardsSelection, cardsSource,n);
  
  return 0;
}
