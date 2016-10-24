#include <iostream>
#include <vector>
using namespace std;
vector<int> G[100];
int isVisited[100];

void setupVisited(int n)
{
    for (int i = 0; i <= n; i++) {
	isVisited[i] = 0;
    }
}
bool enableConnection(int l, int o)
{
    for (int i = 0; i < G[l].size(); i++) {
	if (G[l][i] == o) {
	    return true;
	}
	if (isVisited[l] == 1) {
	    return false;
	}
	isVisited[l] = 1;
	if (enableConnection(G[l][i], o) || enableConnection(o, G[l][i])) {
	    return true;
	}
    }
    return false;
}

int main()
{
    int a, c;
    cin >> a;
    cin >> c;
    //setup
    for (int i = 0; i < c; i++) {
	int n;
	int m;
	cin >> n >> m;
	G[n].push_back(m);
	G[m].push_back(n);
	isVisited[i] = 0;
    }

    //then
    int b = 0;
    cin >> b;
    for (int i = 0; i < b; i++) {
	int l;
	int o;
	cin >> l;
	cin >> o;
	setupVisited(c);
	if (enableConnection(l, o) || enableConnection(o, l)) {
	    cout << "yes" << endl;
	} else {
	    cout << "no" << endl;
	}
    }
    return 0;
}
