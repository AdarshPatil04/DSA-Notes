/**
 * @file diameterOfBinaryTree.cpp
 * @brief This file contains the implementation of finding the diameter of a binary tree.
 * Time Complexity: O(n^2)
 * The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.
 * This code calculates the diameter of a binary tree by recursively calculating the diameters of the left and right subtrees,
 * and comparing them with the sum of the heights of the left and right subtrees plus 1.
 * The height of a binary tree is calculated by recursively finding the maximum height of the left and right subtrees.
 * 
 * Example usage:
 *     Node *root = new Node(1);
 *     root->left = new Node(2);
 *     root->right = new Node(3);
 *     root->left->left = new Node(4);
 *     root->left->right = new Node(5);
 *     root->left->right->right = new Node(6);
 *     root->left->right->right->right = new Node(7);
 *     cout << diameter(root);
 */
#include <bits/stdc++.h>
using namespace std;

// Node structure
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

// Function to find the height of a binary tree.
int height(Node *node)
{
    // Base case: If the node is NULL, return 0
    if (node == NULL)
    {
        return 0;
    }

    // Recursive case: Calculate the height of the left and right subtrees
    int left = height(node->left);
    int right = height(node->right);

    // The height of the tree is the maximum height of the left and right subtrees plus 1
    int ans = max(left, right) + 1;
    return ans;
}

// Function to return the diameter of a Binary Tree.
int diameter(Node *root)
{
    // Base case: If the root is NULL, return 0
    if (root == NULL)
    {
        return 0;
    }

    // Recursive case: Calculate the diameters of the left and right subtrees
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);

    // The diameter of the tree is the maximum of the diameters of the left and right subtrees and the sum of the heights of the left and right subtrees plus 1
    int op3 = height(root->left) + height(root->right) + 1;
    int ans = max(op1, max(op2, op3));
    return ans;
}

// Main function
int main(){
    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Printing the diameter of the binary tree
    cout << diameter(root);
    return 0;
}
