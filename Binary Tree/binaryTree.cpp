/**
 * @file binaryTree.cpp
 * @brief This file contains the implementation of a binary tree data structure and various tree traversal algorithms.
 * 
 * The binary tree is built using user input and supports level order, inorder, preorder, and postorder traversals.
 * The main function initializes the root node, builds the binary tree, and performs the traversals.
 * Inputs: 3 4 5 6 -1 -1 7 -1 -1 -1 -1
 * Output: 3 4 5 6 7
 */
#include <bits/stdc++.h>
using namespace std;

// Node class
class node {
    public:
        int data; // Data to be stored in the node
        node* left; // Pointer to the left child node
        node* right; // Pointer to the right child node

    // Constructor to initialize a new node
    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Function to build a binary tree
node* buildTree(node* root) {
    // Prompt the user to enter the data
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    // Create a new node with the entered data
    root = new node(data);    

    // If the entered data is -1, return NULL
    if(data == -1) {
        return NULL;
    }

    // Prompt the user to enter the data for the left and right child nodes
    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root; // Return the root node of the tree
}

// Function to perform level order traversal of the binary tree
void levelOrderTraversal(node* root) {
    queue<node*> q; // Queue to store the nodes of the binary tree
    q.push(root); // Push the root node into the queue
    q.push(NULL); // Push NULL into the queue to mark the end of the current level

    // While the queue is not empty
    while(!q.empty()) {
        node* temp = q.front(); // Store the front node of the queue in temp
        q.pop(); // Pop the front node from the queue

        // If temp is NULL, print a new line and push NULL into the queue if it is not empty
        if(temp == NULL) { 
            cout << endl;
            if(!q.empty()) { 
                q.push(NULL);
            }  
        }
        else{
            // Print the data of the node and push its left and right child nodes into the queue if they exist
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }
}

// Function to perform reverse level order traversal of the binary tree
void reverseLevelOrderTraversal(node* root) {
    queue<node*> q; // Queue to store the nodes of the binary tree
    stack<node*> s; // Stack to store the nodes in reverse order
    q.push(root); // Push the root node into the queue
    q.push(NULL); // Push NULL into the queue to mark the end of the current level

    // While the queue is not empty
    while(!q.empty()) {
        node* temp = q.front(); // Store the front node of the queue in temp
        q.pop(); // Pop the front node from the queue

        // If temp is NULL, push NULL into the stack if the queue is not empty
        if(temp == NULL) {
            if(!q.empty()) { 
                q.push(NULL);
                s.push(NULL);
            }
        }
        else{
            // Push the node into the stack
            s.push(temp);

            // Push the right child node into the queue before the left child node
            if(temp->right) {
                q.push(temp->right);
            }

            // Push the left child node into the queue
            if(temp->left) {
                q.push(temp->left);
            }
        }
    }

    // While the stack is not empty
    while(!s.empty()) {
        // If the node at the top of the stack is NULL, print a new line
        if(s.top() == NULL) {
            cout << endl;
            s.pop();
        }
        else {
            // Print the data of the node at the top of the stack
            cout << s.top()->data << " ";
            // Pop the node from the stack
            s.pop();
        }
    }
}

// Function to perform inorder traversal of the binary tree
void inorder(node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return ;
    }

    // Recursive case: Perform inorder traversal on the left subtree, print the data of the node, and then perform inorder traversal on the right subtree
    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);
}

// Function to perform preorder traversal of the binary tree
void preorder(node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return ;
    }

    // Recursive case: Print the data of the node, perform preorder traversal on the left subtree, and then perform preorder traversal on the right subtree
    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Function to perform postorder traversal of the binary tree
void postorder(node* root) {
    // Base case: If root is NULL, return
    if(root == NULL) {
        return ;
    }

    // Recursive case: Perform postorder traversal on the left subtree, perform postorder traversal on the right subtree, and then print the data of the node
    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";
}

// Main function
int main() {
    node* root = NULL; // Initialize the root node to NULL

    // Build the binary tree
    root = buildTree(root);

    // Perform level order traversal of the binary tree
    cout << "Printing the level order traversal output " << endl;
    levelOrderTraversal(root);

    // Perform reverse level order traversal of the binary tree
    cout << "Printing the reverse level order traversal output " << endl;
    reverseLevelOrderTraversal(root);

    // Perform inorder traversal of the binary tree
    cout << "inorder traversal is:  ";
    inorder(root); 

    // Perform preorder traversal of the binary tree
    cout << endl << "preorder traversal is:  ";
    preorder(root); 

    // Perform postorder traversal of the binary tree
    cout << endl << "postorder traversal is:  ";
    postorder(root); 

    return 0;
}
