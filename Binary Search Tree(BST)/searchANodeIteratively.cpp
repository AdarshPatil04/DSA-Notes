/**
 * Time complexity: O(n)
 * Space complexity: O(1) because of iterative approach
 * @brief This program demonstrates the iterative search of a key in a Binary Search Tree (BST).
 * 
 * The program defines a Node class to represent a node in the BST. It implements a searchInBST function
 * that takes the root of the BST and a key as input and searches for the key in the BST iteratively.
 * If the key is found, it returns true; otherwise, it returns false.
 * 
 * The main function constructs a binary tree, takes input for the key to be searched, and calls the
 * searchInBST function. If the key is found, it prints "Found"; otherwise, it prints "Not Found".
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

// Function to search a key in a Binary Search Tree (BST) iteratively
bool searchInBST(Node* root, int key) {
    while(root != NULL) {
        // If the root's data is equal to the key, the key is found
        if(root->data == key) {
            return true;
        }
        // If the key is less than the root's data, move to the left subtree
        else if(key < root->data) {
            root = root->left;
        }
        // If the key is greater than the root's data, move to the right subtree
        else {
            root = root->right;
        }
    }
    // If the tree is empty or the key is not found, return false
    return false;
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
