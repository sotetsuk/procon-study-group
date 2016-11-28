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
#define INF std::numeric_limits<int>::max()

//typedef
//-------------------------------------------
typedef long long ll;

int n;
int g[101][101];

int prim(int used, int sum) {
    if (used == 0) return sum;

    int tmp = INF;
    int use = -1;
    REP(i, n) {
        if ((used>>i)&1) {
            continue;
        }
        REP(j, n) {
            if (((used>>j)&1) && g[i][j] < tmp) {
                tmp = g[i][j];
                use = j;
            }
        }
    }
    if (tmp == INF) return sum;
    return prim(used&(~(1<<use)), sum + tmp);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    memset(g, INF, sizeof(g));
    REP(i, n) REP(j, n) {
        cin >> g[i][j];
        if (g[i][j] < 0) g[i][j] = INF;
    }
    int used = (1<<n) - 1;
    cout << prim(used&(~1), 0) << endl;

    return 0;
}
