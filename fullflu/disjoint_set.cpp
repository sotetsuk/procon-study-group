#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <typeinfo>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define SORT(c) sort((c).begin(),(c).end())
#define RSORT(c) sort((c).begin(),(c).end(),std::greater<int>())


class DisjointSet
{
private:
	bool empty;
	int *rank;
	int *p;
	int n;
public:
	DisjointSet();
	DisjointSet(int n);
	void print_rank(){
		REP(i,n) cout << i << " " << rank[i] << endl;
	}
	void unite(int x,int y);
	bool same(int x,int y);
	int findset(int x);
	int findset_withoutcompression(int x);
};

DisjointSet::DisjointSet(){
	empty = true;
}

DisjointSet::DisjointSet(int num){
	empty = false;
	rank = new int[num];
	p = new int[num];
	n = num;
	REP(i,n) p[i] = i;
}

void DisjointSet::unite(int x,int y){
	x = findset(x);
	y = findset(y);
	//x = findset_withoutcompression(x);
	//y = findset_withoutcompression(y);
	if(rank[x] > rank[y]){
		p[y] = x;
	}
	else{
		p[x] = y;
		if(rank[x] == rank[y]){
			rank[y]++;
		}
	}
}

int DisjointSet::findset_withoutcompression(int x){
	while(x!=p[x]){
		x = p[x];
	}
	return x;
}

int DisjointSet::findset(int x){
	if(x!=p[x]){
		p[x] = findset(p[x]);
	}
	return p[x];
}

bool DisjointSet::same(int x,int y){
	if(findset(x) == findset(y)){
	//if(findset_withoutcompression(x) == findset_withoutcompression(y)){
		return true;
	}
	else{
		return false;
	}
}

void exe(){
	int n,q;
	cin >> n >> q;
	int x,y;
	int s;
	DisjointSet ds(n);
	REP(i,q){
		cin >> s >> x >> y;
		if(s == 0){
			ds.unite(x,y);
		}
		else{
			bool same_result = ds.same(x,y);
			cout << same_result << endl;
		}
	}
	//ds.print_rank();
}

int main(){
	exe();
	return 0;
}

/*
5 12
0 1 4
0 2 3
1 1 2
1 3 4
1 1 4
1 3 2
0 1 3
1 2 4
1 3 0
0 0 4
1 0 2
1 3 0
*/

// with compression 00.07,00.09 sec
// without compression 00.06,00.08 sec

