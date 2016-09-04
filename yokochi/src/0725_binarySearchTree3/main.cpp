#include <iostream>
#define NIL_INDEX -2000000000
struct Node {
    long index;
    Node *parent, *left, *right;
};
Node* NIL;
Node* getNil()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = NIL_INDEX;
    node->parent = node;
    node->left = node;
    node->right = node;
    return node;
}
Node* getNewNode()
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = NIL_INDEX;
    node->parent = NIL;
    node->left = NIL;
    node->right = NIL;
    return node;
}
Node* insertNode(Node* rootNode, int index)
{
    Node* node = rootNode;
    Node* parentNode = NIL;
    Node* indexNode = getNewNode();
    indexNode->index = index;
    if (node->index == NIL_INDEX) {
    return indexNode;
    }
    while (node->index != NIL_INDEX) {
    parentNode = node;
    if (node->index > index) {
        node->left->parent = node;
        node = node->left;
    } else {
        node->right->parent = node;
        node = node->right;
    }
    }
    indexNode->parent = parentNode;
    if (parentNode->index > index) {
    parentNode->left = indexNode;
    } else {
    parentNode->right = indexNode;
    }
    return rootNode;
}
void printNodeIn(Node* node)
{
    if (node->index == NIL_INDEX) {
    return;
    }
    printNodeIn(node->left);
    std::cout << " " << node->index;
    printNodeIn(node->right);
}
void printNodePre(Node* node)
{
    if (node->index == NIL_INDEX) {
    return;
    }
    std::cout << " " << node->index;
    printNodePre(node->left);
    printNodePre(node->right);
}
Node* findNode(Node* node, int index)
{
 
    while (node->index != NIL_INDEX) {
    if (node->index == index) {
        return node;
    }
    if (node->index > index) {
        node = node->left;
    } else {
        node = node->right;
    }
    }
    return NIL;
}
Node* getMinimum(Node* node)
{
    while (node->left != NIL) {
    node = node->left;
    }
    return node;
}
Node* getSuccessor(Node* node)
{
    if (node->right != NIL) {
    return getMinimum(node->right);
    }
    Node* y = node->parent;
    while (y != NIL && node == y->right) {
    node = y;
    y = y->parent;
    }
    return y;
}
void deleteNode(Node* indexNode)
{
    if (indexNode->index == NIL_INDEX) {
    return;
    }
    //子が無い時
    if (indexNode->left == NIL && indexNode->right == NIL) {
    Node* parent = indexNode->parent;
    if (parent->left == indexNode) {
        parent->left = NIL;
    }
    if (parent->right == indexNode) {
        parent->right = NIL;
    }
    return;
    } else if (indexNode->left == NIL || indexNode->right == NIL) {
    //子が1つの時
    Node* parent = indexNode->parent;
    Node* child = indexNode->left == NIL ? indexNode->right : indexNode->left;
    child->parent = parent;
    if (parent->left == indexNode) {
        parent->left = child;
    }
    if (parent->right == indexNode) {
        parent->right = NIL;
    }
    return;
    } else {
    //子が２つの時
    Node* inNode = getSuccessor(indexNode);
    indexNode->index = inNode->index;
    deleteNode(inNode);
    }
}
int main()
{
    NIL = getNil();
    Node* node = NIL;
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
    std::string command;
    std::cin >> command;
    if (command == "insert") {
        int index;
        std::cin >> index;
        node = insertNode(node, index);
    } else if (command == "print") {
        printNodeIn(node);
        std::cout << std::endl;
        printNodePre(node);
        std::cout << std::endl;
    } else if (command == "find") {
        int index;
        std::cin >> index;
        Node* answerNode = findNode(node, index);
        if (answerNode->index != NIL_INDEX) {
        std::cout << "yes" << std::endl;
        } else {
        std::cout << "no" << std::endl;
        }
    } else if (command == "delete") {
        int index;
        std::cin >> index;
        Node* indexNode = findNode(node, index);
        deleteNode(indexNode);
    }
    }
}
