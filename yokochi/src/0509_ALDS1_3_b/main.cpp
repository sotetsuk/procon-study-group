#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

typedef struct process {
    string name;
    int time;
} process_t;
int head = 0;
int tail = 0;
int t = 0;

vector<process_t*> arr;
void enqueue(process_t* p)
{
    tail++;
    arr.push_back(p);
}

process_t* dequeue()
{
    process_t* p = arr[head];
    head++;
    return p;
}

void print_arr(string name, int time) { cout << name << " " << time << endl; }

void solve(int q)
{
    if (head>tail) {
        return;
    }
    process_t* p = dequeue();
    
    if (p->time > q) {
        p->time = p->time - q;
        t += q;
        enqueue(p);
    } else {
        t += p->time;
        print_arr(p->name, t);
    }
    
    solve(q);
}

int main()
{
    int N = 0;
    int q = 0;
    cin >> N;
    cin >> q;
    tail = N - 1;
    for (int i = 0; i < N; i++) {
        process_t *p = (process_t*)malloc(sizeof(process_t));
        cin >> p->name;
        cin >> p->time;
        arr.push_back(p);
    }
    solve(q);
    return 0;
}



