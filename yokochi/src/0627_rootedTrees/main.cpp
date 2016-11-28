#include <iostream>
struct Node {
    int index;
    Node* parent;
    Node* child;
};

Node* NIL;

Node* getNilNode()
{
    Node* nil = (Node*)malloc(sizeof(Node));
    nil->index = -1;
    return nil;
}
Node* getNode(Node* T, int index, int num, int* nodeArr)
{
    Node* node;
    if (&T[index] == NIL) {
	node = (Node*)malloc(sizeof(Node));
	node->index = index;
    }
    node->child = (Node*)malloc(num * sizeof(Node));
    for (int i = 0; i < num; i++) {
	std::cout << node->child;
	//ここでセグフォ起きる
	node->child[i].index = nodeArr[i];
    }
    return node;
}

int main()
{
    Node* t;
    int n = 0;
    std::cin >> n;
    t = (Node*)malloc(n * sizeof(Node));
    NIL = getNilNode();
    //初期化
    for (int i = 0; i < n; i++) {
	t[i] = *NIL;
    }

    for (int i = 0; i < n; i++) {
	int index = 0;
	int num = 0;
	std::cin >> index;
	std::cin >> num;
	int* nodeArr = (int*)malloc(num * sizeof(int));
	for (int j = 0; j < num; j++) {
	    std::cin >> nodeArr[j];
	}
	t[i] = *getNode(t, index, num, nodeArr);
    }
    for (int i = 0; i < n; i++) {
	std::cout << t[i].index << std::endl;
    }
}
