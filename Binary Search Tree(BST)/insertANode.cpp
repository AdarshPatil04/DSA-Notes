
/**
 * @brief This program demonstrates the implementation of a Binary Search Tree (BST).
 *        It allows the user to insert elements into the BST and performs various traversals
 *        such as level order, inorder, preorder, and postorder traversal.
 *        The program takes input from the user to build the BST and then prints the traversals.
 * 
 *        The Node class defines the structure of a Node in the binary tree, with data, left,
 *        and right pointers. The insertIntoBST function inserts a new Node into the BST based
 *        on the value of the data. The takeInput function takes input from the user to build
 *        the BST. The levelOrderTraversal function performs a breadth-first search traversal
 *        of the binary tree. The printInorder, printPreorder, and printPostorder functions
 *        perform inorder, preorder, and postorder traversals respectively.
 * Inputs: 5 3 7 1 6 8 -1
 * Output: Level Order traversal of the BST:
 *        5
 *       3 7
 *     1 6 8
 * Inorder traversal of the BST:
 * 1 3 5 6 7 8
 * Preorder traversal of the BST:
 * 5 3 1 7 6 8
 * Postorder traversal of the BST:
 * 1 3 6 8 7 5
 * @return 0 on successful execution
 */
#include<bits/stdc++.h>
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

// Function to insert a new Node into the Binary Search Tree
Node *insertIntoBST(Node *&root, int d)
{
    // If the root is NULL, create a new Node and return it
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }
    // If the data to be inserted is less than or equal to the root's data, insert it into the left subtree
    if (d <= root->data)
    {
        insertIntoBST(root->left, d);
    }
    // If the data to be inserted is greater than the root's data, insert it into the right subtree
    else
    {
        insertIntoBST(root->right, d);
    }
    return root;
}

// Function to take the elements of the BST as input from the user
void takeInput(Node *&root)
{
    int d;
    cin >> d;
    // Keep taking input until the user enters -1
    while (d != -1)
    {
        root = insertIntoBST(root, d);
        cin >> d;
    }
}

// Function to perform level order traversal (Breadth-First Search) of the binary tree
void levelOrderTraversal(Node *root)
{
    queue<Node *> q; // Queue to store the Nodes of the binary tree
    q.push(root);    // Push the root Node into the queue
    q.push(NULL);    // Push NULL into the queue to mark the end of the current level

    // While the queue is not empty
    while (!q.empty())
    {
        Node *temp = q.front(); // Store the front Node of the queue in temp
        q.pop();                // Pop the front Node from the queue

        // If temp is NULL, print a new line and push NULL into the queue if it is not empty
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
            // Print the data of the Node and push its left and right child Nodes into the queue if they exist
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

// Function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

// Function to print the preorder traversal of the binary tree
void printPreorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to print the postorder traversal of the binary tree
void printPostorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL; // Initialize the root of the binary tree to NULL
    cout<<"Enter the elements of the BST: "<<endl;
    takeInput(root); // Take the elements of the BST as input from the user
    cout << "Level Order traversal of the BST: "<<endl;
    levelOrderTraversal(root); // Print the level order traversal of the BST
    cout << "Inorder traversal of the BST: "<<endl;
    printInorder(root); // Print the inorder traversal of the BST
    cout<<endl;
    cout << "Preorder traversal of the BST: "<<endl;
    printPreorder(root); // Print the preorder traversal of the BST
    cout<<endl;
    cout << "Postorder traversal of the BST: "<<endl;
    printPostorder(root); // Print the postorder traversal of the BST
    cout<<endl;
    return 0;
}
