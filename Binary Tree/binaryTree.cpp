/**
 * @brief This code demonstrates various tree traversal algorithms (level order, inorder, preorder, postorder) on a binary tree.
 *
 * The code defines a `node` class representing a node in the binary tree. Each node has a data value and pointers to its left and right child nodes.
 *
 * The code also includes functions for level order traversal, inorder traversal, preorder traversal, and postorder traversal of the binary tree.
 *
 * The `levelOrderTraversal` function performs a level order traversal of the binary tree using a queue. It prints the nodes at each level, starting from the root.
 *
 * The `inorder`, `preorder`, and `postorder` functions perform inorder, preorder, and postorder traversals of the binary tree, respectively. They recursively traverse the left subtree, visit the current node, and then recursively traverse the right subtree.
 *
 * The `main` function initializes a binary tree and calls the traversal functions to demonstrate their usage.
 */
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    // Node with data, left and right pointers
    int data;
    node *left;
    node *right;

    // Constructor to initialize the node
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function for level order traversal of the binary tree
void levelOrderTraversal(node *root)
{
    // Queue to store the nodes of the binary tree and push the root node initially into the queue then push NULL
    queue<node *> q;
    q.push(root);
    q.push(NULL);

    // While the queue is not empty
    while (!q.empty())
    {
        node *temp = q.front(); // Store the front element of the queue in temp
        q.pop();                // Pop the front element of the queue

        // If temp is NULL, print a new line and push NULL if the queue is not empty
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        // Else print the data of the node and push the left and right child of the node if they exist
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// Function for inorder traversal of the binary tree
void inorder(node *root)
{
    // Base case
    // If root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // LNR
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function for preorder traversal of the binary tree
void preorder(node *root)
{
    // Base case
    // If root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // Recursive case
    // NLR
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function for postorder traversal of the binary tree
void postorder(node *root)
{
    // Base case
    // If root is NULL, return
    if (root == NULL)
    {
        return;
    }

    // // Recursive case
    // LRN
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    // Assume root is initialized properly
    levelOrderTraversal(root);
    inorder(root);
    preorder(root);
    postorder(root);
    return 0;
}
