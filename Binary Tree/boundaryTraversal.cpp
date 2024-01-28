/**
 * @file boundaryTraversal.cpp
 * @brief This file contains the implementation of a boundary traversal algorithm for a binary tree.
 *
 * The boundary traversal of a binary tree involves traversing the left boundary, leaf nodes, and right boundary of the tree.
 * The algorithm uses three separate functions to traverse the left boundary, leaf nodes, and right boundary of the tree.
 * The result of the boundary traversal is stored in a vector and returned as the output.
 *
 * The main function creates a binary tree and performs the boundary traversal, printing the result to the console.
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

// Function to traverse the left boundary of the tree
void traverseLeft(Node *root, vector<int> &ans)
{
    // Base case: if the node is null or a leaf node, return
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    // Add the node's data to the answer vector
    ans.push_back(root->data);

    // Recursively traverse the left child if it exists, otherwise the right child
    if (root->left)
        traverseLeft(root->left, ans);
    else
        traverseLeft(root->right, ans);
}

// Function to traverse the leaf nodes of the tree
void traverseLeaf(Node *root, vector<int> &ans)
{
    // Base case: if the node is null, return
    if (root == NULL)
        return;

    // If the node is a leaf node, add its data to the answer vector
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    // Recursively traverse the left and right children
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}

// Function to traverse the right boundary of the tree
void traverseRight(Node *root, vector<int> &ans)
{
    // Base case: if the node is null or a leaf node, return
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    // Recursively traverse the right child if it exists, otherwise the left child
    if (root->right)
        traverseRight(root->right, ans);
    else
        traverseRight(root->left, ans);

    // Add the node's data to the answer vector
    ans.push_back(root->data);
}

// Function to perform a boundary traversal of the tree
vector<int> boundary(Node *root)
{
    vector<int> ans;

    // If the root is null, return an empty vector
    if (root == NULL)
        return ans;

    // Add the root's data to the answer vector
    ans.push_back(root->data);

    // Traverse the left boundary, leaf nodes, and right boundary
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);  // Traverse the left subtree
    traverseLeaf(root->right, ans); // Traverse the right subtree
    traverseRight(root->right, ans);

    return ans;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    cout << "Boundary traversal of the binary tree: ";
    vector<int> ans = boundary(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
