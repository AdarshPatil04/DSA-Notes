/**
 * @brief This program counts the number of leaf nodes in a binary tree.
 * 
 * It defines a BinaryTreeNode class to represent each node in the binary tree.
 * The countLeafNodesInorder function performs an inorder traversal of the binary tree
 * and counts the number of leaf nodes. The getNumberOfLeafNodes function calls the
 * countLeafNodesInorder function and returns the count. The main function initializes
 * a binary tree, calls the getNumberOfLeafNodes function, and prints the result.
 */
#include <bits/stdc++.h>
using namespace std;

// Class to represent each node in the binary tree
class BinaryTreeNode {
    public:
        int data;
        BinaryTreeNode* left;
        BinaryTreeNode* right;

    // Constructor to initialize a new node
    BinaryTreeNode(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Function for inorder traversal of the binary tree
// This function also counts the number of leaf nodes
void countLeafNodesInorder(BinaryTreeNode* root, int &count) {
    // Base case: if the node is null, return
    if(root == NULL) {
        return ;
    }

    // Recursively traverse the left subtree
    countLeafNodesInorder(root->left, count);
   	
    // If the current node is a leaf node (both left and right children are null), increment the count
    if(root->left == NULL && root->right == NULL) {
        count++;
    }
    
    // Recursively traverse the right subtree
    countLeafNodesInorder(root->right, count);
}

// Function to return the number of leaf nodes in the binary tree
int getNumberOfLeafNodes(BinaryTreeNode* root){
    int count = 0;
    countLeafNodesInorder(root, count);
    return count;
}

int main() {
    BinaryTreeNode* root = NULL;
    // Assume root is initialized properly
    int numberOfLeafNodes = getNumberOfLeafNodes(root);
    cout << "Number of leaf nodes: " << numberOfLeafNodes << endl;
    return 0;
}
