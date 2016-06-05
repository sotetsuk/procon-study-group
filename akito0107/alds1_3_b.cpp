#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>

using namespace std;

typedef struct node {
    struct node* next;
    string name;
    int data;
} node_t;

typedef struct queue {
    node_t* head;
    node_t* tail;
} queue_t;

void print_que(queue_t* que) {
    node_t* node = que->head->next;
    while(node) {
        cout << node->name << ":" << node->data;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}

queue_t* init() {
    queue_t* que = (queue_t*)malloc(sizeof(queue_t));
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head->next = NULL;
    head->data = -1;
    head->name = "head";
    que->head = head;
    que->tail = NULL;
    return que;
}

node_t* enqueue(queue_t* que, string name, int data) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->name = name;
    node->data = data;
    node->next = NULL;
    if (!que->head->next) que->head->next = node;
    if (que->tail) que->tail->next = node;
    que->tail = node;
    return node;
}

node_t* dequeue(queue_t* que) {
    node_t* node = que->head->next;
    que->head->next = node->next;
    return node;
}

int empty_que(queue_t* que) {
    return que->head->next == NULL;
}

int main() {
    int n = 0;
    int q = 0;
    scanf("%d %d", &n, &q);
    queue_t* que = init();

    for(int i = 0; i < n; i++) {
        string name;
        int unit = 0;
        cin >> name >> unit;
        enqueue(que, name, unit);
    }

    int time = 0;
    while (!empty_que(que)) {
        node_t* task = dequeue(que);
        if (task->data <= q) {
            time += task->data;
            cout << task->name << " " << time << endl;
            continue;
        }
        int remain = task->data - q;
        time += q;
        enqueue(que, task->name, remain);
        free(task);
    }
    return 0;
}

