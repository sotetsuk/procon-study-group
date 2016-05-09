#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;
struct Node {
    int key;
    Node *next, *prev;
};
static string INSERT = "insert";
static string DELETE = "delete";
static string DELETE_FIRST = "deleteFirst";
static string DELETE_LAST = "deleteLast";

Node* nil;

void init(Node* nil)
{
    nil = (Node*)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

Node* insertN(int key, Node* prev)
{
    Node* n = (Node*)malloc(sizeof(Node));

    n->key = key;
    n->prev = prev;
    n->next = nil;
    if (n->prev != nil) {
	n->prev->next = n;
    }
    return n;
}
Node* deleteN(int key, Node* n)
{
    Node *last = n;
    while (n != nil) {
	if (key == n->key) {
	    if (n->prev != nil) {
		n->prev->next = n->next;
	    }
	    if (n->next != nil) {
		n->next->prev = n->prev;
	    }

	    if (n == last) {
		last = n->prev;
	    }
	    free(n);
	    break;
	    return last;
	}
	n = n->prev;
    }
    return last;
}
void deleteLastN(Node* n)
{
    while (n != nil) {
	if (n->prev == nil) {
	    n->next->prev = nil;
	    free(n);
	}
	n = n->prev;
    }
}
Node* deleteFirstN(Node* n)
{
    n->prev->next = nil;
    Node* prev = n->prev;
    free(n);
    return prev;
}

void print(Node* n)
{
    while (n != nil) {
	cout << n->key;
	n = n->prev;
	if (n != nil) {
	    cout << " ";
	}
    }
    cout<<endl;
}
int main()
{
    int N = 0;
    scanf("%d", &N);
    init(nil);
    Node* prevNode = nil;
    char command[20];
    int key = 0;
    for (int i = 0; i < N; i++) {
	cin >> command;
	if (INSERT == command) {
	    cin >> key;
	    prevNode = insertN(key, prevNode);
	} else if (DELETE == command) {
	    cin >> key;
	    prevNode = deleteN(key, prevNode);
	} else if (DELETE_FIRST == command) {
	    prevNode = deleteFirstN(prevNode);
	} else if (DELETE_LAST == command) {
	    deleteLastN(prevNode);
	}
    }
    print(prevNode);
    return 0;
}

