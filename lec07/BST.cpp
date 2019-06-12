#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;

    Node(int key): 
        key{key},
        left{nullptr},
        right{nullptr} {}
};

class BST
{
private:
    Node *root;

public:
    BST():root{nullptr}{}

    // Get Minimum given some node
    Node* Min(Node *node){
        if (node == nullptr)
            throw "EmptyTree";
        if (node->left == nullptr)
            return node;

        return Min(node->left);
    }

    // Get Minimum of tree
    Node* Min(){
        return Min(root);
    }

    // Get Maximum given some node
    Node* Max(Node *node){
        if (node == nullptr)
            throw "EmptyTree";
        if (node->right == nullptr)
            return node;

        return Max(node->right);
    }

    // Get maximum of tree
    Node* Max(){
        return Max(root);
    }

    // Insert helper method
    void Insert(Node*& node, int key){
        if(node == nullptr){
            node = new Node(key); 
        }
        else if(key < node->key){
            Insert(node->left, key); 
        }else{
            Insert(node->right, key); 
        }
    }
    // Insert into tree
    void Insert(int key){
        Insert(root, key); 
    }

    // Insert a vector of keys
    void BulkInsert(vector<int> keys){
        for(auto key : keys){
            Insert(key); 
        }
    }

    // Find a key given some root node
    Node* Find(Node* node, int key){     
        if(node == nullptr) return nullptr;
        if(node->key == key) return node; 
        if(key < node->key) return Find(node->left, key); 
        return Find(node->right, key);
    }

    // Find a key starting at root
    Node* Find(int key){
        return Find(root, key);
    }

    // Delete a node
    void DeleteNode(Node*& root){
        Node* temp = root; 
        if(root->left == nullptr){
            root = root->right; 
            delete temp;
        }
        else if(root->right == nullptr){
            root = root->left; 
            delete temp;
        }
        else{
            // Get rightmost element in left subtree
            Node* max = Max(root->left); 
            root->key = max->key; 
            Delete(root->left, max->key);
        }
    }

    // Find and delete a node with given ke
    void Delete(Node*& root, int key){
        if(key < root->key)
            Delete(root->left, key);
        else if(key > root->key)
            Delete(root->right, key);
        else
            DeleteNode(root);
        
    }

    // Delete tree node with specified key
    void Delete(int key){
        Delete(this->root, key); 
    }

    // InOrder traversal (get items in sorted order)
    void Inorder(Node*& node){
        if(node == nullptr) return;

        Inorder(node->left);
        cout << "[" << node->key << "]";
        Inorder(node->right);
    }

    // InOrder traversal (get items in sorted order)
    void Inorder(){
        Inorder(root);
        cout << endl;
    }

    // Destruction of tree is done via post-order
    void DestroyTree(Node* root, int level){
        if(root != nullptr){
            DestroyTree(root->left, level+1);
            DestroyTree(root->right, level+1);
            //cout << "Deleting: " << root->key << endl;
            for(int i = 0; i < level; ++i){
                cout << '\t'; 
            }
            cout << "Deleting " << root->key << endl;
            delete root; 
        }
    }

    // Destroy tree
    void DestroyTree(){
        DestroyTree(root, 0);
    }

    // Make a copy of a tree (Preorder)
    void CopyTree(Node*& copy, Node* orig){
        if(orig == nullptr){
            copy = nullptr;
        }else{
            copy = new Node(orig->key);
            CopyTree(copy->left, orig->left);
            CopyTree(copy->right, orig->right);
        }
    }

    // Copy Constructor
    BST(const BST& orig){
        CopyTree(root, orig.root);
    }

    // Copy Assignment
    void operator=(const BST& orig){
        if(&orig == this)
            return;

        DestroyTree(root, 0);
        CopyTree(root, orig.root);
    }

    ~BST() {
        DestroyTree(); 
    }
};

int main(void)
{
    vector<int>  nums = {4, 2, 6, 1, 3, 5, 7};
    BST tree;
    tree.BulkInsert(nums); 
    tree.Inorder();

    BST tree2 = tree; 
    tree2.Inorder();

    for(auto i : nums){
        tree.Delete(i); 
        tree.Inorder(); 
    }
    
    tree2.Inorder(); 
}