/**
 * Time Complexity: O(n)
 * Space Complexity: O(Height of the tree)
 * @file sumTree.cpp
 * @brief This file contains the implementation of a function to check if a binary tree is a sum tree.
 * 
 * A sum tree is a binary tree in which the value of each node is equal to the sum of the values of its left and right child nodes.
 * This code defines a Node class to represent the structure of a node in the binary tree and implements a function to check if a given binary tree is a sum tree.
 * The function uses a recursive approach to traverse the tree and check the sum property for each node and its children.
 * If the tree is a sum tree, the function returns true; otherwise, it returns false.
 */
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

// Function to check if a tree is a sum tree
pair<bool,int> isSumTreeFast(Node* root) {
    // Base case: if the node is null, return true and sum as 0
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    
    // If the node is a leaf node, return true and the node's data as sum
    if(root->left == NULL && root->right == NULL ) {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    
    // Recursively check for left and right subtrees
    pair<bool,int> leftAns = isSumTreeFast(root->left);
    pair<bool,int> rightAns = isSumTreeFast(root->right);
    
    // Extract the boolean values and sums from the pair
    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;
    int leftSum = leftAns.second;
    int rightSum = rightAns.second;
    
    // Check if the node's data is equal to the sum of its left and right children
    bool condn = root->data == leftSum + rightSum;
    
    pair<bool, int> ans;
    
    // If the node and its children form a sum tree, return true and the total sum
    if(isLeftSumTree && isRightSumTree && condn) {
        ans.first = true;
        ans.second = root->data + leftSum + rightSum ; // OR 2 * root->data since in the above condn = root->data == leftSum + rightSum
    }
    else
    {
        // If the node and its children do not form a sum tree, return false
        ans.first = false;
    }
    return ans;
}

// Wrapper function to only return the boolean value
bool isSumTree(Node* root)
{
    return isSumTreeFast(root).first;
}

int main(){
    // Create a binary tree
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);

    // Check if the tree is a sum tree
    if (isSumTree(root))
    {
        cout << "The tree is a sum tree";
    }
    else
    {
        cout << "The tree is not a sum tree";
    }

    return 0;
}
