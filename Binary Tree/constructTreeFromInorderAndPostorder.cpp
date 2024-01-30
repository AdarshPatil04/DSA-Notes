/**
 * Time complexity: O(nlogn) because we are using map with logn access time inside a for loop with O(n)
 * Space complexity: O(n) because we are using map with O(n) space and recursion stack with O(n) space
 * @brief This program constructs a binary tree from its inorder and postorder traversals.
 * 
 * The program takes two arrays, `in[]` and `post[]`, representing the inorder and postorder traversals of a binary tree respectively.
 * It then constructs the binary tree using these traversals and performs a preorder traversal on the constructed tree.
 * 
 * The main steps of the program are as follows:
 * 1. Define the structure of a node in the binary tree.
 * 2. Create a mapping from node data to its index in the inorder traversal.
 * 3. Recursively construct the binary tree from the inorder and postorder traversals.
 * 4. Build the tree from the inorder and postorder traversals.
 * 5. Perform a preorder traversal on the constructed tree.
 * 
 * @return 0 on successful execution.
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

// Function to create a mapping from node data to its index in the inorder traversal, using map for O(nlogn) access
void createMapping(int in[], map<int, int> &nodeToIndex, int n)
{
    for (int i = 0; i < n; i++)
    {
        nodeToIndex[in[i]] = i;
    }
}

// Recursive function to construct the binary tree from inorder and postorder traversals
Node *solve(int in[], int post[], int &index, int inOrderStart, int inOrderEnd, int n, map<int, int> &nodeToIndex)
{
    // Base case: if the current subarray of inorder traversal is empty, return NULL
    if (index < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }
    // The current element in postorder traversal is the root of the current subtree
    int element = post[index--];
    Node *root = new Node(element);
    // Find the position of the root in inorder traversal
    int position = nodeToIndex[element];
    // Construct the left and right subtrees
    root->right = solve(in, post, index, position + 1, inOrderEnd, n, nodeToIndex); // Note that the right subtree is constructed first because the postorder traversal is left, right, root
    root->left = solve(in, post, index, inOrderStart, position - 1, n, nodeToIndex);
    // Return the root of the current subtree
    return root;
}

// Function to build the tree from inorder and postorder traversals
Node *buildTree(int in[], int post[], int n)
{
    int postOrderIndex = n-1; // Start from the end of the postorder array
    map<int, int> nodeToIndex;
    // Create a mapping from node data to its index in inorder traversal
    createMapping(in, nodeToIndex, n);
    // Construct the tree and return its root
    Node *ans = solve(in, post, postOrderIndex, 0, n - 1, n, nodeToIndex);
    return ans;
}

// Function to perform preorder traversal of the binary tree
void preorder(Node *root)
{
    // Base case: If root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // Recursive case: Print the data of the node, perform preorder traversal on the left subtree, and then perform preorder traversal on the right subtree
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int n = 5;
    int in[n] = {4, 2, 5, 1, 3};
    int post[n] = {4, 5, 2, 3, 1};
    // Build the tree from inorder and postorder traversals
    Node *root = buildTree(in, post, n);
    // Perform preorder traversal on the constructed tree
    preorder(root);
    return 0;
}
