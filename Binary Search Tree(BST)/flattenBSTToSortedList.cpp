/**
 * @file flattenBSTToSortedList.cpp
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This file contains the implementation of a function to flatten a binary search tree (BST) into a sorted linked list.
 * The BST is flattened by performing an inorder traversal of the tree and storing the node values in a vector.
 * The vector is then used to construct a new linked list with the nodes arranged in sorted order.
 * The flattened linked list is printed using an inorder traversal.
 */

#include <bits/stdc++.h>
using namespace std;

// Define the structure of a Node in the binary tree
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

// Function to perform inorder traversal and store the node values in a vector
void inorder(Node *root, vector<int> &in)
{
    // Base case: if the node is null, return
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorder(root->left, in);

    // Store the node value in the vector
    in.push_back(root->data);

    // Traverse the right subtree
    inorder(root->right, in);
}

/**
 * @brief Flattens a binary search tree (BST) into a sorted linked list.
 * @param root The root of the BST.
 * @return The root of the flattened linked list.
 */
Node *flatten(Node *root)
{
    vector<int> v;

    // store inorder => sorted values
    inorder(root, v);
    int n = v.size();

    Node *newRoot = new Node(v[0]);

    // 2nd step
    Node *curr = newRoot;

    for (int i = 1; i < n; i++)
    {

        Node *temp = new Node(v[i]);

        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }

    // final step
    curr->left = NULL;
    curr->right = NULL;

    // returning ans
    return newRoot;
}

// Function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Flatten the binary tree
    Node *newRoot = flatten(root);

    // Print the inorder traversal of the flattened binary tree
    printInorder(newRoot);

    return 0;
}
