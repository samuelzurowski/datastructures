#include "RBT.hpp"
using namespace std; 

int main() { 
	RBTree<int> tree; 

	tree.insert(7); 
	tree.insert(6); 
	tree.insert(4); 
	tree.insert(5); 
	tree.insert(11);
	tree.insert(20);
	tree.insert(3); 
	tree.insert(1); 
	tree.insert(2); 

	cout << "In order of tree: " << endl;
	tree.inOrder();

	cout << "\nLevel order of tree: " << endl;
	tree.levelOrder();
	cout << endl;
	return 0; 
} 
