#include <iostream>
#define NIL -1
struct Node {
    int parent, left, right;
};
int getDepth(Node* nodeList, int index)
{
    int parent = nodeList[index].parent;
    int depth = 0;
    while (parent != NIL) {
	depth++;
	parent = nodeList[parent].parent;
    }
    return depth;
}
std::string getType(Node* node)
{
    if (node->parent == NIL) {
	return "root";
    } else if (node->left == NIL) {
	return "leaf";
    } else {
	return "internal node";
    }
}
std::string getChildList(Node* nodeList, int index)
{
    if (nodeList[index].left == NIL) {
	return "";
    }
    std::string childList = "";
    int child = nodeList[index].left;
    while (child != NIL) {
	childList += std::to_string(child);
	child = nodeList[child].right;
	if (child != NIL) {
	    childList += ", ";
	}
    }
    return childList;
}

void print(Node* nodeList, int n)
{
    for (int i = 0; i < n; i++) {
	std::cout << "node " << i << ": ";
	std::cout << "parent = " << nodeList[i].parent << ", ";
	std::cout << "depth = " << getDepth(nodeList, i) << ", ";
	std::cout << getType(&nodeList[i]) << ", ";
	std::cout << "[" << getChildList(nodeList, i) << "]";
	std::cout << std::endl;
    }
}

Node* setNode(int index, int childNum, int* childList, Node* nodeList)
{
    for (int i = 0; i < childNum; i++) {
	nodeList[childList[i]].parent = index;
	if (i + 1 < childNum) {
	    nodeList[childList[i]].right = childList[i + 1];
	}
    }
    if (childNum > 0) {
	nodeList[index].left = childList[0];
    }
    return nodeList;
}
int main()
{
    int n;
    std::cin >> n;
    Node* nodeList = (Node*)malloc(n * sizeof(Node));
    //初期化
    for (int i = 0; i < n; i++) {
	nodeList[i].parent = NIL;
	nodeList[i].left = NIL;
	nodeList[i].right = NIL;
    }

    for (int i = 0; i < n; i++) {
	int index;
	int childNum;
	int* childList;
	std::cin >> index;
	std::cin >> childNum;
	childList = (int*)malloc(childNum * sizeof(int));
	for (int i = 0; i < childNum; i++) {
	    std::cin >> childList[i];
	}
	nodeList = setNode(index, childNum, childList, nodeList);
    }
    print(nodeList, n);
}
