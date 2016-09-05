#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

define MAX 200000
define SENTINEL 10000000000
typedef long long llong;

llong L[MAX/2+2],R[MAX/2+2];

void minimum_cost(){
	//#define MAX 1000//maximum size
	//static const int MAX = 1000;
	static const int VMAX = 10000;//maximum weight
	int n, A[MAX],s,i;
	int B[MAX],T[VMAX+1];
	//cout << MAX << endl;

	cin >> n;
	s = VMAX;
	for(int i=0;i<n;i++){
		cin >> A[i];
		s = min(s,A[i]);//minimum value in A
	}
	//int ans = minimum_cost_solver(MAX);
	int ans = 0;
	bool V[MAX];
	for(i=0;i<n;i++){
		B[i]=A[i];
		V[i]=false;
	}
	sort(B,B+n);
	for(i=0;i<n;i++){
		T[B[i]]=i;//index in A, where the weight is B[i]
	}
	for(i=0;i<n;i++){
		if(V[i]) continue;//whether the index i is in an at least one loop or not
		int cur = i;//current index (ar first, start index of a loop)
		int S=0;//sum of weights in the loop
		int m=VMAX;//minimum weight in the loop
		int an = 0;//counts of the loop
		while(1){
			V[cur] = true;
			an++;
			int v = A[cur];//weight of A[current]
			m = min(m,v);
			S += v;
			cur = T[v];
			if (V[cur]) break;//index cur is in the loop
		}
		ans += min(S + (an-2)*m, m + S + (an+1)*s);
	}

	cout << ans << endl;

}

int main()
{
	//countingsort();
	//mergesort_count();
	//tmp();
	minimum_cost();

	return 0;

}
