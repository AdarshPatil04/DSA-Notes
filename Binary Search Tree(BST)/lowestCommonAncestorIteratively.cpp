/**
 * Time Complexity: O(h)
 * Space Complexity: O(1)
 * @file lowestCommonAncestorIteratively.cpp
 * @brief This file contains the implementation of finding the lowest common ancestor of two nodes in a binary search tree iteratively.
 *
 * The lowest common ancestor (LCA) of two nodes P and Q in a binary search tree is the deepest node that has both P and Q as descendants.
 * This code provides an iterative solution to find the LCA of two nodes in a binary search tree.
 *
 * The main function constructs a binary search tree and defines two nodes for which to find the LCA.
 * It then calls the lowestCommonAncestor function to find the LCA and prints its data.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class to represent each node in the binary search tree
class Node
{
public:
    int data;    // data of the node
    Node *left;  // pointer to the left child
    Node *right; // pointer to the right child

    // constructor to initialize a new node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to find the lowest common ancestor of two nodes in the binary search tree
Node *lowestCommonAncestor(Node *root, Node *P, Node *Q)
{
    // iterative solution
    // while the root is not NULL
    while (root != NULL)
    {
        // if the root's data is greater than both P's and Q's data
        // then the lowest common ancestor must be in the left subtree
        if (root->data > P->data && root->data > Q->data)
            root = root->left;

        // if the root's data is less than both P's and Q's data
        // then the lowest common ancestor must be in the right subtree
        else if (root->data < P->data && root->data < Q->data)
            root = root->right;

        // if neither of the above conditions are true
        // then the root must be the lowest common ancestor
        else
            return root;
    }
}

int main()
{
    // Construct the binary search tree
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    // Define the two nodes for which to find the lowest common ancestor
    Node *p = new Node(2);
    Node *q = new Node(8);

    // Find the lowest common ancestor and print its data
    cout << "The lowest common ancestor of " << p->data << " and " << q->data << " is: " << lowestCommonAncestor(root, p, q)->data;

    return 0;
}
