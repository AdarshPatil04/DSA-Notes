/**
 * @file
 * @brief This file contains the implementation of finding the minimum and maximum values in a Binary Search Tree (BST).
 * 
 * The code constructs a BST and then finds the minimum and maximum values in the BST using iterative approaches.
 * It defines a Node class to represent each node in the BST and provides functions to find the minimum and maximum values.
 * The main function creates a BST, finds the minimum and maximum values, and prints them.
 */
#include <iostream>
#include <queue>
using namespace std;

// Node class to represent each node in the Binary Search Tree (BST)
class Node
{
public:
    int data;    // data of the node
    Node *left;  // pointer to the left child node
    Node *right; // pointer to the right child node

    // Node constructor
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to find the node with the minimum value in a BST
Node *minValue(Node *root)
{
    Node *temp = root;

    // Traverse to the leftmost leaf node
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp; // Return the leftmost leaf node
}

// Function to find the node with the maximum value in a BST
Node *maxValue(Node *root)
{
    Node *temp = root;

    // Traverse to the rightmost leaf node
    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp; // Return the rightmost leaf node
}

// Main function
int main()
{
    // Constructing the BST
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    // Printing the minimum and maximum values in the BST
    cout << "Minimum value in the BST: " << minValue(root)->data << endl;
    cout << "Maximum value in the BST: " << maxValue(root)->data << endl;

    return 0;
}
