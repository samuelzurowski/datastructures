#pragma once
#include <queue>
#include <iostream>
using namespace std;

enum Color {RED, BLACK}; // bool for color red = 0 black = 1;

// nodes
template<class T>
struct Node 
{ 
	T data; 
	bool color; 
	Node *left, *right, *parent; 
	Node(T data): data{data}, left{nullptr}, right{nullptr}, parent{nullptr} {} 
}; 

// Class to represent Red-Black Tree 
template<class T>
class RBTree { 
private: 
	Node<T> *root = nullptr; 

    // function to insert into the RBT checks value
	Node<T>* BSTInsert(Node<T>* root, Node<T>* p) {
		if(root == nullptr) return p;

		if(p->data < root->data) {
			root->left = BSTInsert(root->left, p);
			root->left->parent = root;
		}
		else if(p->data > root->data ) {
			root->right = BSTInsert(root->right, p);
			root->right->parent = root;
		}
		return root;
	}

    // fix problems with the rbt
	void fixProblem(Node<T> *&root, Node<T> *&pt) { 
		Node<T> *p = nullptr; 
		Node<T> *g = nullptr; 

		while ((pt != root) && (pt->color != BLACK) && 
			(pt->parent->color == RED)) { 

			p = pt->parent; 
			g = pt->parent->parent; 
			// parent of pt is left of child of grand
			if (p == g->left) { 
				Node<T> *u = g->right; 
				// uncle pt red recolor
				if (u != nullptr && u->color == RED) { 
					g->color = RED; 
					p->color = BLACK; 
					u->color = BLACK; 
					pt = g; 
				} 
				else { // pt right child parent left rotation
					if (pt == p->right) { 
						rotLeft(root, p); 
						pt = p; 
						p = pt->parent; 
					} // pt left child parent, right rotate
					rotRight(root, g); 
					swap(p->color, g->color); 
					pt = p; 
				} 
			} 
			// parent pt is right of child grand
			else { 
				Node<T> *u = g->left; 
				// uncle is pt of red recolor
				if ((u != nullptr) && (u->color == RED)) { 
					g->color = RED; 
					p->color = BLACK; 
					u->color = BLACK; 
					pt = g; 
				} 
				else { // pt is left child of parent right rot
					if (pt == p->left) { 
						rotRight(root, p); 
						pt = p; 
						p = pt->parent; 
					} // pt is right of child of parent left rot
					rotLeft(root, g); 
					swap(p->color, g->color); 
					pt = p; 
				} 
			} 
		} 
		root->color = BLACK; 
	} 

    //do left rotation
	void rotLeft(Node<T> *&root, Node<T> *&pt) { 
		Node<T> *pRight = pt->right; 

		pt->right = pRight->left; 

		if (pt->right != nullptr) pt->right->parent = pt; 

		pRight->parent = pt->parent; 

		if (pt->parent == nullptr) root = pRight; 
		else if (pt == pt->parent->left) pt->parent->left = pRight; 
		else pt->parent->right = pRight; 

		pRight->left = pt; 
		pt->parent = pRight; 
	} 

    // do right rotation
	void rotRight(Node<T> *&root, Node<T> *&pt) { 
		Node<T> *pLeft = pt->left; 

		pt->left = pLeft->right; 

		if (pt->left != nullptr) pt->left->parent = pt; 

		pLeft->parent = pt->parent; 

		if (pt->parent == nullptr) root = pLeft; 
		else if (pt == pt->parent->left) pt->parent->left = pLeft; 
		else pt->parent->right = pLeft; 

		pLeft->right = pt; 
		pt->parent = pLeft; 
	} 

    // print in order 
	void inOrderPrint(Node<T> *root) {
		if(root == nullptr) return;

		inOrderPrint(root->left);
		cout << root->data << ' ';
		inOrderPrint(root->right);
	}

    // prints level order using a queue.
	void levelOrderPrint(Node<T> *root) {
		if(root == nullptr) return;

		queue<Node<T> *> q;
		q.push(root);

		while(!q.empty()) {
			Node<T>* var = q.front();
			cout << var->data << ' ';

			q.pop();

			if(var->left != nullptr) q.push(var->left);
			if(var->right != nullptr) q.push(var->right);
		}
	}

public:  
	RBTree() = default;
	// Function to insert a new node with given data 
	void insert(T data) { 
		Node<T> *p = new Node<T>(data); 

		// Do a normal BST insert 
		root = BSTInsert(root, p); 

		// fix Red Black Tree violations 
		fixProblem(root, p); 
	} 
	void inOrder() {inOrderPrint(root); }
	void levelOrder() { levelOrderPrint(root); }
}; 