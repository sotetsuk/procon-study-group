#include <vector>
#include <stack>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

#include <typeinfo>

using namespace std;

struct Node
{
	int key;
	Node *parent, *left, *right;
};
Node *root,*NIL;

// print in preorder
void preorder(Node *T_1){
	if(T_1 == NIL){
		return;
	}
	cout << " " << T_1->key;
	preorder(T_1->left);
	preorder(T_1->right);
}

// print in inorder
void inorder(Node *T_1){
	if(T_1 == NIL){
		return;
	}
	inorder(T_1->left);
	cout << " " << T_1->key;
	inorder(T_1->right);
}

// insert node
void insert(int k){
	Node *y = NIL;
	Node *x = root;
	Node *z;

	z = (Node *)malloc(sizeof(Node));
	z->key = k;
	z->left = NIL;
	z->right = NIL;
	//cout << endl;

	while( x!= NIL){
		//cout << "aa " << endl;
		y = x;
		if(z -> key < x->key){
			x = x->left;
		}
		else{
			x = x->right;
		}
	}
	z->parent = y;

	if(y == NIL){
		root = z;
	}
	else{
		if(z->key < y->key){
			y->left = z;
		}
		else{
			y->right = z;
		}
	}

}

// honest recursive search leads to TimeLimitExceeding
bool find_flg = false;
void find_recursive(Node *x,int k){
	if(find_flg == true || x == NIL) return;
	if(x->key == k){
		find_flg = true;
		return;
	}
	find_recursive(x->left,k);
	find_recursive(x->right,k);
}

// finding node
Node *find_tree(Node *x, int k){
	while(x != NIL && k != x->key){
		if(k < x->key) x = x->left;
		else x = x->right;
	}
	return x;
}

// find a leftmost child
Node *treeMinimum(Node *target){
	while(target->left != NIL){
		target = target->left;
	}
	return target;
}

// find a next successor
Node *get_treeSuccessor(Node *target){
	// check if the target has a right child (this must be true in the task of delete_tree)
	if(target->right != NIL){
		return treeMinimum(target->right);
	}
	cout << "this must not be shown" << endl;
	// ignore at the task of delete_tree
	Node *parent = target->parent;
	while(parent != NIL && target == parent->right){
		target = parent;
		parent = parent->parent;
	}
	return parent;
}

// delete node
void delete_tree(int k){
	Node *target = find_tree(root,k);
	Node *removing;
	Node *child;
	// check if tree includes k
	if(target == NIL){
		cout << "cannot delete:" << k << endl;
		return;
	}
	// decide which node will be removed explicitly
	// if the target has at most 1 child, remove the target
	// else, remove Successor of the target
	else if(target->left == NIL || target->right == NIL)
		removing = target;
	else{
		removing = get_treeSuccessor(target);
		//cout << removing->key << endl;
	}


	// define a transferred child of the removing node
	// if removing node has a left child (Not NIL), it is the child
	// else, a right child (including NIL) is the child
	if(removing->left != NIL)
		child = removing->left;
	else
		child = removing->right;

	// set the parent of the transferred child
	if(child != NIL)
		child->parent = removing->parent;

	// set the root of the tree or the child of the parent of removing node
	if(removing->parent == NIL)
		root = child;
	else if(removing == removing->parent->left)
		removing->parent->left = child;
	else
		removing->parent->right = child;


	if(target != removing)
		target->key = removing->key;

	// delete removing node
	free(removing);
}

// implementation of binary search tree
void binary_search_tree(){
	int n,k;
	Node *ans;
	string com;
	cin >> n;

	for(int i = 0; i < n; i++){
		cin >> com;
		if(com == "insert"){
			cin >> k;
			//cout << typeid(k).name() << endl;
			insert(k);
		}
		else if(com == "print"){
			inorder(root);
			cout << endl;
			preorder(root);
			cout << endl;
		}
		else if(com == "find"){
			cin >> k;
			ans = find_tree(root,k);
			if(ans != NIL){
				cout << "yes";
				//find_flg = false;
				cout << endl;
			}
			else{
				cout << "no";
				cout << endl;
			}
		}
		else if(com == "delete"){
			cin >> k;
			delete_tree(k);
		}

	}
}

int main(){
	binary_search_tree();
	return 0;
}




