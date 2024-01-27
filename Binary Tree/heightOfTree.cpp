/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @file heightOfTree.cpp
 * @brief This file contains the implementation of a solution to find the height of a binary tree.
 *
 * The height of a binary tree is defined as the maximum number of edges in any path from the root node to a leaf node.
 * This code defines a Node structure and a Solution class with a height() function that calculates the height of a binary tree recursively.
 * The main function creates a binary tree and prints its height.
 */
#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    int data;           // Data to be stored in the node
    struct Node *left;  // Pointer to the left child node
    struct Node *right; // Pointer to the right child node

    // Constructor to initialize a new node
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

// Solution class
class Solution
{
public:
    // Function to find the height of a binary tree.
    int height(struct Node *node)
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
};

// Main function
int main()
{
    // Creating an object of the Solution class
    Solution s;

    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Printing the height of the binary tree
    cout << "Height of tree is " << s.height(root);
    return 0;
}
