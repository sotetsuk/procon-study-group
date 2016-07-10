#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cstdio>

#define SIZE 1046527
#define SIZE_WORD 14

char H[SIZE][SIZE_WORD];


long long hashFirst(long long key){
  return key % SIZE;
}

long long hashSecond(long long key){
  return 1 + key % (SIZE-1);
}

int hash(long long key, int i){
  return (hashFirst(key) + i*hashSecond(key)) % SIZE; 
}

//数値に変換（1文字）
int parseCharInt(char word){
  if(word == 'A')return 0;
  else if(word == 'C')return 1;
  else if(word == 'G')return 2;
  else if(word == 'T')return 3;
  else return -1;
}

//数字に変換(文字列)
int getKey(char *words){
  int key = 0;
  int p = 1;
  for(int i=0;i<strlen(words);i++){
    key += p*parseCharInt(words[i]);
    p *= 5;
  }
  return key;
}
  
bool insert(char *words){
  int i=0;
  long long key = getKey(words);
  while(1){
    int h=hash(key, i);
    if(strcmp(H[h], words) == 0)return false;
    else if(strlen(H[h]) == 0){
      strcpy(H[h], words);
      return true;
    }
    i++;
  }
}

bool search(char *words){
  int i = 0;
  long long key = getKey(words);
  while(1){
    int h = hash(key, i);
    if(strcmp(H[h], words) == 0)return true;
    else if(strlen(H[h]) == 0)return false;
  }
  return false;
}

int main(){
  int n;
  scanf("%d\n", &n);
  char order[10], words[SIZE_WORD];
  for(int i=0;i< SIZE;i++)H[i][0] = '\0';
  for(int i=0;i<n;i++){
    scanf("%s %s", order,  words);
    if(order[0] == 'i'){
      insert(words);
    }else if(order[0] == 'f'){
      if(search(words)){
	printf("yes\n");
      }else{
	printf("no\n");
      }
    }
  }
  return 0;
}
