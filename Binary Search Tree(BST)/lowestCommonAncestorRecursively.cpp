/**
 * Time Complexity: O(h)
 * Space Complexity: O(h)
 * @file lowestCommonAncestorRecursively.cpp
 * @brief This file contains the implementation of finding the lowest common ancestor of two nodes in a binary search tree recursively.
 *
 * The code constructs a binary search tree and defines two nodes for which to find the lowest common ancestor.
 * It then uses a recursive function to find the lowest common ancestor of the given nodes in the binary search tree.
 * The lowest common ancestor is the deepest node that has both given nodes as descendants.
 * The code outputs the data of the lowest common ancestor.
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
Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    // If the root is NULL, return NULL
    if (root == NULL)
    {
        return NULL;
    }

    // If the root's data is less than both p's and q's data,
    // then the lowest common ancestor must be in the right subtree
    if (root->data < p->data && root->data < q->data)
    {
        return lowestCommonAncestor(root->right, p, q);
    }

    // If the root's data is greater than both p's and q's data,
    // then the lowest common ancestor must be in the left subtree
    if (root->data > p->data && root->data > q->data)
    {
        return lowestCommonAncestor(root->left, p, q);
    }

    // If neither of the above conditions are true, then the root must be the lowest common ancestor
    return root;
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
