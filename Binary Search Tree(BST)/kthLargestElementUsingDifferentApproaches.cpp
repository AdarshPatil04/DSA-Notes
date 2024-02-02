/**
 * @file
 * This file contains code to find the kth largest element in a binary tree using different approaches.
 * It includes three approaches:
 * 1. Using reverse inorder traversal-> Time Complexity: O(n), Space Complexity: O(n)
 * 2. Using reverse inorder traversal by n-k+1 approach -> Time Complexity: O(n), Space Complexity: O(n)
 * 3. Using Morris Traversal -> Time Complexity: O(n), Space Complexity: O(1)
 * The main function constructs a binary tree and finds the kth largest element in it.
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

// Approach 1: Using reverse inorder traversal by n-k+1 approach
// Recursive function to find the kth largest element in the binary tree
int solve(Node *root, int &i, int k)
{
    // base case: if the node is null, return -1
    if (root == NULL)
    {
        return -1;
    }

    // Recursively call the function on the right subtree
    int right = solve(root->right, i, k);

    // If the right subtree has returned a non-negative value, return it
    if (right != -1)
    {
        return right;
    }

    // Increment the counter
    i++;

    // If the counter equals k, return the data of the current node
    if (i == k)
    {
        return root->data;
    }

    // Recursively call the function on the left subtree
    return solve(root->left, i, k);
}

// Function to find the kth largest element in the binary tree
int kthLargest(Node *root, int k)
{
    // Initialize the counter to 0
    int i = 0;

    // Call the recursive function and store the result in ans
    int ans = solve(root, i, k);

    // Return the result
    return ans;
}

// Approach 2: Using reverse inorder traversal
/*
// Function to count the total number of nodes in the binary tree
int countNodes(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

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

// Function to find the kth largest element in the binary tree
int kthLargest(Node *root, int k)
{
    // Count the total number of nodes in the binary tree
    int n = countNodes(root);

    // Initialize the counter to 0
    int i = 0;

    // Call the recursive function and store the result in ans
    int ans = solve(root, i, n - k + 1);

    // Return the result
    return ans;
}
* /

// Approach 3: Using Morris Traversal
/*
// Function to find the kth largest element in the binary tree using Morris Traversal
int kthLargest(Node *root, int k)
{
    Node *curr = root;
    Node *pre;
    int count = 0;
    while (curr != NULL)
    {
        if (curr->right == NULL)
        {
            count++;
            if (count == k)
                return curr->data;
            curr = curr->left;
        }
        else
        {
            pre = curr->right;
            while (pre->left != NULL && pre->left != curr)
                pre = pre->left;
            if (pre->left == NULL)
            {
                pre->left = curr;
                curr = curr->right;
            }
            else
            {
                pre->left = NULL;
                count++;
                if (count == k)
                    return curr->data;
                curr = curr->left;
            }
        }
    }
    return -1; // If k is more than the number of nodes in the binary tree
}
*/

int main()
{
    // Construct the binary tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Print the 3rd largest element in the binary tree
    cout << kthLargest(root, 3);

    return 0;
}