
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef struct counter_info {
    int depth;
    int position;
} ci;
typedef struct sum_info {
    int sum;
    int position;
} si;
stack<ci> contour;
stack<si> sumstack;

void print()
{
    int allsum = 0;
    long stacksize = sumstack.size();
    int a[sumstack.size()];
    for (int i = 0; i < stacksize; i++) {
	allsum += sumstack.top().sum;
	a[i] = sumstack.top().sum;
	sumstack.pop();
    }
    cout << allsum << endl;
    cout << stacksize;
    int alength = sizeof(a) / sizeof(a[0]);
    for (int i = alength - 1; i >= 0; i--) {
	cout << " " << a[i];
    }
    cout << endl;
}
void pushToSumStack(int position, int sum)
{
    si* sinfo = (si*)malloc(sizeof(si));
    sinfo->sum = sum;
    sinfo->position = position;
    sumstack.push(*sinfo);
}
void calTotalSum(int position, int sum)
{
    if (sumstack.empty()) {
	pushToSumStack(position, sum);
	return;
    }
    si sumtop = sumstack.top();
    si newtop = sumtop;
    if (position > sumtop.position) {
	pushToSumStack(position, sum);
	return;
    }
    while (position < sumtop.position) {
	sumstack.pop();
	newtop.sum += sum;
	if (sumstack.empty()) {
	    break;
	}
	sumtop = sumstack.top();
	sum = sumtop.sum;
    }
    sumstack.push(newtop);
}
void solve(char c[20000])
{

    int N = strlen(c);
    int depth = 0;
    for (int i = 0; i < N; i++) {
	if ('\\' == c[i]) {
	    depth++;
	    ci* cinfo = (ci*)malloc(sizeof(ci));
	    cinfo->depth = depth;
	    cinfo->position = i;
	    contour.push(*cinfo);
	    //	    sum += depth - 0.5;
	}
	if ('/' == c[i]) {
	    if (contour.empty()) {
		continue;
	    }
	    int sum = 0;
	    ci ctop = contour.top();
	    if (ctop.depth == depth) {
		contour.pop();
		if (c[i - 1] == '\\') {
		    sum = 1;
		    si* sinfo = (si*)malloc(sizeof(si));
		    sinfo->sum = sum;
		    sinfo->position = ctop.position;
		    sumstack.push(*sinfo);
		} else {
		    sum = i - ctop.position;
		    calTotalSum(ctop.position, sum);
		}
	    }
	    depth--;
	}
	if ('_' == c[i]) {
	}
    }
    print();
}

int main()
{
    char c[20000];
    while (scanf("%s", c) != 1) {
    }
    solve(c);
    return 0;
}

