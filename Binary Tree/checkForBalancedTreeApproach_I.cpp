/**
 * Time Complexity: O(n^2)
 * @brief This code demonstrates how to check if a binary tree is balanced.
 * 
 * The code defines a Node structure for the binary tree and implements functions to find the height of the tree and check if it is balanced.
 * The height of the tree is calculated recursively by finding the maximum height of the left and right subtrees.
 * The balance of the tree is determined by checking the difference in heights of the left and right subtrees.
 * If the difference is less than or equal to 1, the tree is considered balanced.
 * The main function creates a binary tree, prints its height, and checks if it is balanced.
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

// Function to check if a binary tree is balanced
bool isBalanced(Node *root)
{
    // If the node is null, it is balanced
    if (root == NULL)
    {
        return true;
    }

    // Check if the left subtree is balanced
    bool left = isBalanced(root->left);

    // Check if the right subtree is balanced
    bool right = isBalanced(root->right);

    // Check the difference in heights of left and right subtrees
    // If the difference is less than or equal to 1, it is balanced
    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    // If left subtree, right subtree and the current node (difference in heights)
    // are all balanced, then the tree is balanced
    if (left && right && diff)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Printing the height of the binary tree
    cout << "Height of tree is " << height(root) << endl;
    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;
    return 0;
}