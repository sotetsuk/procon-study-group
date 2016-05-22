//
//  main.cpp
//  c++proj
//
//  Created by chiiia12 on 2016/04/18.
//
//

#include <iostream>
#include <vector>
using namespace std;

int cnt;
vector<int> G;

void insertionSort(int* a,int g,int n){
    for(int i = g-1;i<n;i++){
        int j = i;
        while(j-g>=0&&a[j-g]>a[j]){
            int tmp = a[j];
            a[j] = a[j-g];
            a[j-g] = tmp;
            j=j-g;
            cnt++;
        }
    }
}
void selectionSort(int* a,int n){
    cnt = 0;
    for(int h =1;;){
        if(h>n)break;
        G.push_back(h);
        h=3*h+1;
    }
    for(int i = G.size()-1;i>=0;i--){
        insertionSort(a,G[i],n);
    }
}

int main() {
    int n;
    cin>>n;
    int a[n];
    for(int i =0;i<n;i++){
        cin>>a[i];
    }
    selectionSort(a,n);
    cout<<G.size()<<endl;
    for(int i = G.size()-1;i>0;i--){
        cout<<G[i]<<" ";
    }
    cout<<G[0]<<endl;
    cout<<cnt<<endl;
    for(int i = 0;i<n;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}
