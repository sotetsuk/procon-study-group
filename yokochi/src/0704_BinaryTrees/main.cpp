#include <algorithm>
#include <iostream>
#define NIL -1
struct Node {
    int parent, left, right;
};
int getParent(Node* nodeArray, int index)
{
    return nodeArray[index].parent;
}
int getSibling(Node* nodeArray, int index)
{
    if (nodeArray[index].parent == NIL) {
	return NIL;
    }
    int parent = nodeArray[index].parent;
    if (nodeArray[parent].left == index) {
	return nodeArray[parent].right;
    } else {
	return nodeArray[parent].left;
    }
}
//子の数
int getDegree(Node* nodeArray, int index)
{
    int count = 0;
    if (nodeArray[index].left != NIL) {
	count++;
    }
    if (nodeArray[index].right != NIL) {
	count++;
    }
    return count;
}
int getDepth(Node* nodeArray, int index)
{
    int parent = nodeArray[index].parent;
    int depth = 0;
    while (parent != NIL) {
	depth++;
	parent = nodeArray[parent].parent;
    }
    return depth;
}
int getHeight(Node* nodeArray, int index)
{
    int h1 = 0;
    int h2 = 0;
    if (nodeArray[index].left != NIL) {
	h1 += getHeight(nodeArray, nodeArray[index].left) + 1;
    }
    if (nodeArray[index].right != NIL) {
	h2 += getHeight(nodeArray, nodeArray[index].right) + 1;
    }
    return std::max(h1, h2);
}
std::string getType(Node* nodeArray, int index)
{
    if (nodeArray[index].parent == NIL) {
	return "root";
    }
    if (nodeArray[index].left == NIL && nodeArray[index].right == NIL) {
	return "leaf";
    }
    return "internal node";
}
void printNode(Node* nodeArray, int n)
{
    for (int i = 0; i < n; i++) {
	std::cout << "node " << i << ": ";
	std::cout << "parent = " << getParent(nodeArray, i) << ", ";
	std::cout << "sibling = " << getSibling(nodeArray, i) << ", ";
	std::cout << "degree = " << getDegree(nodeArray, i) << ", ";
	std::cout << "depth = " << getDepth(nodeArray, i) << ", ";
	std::cout << "height = " << getHeight(nodeArray, i) << ", ";
	std::cout << getType(nodeArray, i);
	std::cout << std::endl;
    }
}
int main()
{
    int n = 0;
    std::cin >> n;
    Node* nodeArray = (Node*)malloc(n * sizeof(Node));
    for (int i = 0; i < n; i++) {
	nodeArray[i].parent = NIL;
	nodeArray[i].left = NIL;
	nodeArray[i].right = NIL;
    }
    for (int i = 0; i < n; i++) {
	int index, left, right;
	std::cin >> index;
	std::cin >> left;
	std::cin >> right;
	nodeArray[left].parent = index;
	nodeArray[right].parent = index;
	nodeArray[index].left = left;
	nodeArray[index].right = right;
    }
    printNode(nodeArray, n);
}
