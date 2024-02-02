/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This program demonstrates the conversion of a normal binary search tree (BST) into a balanced BST.
 * 
 * The program defines a Node structure for the binary tree and provides functions to perform inorder traversal,
 * convert a sorted array to a balanced BST, convert a binary tree to a balanced BST, and print the level order
 * traversal and inorder traversal of the binary tree.
 * 
 * The main function constructs a binary tree, prints its level order traversal before balancing, performs the
 * balancing operation, and prints the level order traversal after balancing.
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

// Function to perform inorder traversal and store the node values in a vector
void inorder(Node *root, vector<int> &in)
{
    // Base case: if the node is null, return
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorder(root->left, in);

    // Store the node value in the vector
    in.push_back(root->data);

    // Traverse the right subtree
    inorder(root->right, in);
}

// Function to convert a sorted array to a balanced binary search tree
Node *inorderToBST(int s, int e, vector<int> &v)
{
    // Base case: if start index is greater than end index, return null
    if (s > e)
        return NULL;

    // Calculate the middle index
    int mid = (s + e) / 2;

    // Create a new node with the middle element
    Node *newRoot = new Node(v[mid]);

    // Recursively construct the left and right subtrees
    newRoot->left = inorderToBST(s, mid - 1, v);
    newRoot->right = inorderToBST(mid + 1, e, v);
    return newRoot;
}

// Function to convert a binary tree to a balanced binary search tree
Node *balancedBst(Node *root)
{
    vector<int> v;

    // Store the inorder traversal of the binary tree in a vector
    inorder(root, v);

    // Convert the sorted array to a balanced binary search tree
    return inorderToBST(0, v.size() - 1, v);
}

// Function to print the level order traversal of the binary tree
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    root->right->right->right = new Node(30);
    root->right->right->right->right = new Node(35);
    cout << "Level order traversal of the binary tree before balancing:" << endl;
    levelOrderTraversal(root);
    root = balancedBst(root);
    cout << "Level order traversal of the binary tree after balancing:" << endl;
    levelOrderTraversal(root);
    return 0;
}
