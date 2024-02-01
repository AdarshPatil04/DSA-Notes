/**
 * Time complexity: O(h) where h is the height of the tree
 * @brief This program demonstrates the deletion of nodes from a Binary Search Tree (BST).
 *        It includes functions to find the node with the minimum value in the tree, delete a node from the BST,
 *        and print the level order traversal of the binary tree.
 *        The main function constructs a BST, deletes nodes with specific values, and prints the tree after each deletion.
 */
#include <iostream>
#include <queue>
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

// Function to find the node with the minimum value in a given tree/subtree
Node *minValue(Node *root)
{
    Node *temp = root;

    // Go to the leftmost node
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

// Function to delete a node from the BST
Node *deleteFromBST(Node *root, int val)
{
    // base case
    if (root == NULL)
    {
        return root;
    }

    // If the node is found
    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = deleteFromBST(root->left, val);
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = deleteFromBST(root->right, val);
            delete root;
            return temp;
        }

        // 2 child
        /*
        // Alternative code for 2 child case
        if (root->left != NULL && root->right != NULL)
        {
            // Find the maximum value in the left subtree
            Node *temp = maxValue(root->left);
            // Replace the node's data with the maximum value
            root->data = temp->data;
            // Delete the maximum value node from the left subtree
            root->left = deleteFromBST(root->left, temp->data);
            return root;
        }
        */
        if (root->left != NULL && root->right != NULL)
        {
            // finding mini from the right part
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if (root->data > val)
    {
        // If the given value is less than the root's data, go to the left subtree
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        // If the given value is more than the root's data, go to the right subtree
        root->right = deleteFromBST(root->right, val);
        return root;
    }
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

int main()
{
    // Construct the binary tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Print the level order traversal of the tree before deletion
    cout << "Before deleting" << endl;
    levelOrderTraversal(root);

    // Delete node with value 8 and print the tree after deletion
    deleteFromBST(root, 8);
    cout << "After deleting 8" << endl;
    levelOrderTraversal(root);

    // Delete node with value 7 and print the tree after deletion
    deleteFromBST(root, 7);
    cout << "After deleting 7" << endl;
    levelOrderTraversal(root);

    // Delete node with value 5 and print the tree after deletion
    deleteFromBST(root, 5);
    cout << "After deleting 5" << endl;
    levelOrderTraversal(root);

    return 0;
}
