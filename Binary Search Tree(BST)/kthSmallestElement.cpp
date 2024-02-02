/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @file
 * @brief This file contains the implementation of finding the kth smallest element in a binary tree.
 *
 * The code defines a binary tree node structure and a recursive function to find the kth smallest element in the binary tree.
 * The main function constructs a binary tree and calls the kthSmallest function to find the kth smallest element.
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

// Recursive function to find the kth smallest element in the binary tree
int solve(Node *root, int &i, int k)
{
    // base case: if the node is null, return -1
    if (root == NULL)
    {
        return -1;
    }

    // Recursively call the function on the left subtree
    int left = solve(root->left, i, k);

    // If the left subtree has returned a non-negative value, return it
    if (left != -1)
    {
        return left;
    }

    // Increment the counter
    i++;

    // If the counter equals k, return the data of the current node
    if (i == k)
    {
        return root->data;
    }

    // Recursively call the function on the right subtree
    return solve(root->right, i, k);
}

// Function to find the kth smallest element in the binary tree
int kthSmallest(Node *root, int k)
{
    // Initialize the counter to 0
    int i = 0;

    // Call the recursive function and store the result in ans
    int ans = solve(root, i, k);

    // Return the result
    return ans;
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Print the 3rd smallest element in the binary tree
    cout << kthSmallest(root, 3);

    return 0;
}
