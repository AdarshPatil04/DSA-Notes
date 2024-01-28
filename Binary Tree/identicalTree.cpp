/**
 * @file identicalTree.cpp
 * @brief This file contains the implementation of a function to check if two binary trees are identical.
 * 
 * The code defines a Node structure to represent a node in a binary tree. It also defines a function
 * isIdentical() that takes two binary trees as input and checks if they are identical. The function
 * recursively compares the nodes of the trees and their data values to determine if they are identical.
 * The main() function creates two binary trees and calls the isIdentical() function to check if they
 * are identical. The result is printed to the console.
 */
#include <bits/stdc++.h>
using namespace std;

// Define the structure of a node in the binary tree
class Node
{
public:
    int data;    // Data to be stored in the node
    Node *left;  // Pointer to the left child node
    Node *right; // Pointer to the right child node

    // Constructor to initialize a new node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to check if two binary trees are identical
bool isIdentical(Node *r1, Node *r2)
{
    // Base cases: if both nodes are null, they are identical
    if(r1 == NULL && r2 == NULL) {
        return true;
    }
    
    // If one node is null and the other is not, they are not identical
    if(r1 == NULL && r2 != NULL) {
        return false;
    }
    
    if(r1 != NULL && r2 == NULL) {
        return false;
    }
    
    // Recursively check if the left and right subtrees are identical
    bool left = isIdentical(r1->left, r2->left);
    bool right = isIdentical(r1->right, r2->right);
    
    // Check if the data in the nodes are identical
    bool value = r1->data == r2->data;
    
    // If the left and right subtrees are identical and the data in the nodes are identical, the trees are identical
    if(left && right && value) {
        return true;
    }
    else
    {
        return false;
    }
}

// Main function
int main()
{
    // Create two binary trees
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->right = new Node(3);

    // Print whether the trees are identical or not
    cout << "Are the trees identical? " << (isIdentical(root1, root2) ? "Yes" : "No") << endl;
    return 0;
}
