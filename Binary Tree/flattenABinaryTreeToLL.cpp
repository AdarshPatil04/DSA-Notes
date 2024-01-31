/**
 * Time complexity: O(n)
 * Space complexity: O(1) because we are not using stack or recursion or map but by using morris traversal
 * @brief This program demonstrates how to flatten a binary tree into a linked list in-place.
 * 
 * The program defines a binary tree structure using the Node class. The flatten function is used to
 * flatten the binary tree into a linked list by rearranging the pointers of the nodes. The printInorder
 * function is used to print the inorder traversal of the binary tree before and after flattening.
 * 
 * The main function constructs a binary tree, prints its inorder traversal, flattens the tree, and then
 * prints the inorder traversal of the flattened tree.
 */
#include<bits/stdc++.h>
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

// Function to flatten the binary tree into a linked list in-place
// It changes the structure of the binary tree by using curr and by taking the same root node as input
void flatten(Node* root){
    Node* curr = root; // Start from the root
    while(curr!=NULL){
        if(curr->left){ // If the current node has a left child
            Node* pred = curr->left; // Start from the left child
            while(pred->right!=NULL){ // Find the rightmost node in the left subtree
                pred = pred->right;
            }
            // Make the right child of the rightmost node point to the right child of the current node
            pred->right = curr->right;
            // Make the right child of the current node point to its left child
            curr->right = curr->left;
            curr->left = NULL; // Make the left child of the current node NULL
        }
        curr = curr->right; // Move on to the right child of the current node
    }
}

// Function to print the inorder traversal of the binary tree
void printInorder(Node* root){
    if(root==NULL){ // If the root is NULL, there is no tree to print
        return;
    }
    printInorder(root->left); // Print the left subtree
    cout<<root->data<<" "; // Print the data of the root
    printInorder(root->right); // Print the right subtree
}

int main(){
    // Construct the binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    printInorder(root); // Print the inorder traversal of the original tree
    cout<<endl;
    flatten(root); // Flatten the binary tree into a linked list in-place
    printInorder(root); // Print the inorder traversal of the flattened tree
    cout<<endl;
    return 0;
}
