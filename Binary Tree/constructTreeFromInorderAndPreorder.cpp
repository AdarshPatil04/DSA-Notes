/**
 * Time Complexity: O(nlogn) because we are using map with logn access time inside a for loop with O(n)
 * Space Complexity: O(n) because we are using map with O(n) space and recursion stack with O(n) space
 * @brief This code demonstrates how to construct a binary tree from its inorder and preorder traversals.
 * 
 * The code defines a Node class to represent a node in the binary tree. It also includes functions to create a mapping from node data to its index in the inorder traversal, and to recursively construct the binary tree using the inorder and preorder traversals.
 * 
 * The main function builds the tree from the given inorder and preorder arrays, and performs a postorder traversal on the constructed tree.
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

// Function to create a mapping from node data to its index in the inorder traversal, using map for O(1) access
void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

// Recursive function to construct the binary tree from inorder and preorder traversals
Node *solve(int in[], int pre[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    // Base case: if the current subarray of inorder traversal is empty, return NULL
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // The current element in preorder traversal is the root of the current subtree
    int element = pre[index--];
    Node *root = new Node(element);
    // Find the position of the root in inorder traversal
    int position = nodeToIndex[element];
    // Construct the left and right subtrees
    root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex); // Note that the right subtree is constructed first because the preorder traversal is root, left, right
    root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    // Return the root of the current subtree
    return root;
}

// Function to build the tree from inorder and preorder traversals
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = n-1; // Start from the end of the preorder array
    map<int, int> nodeToIndex;
    // Create a mapping from node data to its index in inorder traversal
    createMapping(in, nodeToIndex, n);
    // Construct the tree and return its root
    Node *ans = solve(in, pre, preOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

// Function to perform postorder traversal of the binary tree
void postorder(Node *root)
{
    // Base case: If root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // Recursive case: Perform postorder traversal on the left subtree, perform postorder traversal on the right subtree, and then print the data of the node
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int n = 5;
    int in[n] = {4, 2, 5, 1, 3};
    int pre[n] = {1, 2, 4, 5, 3};
    // Build the tree from inorder and preorder traversals
    Node *root = buildTree(in, pre, n);
    // Perform postorder traversal on the constructed tree
    postorder(root);
    return 0;
}
