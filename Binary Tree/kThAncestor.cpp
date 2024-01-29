/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This code implements a function to find the kth ancestor of a given node in a binary tree.
 * 
 * The code defines a binary tree node structure and a function `kthAncestor` that takes the root of the binary tree,
 * the value of k, and the value of the node for which we want to find the kth ancestor. The function recursively
 * traverses the binary tree to find the kth ancestor of the given node and returns the value of the ancestor node.
 * If the kth ancestor does not exist, the function returns -1.
 * 
 * Example usage:
 * 
 * Node *root = new Node(1);
 * root->left = new Node(2);
 * root->right = new Node(3);
 * int k = 1;
 * int node = 3;
 * cout << kthAncestor(root, k, node); // Output: 1
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

// Function to solve the problem
Node *solve(Node *root, int &k, int node)
{
    // Base case: if the node is NULL, return NULL
    if (root == NULL)
        return NULL;

    // If the current node's data is equal to the given node, return the current node
    if (root->data == node)
    {
        return root;
    }

    // Recursively call the solve function for the left child of the current node
    Node *leftAns = solve(root->left, k, node);

    // Recursively call the solve function for the right child of the current node
    Node *rightAns = solve(root->right, k, node);

    // If the left child is not NULL and the right child is NULL
    if (leftAns != NULL && rightAns == NULL)
    {
        // Decrement k
        k--;
        // If k is less than or equal to 0
        if (k <= 0)
        {
            // Lock the answer and return the current node
            k = INT_MAX;
            return root;
        }
        // Otherwise, return the left child
        return leftAns;
    }

    // If the left child is NULL and the right child is not NULL
    if (leftAns == NULL && rightAns != NULL)
    {
        // Decrement k
        k--;
        // If k is less than or equal to 0
        if (k <= 0)
        {
            // Lock the answer and return the current node
            k = INT_MAX;
            return root;
        }
        // Otherwise, return the right child
        return rightAns;
    }
    // If both children are NULL, return NULL
    return NULL;
}

// Function to find the kth ancestor of a given node
int kthAncestor(Node *root, int k, int node)
{
    // Call the solve function and store the result in ans
    Node *ans = solve(root, k, node);
    // If ans is NULL or ans's data is equal to the given node, return -1
    if (ans == NULL || ans->data == node)
        return -1;
    // Otherwise, return ans's data
    else
        return ans->data;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    int k = 1;
    int node = 3;
    cout << kthAncestor(root, k, node);
    return 0;
}
