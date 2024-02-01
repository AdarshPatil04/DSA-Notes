/**
 * Time complexity: O(n)
 * Space complexity: O(h) where h is the height of the tree
 * @brief This program checks if a given binary tree is a valid Binary Search Tree (BST).
 *
 * The program defines a Node class to represent each node in the binary search tree.
 * It includes functions to check if a given tree/subtree is a BST and to validate if a given tree is a BST.
 * The main function constructs a binary tree and checks if it is a valid BST.
 * If the tree is a BST, it prints "Valid BST". Otherwise, it prints "Invalid BST".
 *
 * @return int The exit status of the program.
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

// Function to check if a given tree/subtree is a BST
bool isBST(Node *root, int min, int max)
{
    // base case: an empty tree is BST
    if (root == NULL)
    {
        return true;
    }

    // if node's value is within the valid range and the left and right subtrees are also BSTs
    if (root->data >= min && root->data <= max)
    {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else
    {
        // if node's value is not within the valid range, it's not a BST
        return false;
    }
}

// Function to validate if a given tree is a BST
bool validateBST(Node *root)
{
    // the valid range for the root of BST is from INT_MIN to INT_MAX
    return isBST(root, INT_MIN, INT_MAX);
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

    // If the tree is a BST, print "Valid BST"
    if (validateBST(root))
    {
        cout << "Valid BST" << endl;
    }
    // If the tree is not a BST, print "Invalid BST"
    else
    {
        cout << "Invalid BST" << endl;
    }
    return 0;
}
