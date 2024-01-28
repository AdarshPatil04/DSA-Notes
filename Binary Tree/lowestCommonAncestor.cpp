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

// Function to return the lowest common ancestor (LCA) in a Binary Tree.
Node* lca(Node* root, int n1, int n2)
{
    // Base case: if the root is NULL, return NULL
    if(root == NULL)
    {
        return NULL;
    }

    // If the root's data matches either n1 or n2, return the root
    if(root->data == n1 || root->data == n2)
    {
        return root;
    }

    // Recursively call the lca function for the left and right child nodes
    Node* leftAns = lca(root->left, n1, n2);
    Node* rightAns = lca(root->right, n1, n2);

    // If both leftAns and rightAns are not NULL, return the root
    // This is because n1 and n2 are on different sides of the root
    if(leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    // If leftAns is not NULL and rightAns is NULL, return leftAns
    else if(leftAns != NULL)
    {
        return leftAns;
    }
    // If leftAns is NULL and rightAns is not NULL, return rightAns
    else if(rightAns != NULL)
    {
        return rightAns;
    }
    // If both leftAns and rightAns are NULL, return NULL
    else
    {
        return NULL;
    }
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Find the LCA of 4 and 5
    Node *LCA = lca(root, 4, 5);

    // Print the LCA
    if(LCA != NULL)
        cout << "LCA: " << LCA->data << endl;
    else
        cout << "LCA doesn't exist" << endl;

    return 0;
}
