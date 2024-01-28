/**
 * Time Complexity: O(n)
 * Space Complexity: O(height of the tree)
 * @brief This program calculates the diameter of a binary tree.
 * 
 * The diameter of a binary tree is defined as the length of the longest path between any two nodes in the tree.
 * This program uses a recursive approach to calculate the diameter of the binary tree.
 * It defines a structure for tree nodes and provides functions to create new nodes and calculate the diameter.
 * The main function creates a binary tree and prints the diameter of the tree.
 */
#include<bits/stdc++.h>
using namespace std;

// Define the structure for tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new node
Node* newNode(int data) {
    Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to calculate the diameter of the binary tree
pair<int,int> diameterFast(Node* root) {
    // Base case: if the root is null, return pair of zeros
    if(root == NULL) {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
    
    // Recursively calculate the diameter of the left and right subtrees
    pair<int,int> left = diameterFast(root->left);
    pair<int,int> right = diameterFast(root->right);
    
    // Calculate the maximum diameter using the diameters of left and right subtrees and the sum of the heights of the subtrees
    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    
    // Store the maximum diameter and the maximum height in a pair
    pair<int,int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second , right.second) + 1;

    // Return the pair
    return ans;
}

// Function to return the diameter of the binary tree
int diameter(Node* root) {
    // Call the diameterFast function and return the first element of the pair (i.e., the diameter)
    return diameterFast(root).first;
}

// Driver code
int main() {
     Node *root =  newNode(1);
    root->left =  newNode(2);
    root->right =  newNode(3);
    root->left->left =  newNode(4);
    root->left->right =  newNode(5);
    root->left->right->right =  newNode(6);
    root->left->right->right->right =  newNode(7);
    
    cout << "Diameter of the given binary tree is " << diameter(root);
    
    return 0;
}
