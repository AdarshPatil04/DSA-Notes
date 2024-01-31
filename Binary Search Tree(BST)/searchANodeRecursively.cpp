/**
 * Time complexity: O(n)
 * Space complexity: O(n) because we are using recursion stack
 * @brief This code demonstrates how to search for a node in a Binary Search Tree (BST) recursively.
 * 
 * The code defines a Node class and a function searchInBST() to search for a key in the BST.
 * The main() function constructs a binary tree, takes input for the key to be searched, and prints whether the key is found or not.
 */
#include<bits/stdc++.h>
using namespace std;

// Define the Node class
class Node
{
public:
    int data;    // Data to be stored in the Node
    Node *left;  // Pointer to the left child Node
    Node *right; // Pointer to the right child Node

    // Constructor to initialize a new Node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to search a key in a Binary Search Tree (BST)
bool searchInBST(Node* root, int key) {
    // If the tree is empty, the key is not found
    if(root == NULL) {
        return false;
    }
    // If the root's data is equal to the key, the key is found
    if(root->data == key) {
        return true;
    }
    // If the key is less than the root's data, search in the left subtree
    if(key < root->data) {
        return searchInBST(root->left, key);
    }
    // If the key is greater than the root's data, search in the right subtree
    else {
        return searchInBST(root->right, key);
    }
}

int main(){
    // Construct the binary tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Input the key to be searched
    int key;
    cin>>key;

    // If the key is found in the BST, print "Found"
    if(searchInBST(root, key)) {
        cout<<"Found"<<endl;
    }
    // If the key is not found in the BST, print "Not Found"
    else {
        cout<<"Not Found"<<endl;
    }
    return 0;
}
