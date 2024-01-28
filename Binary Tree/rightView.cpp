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

// Recursive function to fill the ans vector with the right view of the binary tree.
void solve(Node *root, vector<int> &ans, int level)
{
    // Base case: if the root is NULL, return
    if (root == NULL)
        return;

    // If we entered into a new level, add the node's data to the ans vector
    if (level == ans.size())
        ans.push_back(root->data);

    // Recursively call the solve function for the right and left child nodes
    // Increase the level by 1
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}

// Function to return a list containing elements of right view of the binary tree.
vector<int> rightView(Node *root)
{
    vector<int> ans; // Vector to store the right view
    solve(root, ans, 0); // Call the solve function to fill the ans vector
    return ans; // Return the ans vector
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    // Get the right view of the binary tree
    vector<int> ans = rightView(root);

    // Print the right view
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    return 0;
}
