/**
 * Time complexity: O(n)
 * @brief This program demonstrates the construction of a binary search tree (BST) from a given preorder traversal.
 *        It takes a vector representing the preorder traversal as input and constructs a BST using the values in the vector.
 *        The program then prints the level order traversal of the constructed BST.
 * 
 * @details The program defines a Node class to represent a node in the binary tree.
 *          It uses a recursive function to construct the BST from the preorder traversal.
 *          The function takes the current element, minimum value, maximum value, and an index as parameters.
 *          It checks if the current element is within the range of the minimum and maximum values.
 *          If it is, a new node is created with the current element and the index is incremented.
 *          The function then recursively constructs the left and right subtrees using the updated range and index.
 *          The main function initializes the preorder traversal vector and calls the preorderToBST function to construct the BST.
 *          Finally, the levelOrderTraversal function is called to print the level order traversal of the BST.
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
Node *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    // Base case: if all elements are used up or the current element is not in the range, return null
    if (i >= preorder.size() || preorder[i] < mini || preorder[i] > maxi)
        return NULL;

    // Create a new node with the current element and increment the index
    Node *root = new Node(preorder[i++]);

    // Recursively construct the left and right subtrees
    root->left = solve(preorder, mini, root->data, i);
    root->right = solve(preorder, root->data, maxi, i);
    return root;
}

// Function to convert a preorder traversal to a binary search tree
Node *preorderToBST(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
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
