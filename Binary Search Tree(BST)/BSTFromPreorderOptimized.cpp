/**
 * @brief This program demonstrates the construction of a binary search tree (BST) from a given preorder traversal.
 *        It takes a vector representing the preorder traversal of a BST as input and constructs the corresponding BST.
 *        The program then prints the level order traversal of the constructed BST.
 *
 * @details The program defines a Node class to represent a node in the binary tree. Each node contains an integer data value,
 *          and pointers to its left and right child nodes. The main function initializes a vector representing the preorder traversal,
 *          calls the preorderToBST function to construct the BST, and then calls the levelOrderTraversal function to print the level order traversal.
 *          The solve function is a recursive helper function that constructs the BST by recursively dividing the preorder traversal into left and right subtrees.
 *          The levelOrderTraversal function uses a queue to perform a level order traversal of the BST and prints the node values.
 *
 * @return 0 on successful execution.
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

// Recursive function to construct a binary search tree from a preorder traversal
Node *solve(vector<int> &preorder, int maxi, int &i)
{
    // Base case: if all elements are used up or the current element is not in the range, return null
    if (i >= preorder.size() || preorder[i] > maxi)
        return NULL;

    // Create a new node with the current element and increment the index
    Node *root = new Node(preorder[i++]);

    // Recursively construct the left and right subtrees
    root->left = solve(preorder, root->data, i);
    root->right = solve(preorder, maxi, i);
    return root;
}

// Function to convert a preorder traversal to a binary search tree
Node *preorderToBST(vector<int> &preorder)
{
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, maxi, i);
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

        // If a null node is encountered, print a newline and push another null into the queue if it is not empty
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
            // Print the node value and push its left and right children into the queue
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    // Initialize the preorder traversal
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    // Convert the preorder traversal to a binary search tree
    Node *root = preorderToBST(preorder);

    // Print the level order traversal of the binary search tree
    levelOrderTraversal(root);

    return 0;
}
