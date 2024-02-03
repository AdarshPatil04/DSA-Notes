/**
 * Time Complexity: O(n)
 * @brief This code finds the size of the largest Binary Search Tree (BST) in a given binary tree.
 * 
 * The code defines a Node class to represent each node in the binary search tree.
 * It also defines an Info class to store information about a subtree.
 * The solve function recursively solves the problem for each subtree and updates the answer.
 * The largestBST function returns the size of the largest BST in the binary tree.
 * The main function constructs a binary search tree and prints the size of the largest BST.
 */
#include <bits/stdc++.h>
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

// Info class to store information about a subtree
class info
{
public:
    int size;   // size of the subtree
    bool isBST; // true if subtree is a binary search tree
    int max;    // maximum value in the subtree
    int min;    // minimum value in the subtree
};

// Function to solve the problem
info solve(Node *root, int &ans)
{
    // Base case: if the tree is empty, it is a BST
    if (root == NULL)
        return {0, true, INT_MIN, INT_MAX};

    // Solve the problem recursively for the left and right subtrees
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    // Create a new info object for the current subtree
    info curr;
    curr.min = min(root->data, left.min);
    curr.max = max(root->data, right.max);
    curr.size = left.size + right.size + 1;

    // Check if the current subtree is a BST
    if ((root->data > left.max && root->data < right.min) && left.isBST && right.isBST)
    {
        curr.isBST = true;
    }
    else
    {
        curr.isBST = false;
    }

    // If the current subtree is a BST, update the answer
    if (curr.isBST)
        ans = max(curr.size, ans);

    // Return the info for the current subtree
    return curr;
}

// Function to find the size of the largest BST in a binary tree
int largestBST(Node *root)
{
    int ans = 0;
    info dummy = solve(root, ans);
    return ans;
}

int main()
{
    // Construct the binary search tree
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);

    // Print the size of the largest BST
    cout << largestBST(root);

    return 0;
}
