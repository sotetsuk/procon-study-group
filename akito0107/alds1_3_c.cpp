#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef struct node {
    struct node* prev;
    struct node* next;
    int data;
} node_t;

void print_list(node_t* head) {
    node_t* node = head->next;
    while(node) {
        cout << node->data;
        node = node->next;
        if (node) {
            cout << " ";
        }
    }
    cout << endl;
}

node_t* init() {
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head->prev = NULL;
    head->next = NULL;
    head->data = -1;
    return head;
}

node_t* insert(node_t* head, int data) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    node->data = data;
    node->prev = head;
    node->next = head->next;
    head->next = node;
    if (node->next) {
        node->next->prev = node;
    }
    return node;
}

int delete_key(node_t* head, int key) {
    node_t* node = head->next;
    while(node) {
        if (node->data == key) {
            node->prev->next = node->next;
            if (node->next)
                node->next->prev = node->prev;
            free(node);
            return 1;
        }
        node = node->next;
    }
    return -1;
}

int delete_first(node_t* head) {
    node_t* node = head->next;
    node->next->prev = head;
    head->next = node->next;
    free(node);
    return 1;
}

int delete_last(node_t* head) {
    node_t* node = head->next;
    while(node->next != NULL) node = node->next;
    node->prev->next = NULL;
    free(node);
    return 1;
}

int main() {
    int n = 0;
    cin >> n;
    node_t* list = init();

    for(int i = 0; i <= n; i++) {
        string line;
        getline(cin, line);
        string buf;
        stringstream ss(line);
        ss >> buf;
        if (buf == "deleteFirst") {
            delete_first(list);
        } else if (buf == "deleteLast") {
            delete_last(list);
        } else if (buf == "insert") {
            ss >> buf;
            insert(list, stoi(buf));
        } else if (buf == "delete") {
            ss >> buf;
            delete_key(list, stoi(buf));
        }
    }
    print_list(list);

    return 0;
}
