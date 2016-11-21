//include
//------------------------------------------
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <limits>
using namespace std;

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,a,b) for(int i=(a);i>(b);i--)
#define REP(i,n)  FOR(i,0,n)

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
//-------------------------------------------
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define INF (1<<21)
#define NOT_VISITED 0
#define FOUND 1
#define VISITED 2

//typedef
//-------------------------------------------
typedef long long ll;
typedef pair<int, int> Pair;
typedef priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

int n;
vector<Pair> g[101];
pq p_queue;
int d[101];
int visited[101];

int dijkstra(int start) {
    d[start] = 0;
    p_queue.push(Pair(d[start], start));
    visited[start] = VISITED;

    while(!p_queue.empty()) {
        Pair m = p_queue.top(); p_queue.pop();
        int u = m.second;
        visited[u] = VISITED;

        if (d[u] < m.first) continue;

        REP(i, g[u].size()) {
            int v = g[u][i].first;
            if (visited[v] == VISITED) continue;

            if (d[v] > d[u] + g[u][i].second) {
                d[v] = d[u] + g[u][i].second;
                p_queue.push(Pair(d[v], v));
            }
        }

        p_queue.pop();
    }
    return 1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 101) {
        visited[i] = NOT_VISITED;
        d[i] = INF;
    }

    cin >> n;
    REP(i, n) {
        int u, k;
        cin >> u >> k;
        REP(j, k) {
            int v, c;
            cin >> v >> c;
            Pair e(v, c);
            g[u].push_back(e);
        }
    }

    dijkstra(0);

    REP(i, n)  {
        cout << i << " " << d[i] << endl;
    }

    return 0;
}
