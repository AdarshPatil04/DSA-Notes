/**
 * Time Complexity: O(h)
 * Space Complexity: O(n)
 * This code demonstrates how to find the predecessor and successor of a given node in a binary search tree (BST) using recursion.
 * It defines a Node class to represent each node in the BST and provides functions to find the minimum and maximum value nodes in a tree/subtree.
 * The findPredecessor function finds the predecessor of a given node by finding the maximum value node in its left subtree.
 * The findSuccessor function finds the successor of a given node by finding the minimum value node in its right subtree.
 * The printInorder function prints the inorder traversal of the binary tree.
 * The main function constructs a binary tree, prints its inorder traversal, and finds the predecessor and successor of a given node.
 */
#include <iostream>
#include <queue>
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

// Function to find the node with the minimum value in a given tree/subtree
Node *minValue(Node *root)
{
    Node *temp = root;

    // Go to the leftmost node
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// Function to find the node with the maximum value in a given tree/subtree
Node *maxValue(Node *root)
{
    Node *temp = root;

    // Go to the rightmost node
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp;
}

// Function to find the predecessor of a node
void findPredecessor(Node *root, Node *&pred, int x)
{
    // base case
    if (root == NULL)
        return;

    // If the node is found, the predecessor is the maximum value node of its left subtree
    if (root->data == x)
    {
        if (root->left != NULL)
        {
            pred = maxValue(root->left);
        }
    }
    else if (x < root->data)
    {
        // If the given value is less than the root's data, go to the left subtree
        findPredecessor(root->left, pred, x);
    }
    else
    {
        // If the given value is more than the root's data, update the predecessor and go to the right subtree
        pred = root;
        findPredecessor(root->right, pred, x);
    }
    return;
}

// Function to find the successor of a node
void findSuccessor(Node *root, Node *&succ, int x)
{
    // base case
    if (root == NULL)
        return;

    // If the node is found, the successor is the minimum value node of its right subtree
    if (root->data == x)
    {
        if (root->right != NULL)
        {
            succ = minValue(root->right);
        }
    }
    else if (x < root->data)
    {
        // If the given value is less than the root's data, update the successor and go to the left subtree
        succ = root;
        findSuccessor(root->left, succ, x);
    }
    else
    {
        // If the given value is more than the root's data, go to the right subtree
        findSuccessor(root->right, succ, x);
    }

    return;
}

// Function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);  // visit left subtree
    cout << root->data << " "; // print data of root
    printInorder(root->right); // visit right subtree
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(15);
    root->left = new Node(10);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right = new Node(20);
    root->right->left = new Node(16);
    root->right->right = new Node(25);

    // Print the inorder traversal of the tree
    printInorder(root);
    cout << endl;

    int x = 16;
    Node *pred = NULL;
    Node *succ = NULL;

    // Find and print the predecessor of x
    findPredecessor(root, pred, x);
    if (pred != NULL)
    {
        cout << "Predecessor of " << x << " is " << pred->data << endl;
    }
    else
    {
        cout << "Predecessor doesn't exist" << endl;
    }

    // Find and print the successor of x
    findSuccessor(root, succ, x);
    if (succ != NULL)
    {
        cout << "Successor of " << x << " is " << succ->data << endl;
    }
    else
    {
        cout << "Successor doesn't exist" << endl;
    }

    return 0;
}
