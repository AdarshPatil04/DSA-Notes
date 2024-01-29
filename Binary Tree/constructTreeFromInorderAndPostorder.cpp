/**
 * @brief This program demonstrates the construction of a binary tree from its inorder and preorder traversals.
 *
 * The program defines a Node class to represent a node in the binary tree. It also includes functions to create a mapping from node data to its index in the inorder traversal,
 * recursively construct the binary tree from the inorder and preorder traversals, and perform postorder traversal of the binary tree.
 *
 * The main function initializes the inorder and preorder traversals of the tree, builds the tree using the buildTree function, and performs postorder traversal on the constructed tree.
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

// Function to create a mapping from node data to its index in the inorder traversal
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
    if (index >= n || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // The current element in preorder traversal is the root of the current subtree
    int element = pre[index++];
    Node *root = new Node(element);
    // Find the position of the root in inorder traversal
    int position = nodeToIndex[element];
    // Construct the left and right subtrees
    root->left = solve(in, pre, index, inOrderStart, position - 1, n, nodeToIndex);
    root->right = solve(in, pre, index, position + 1, inOrderEnd, n, nodeToIndex);
    // Return the root of the current subtree
    return root;
}

// Function to build the tree from inorder and preorder traversals
Node *buildTree(int in[], int pre[], int n)
{
    int preOrderIndex = 0;
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

// Driver code
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
