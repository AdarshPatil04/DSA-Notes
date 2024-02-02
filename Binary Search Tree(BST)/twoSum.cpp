/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This program checks if there exist two elements in a Binary Search Tree (BST) such that their sum is equal to a given target.
 * 
 * The program defines a Node structure for the binary tree and implements an inorder traversal to store the node values in a vector.
 * It then uses a two-pointer approach to check if a pair of values in the vector exists with a sum equal to the target.
 * If such a pair exists, the program returns true; otherwise, it returns false.
 * 
 * The main function constructs a sample BST and calls the twoSumInBST function to check if there exist two elements with a sum of 10.
 * The result is printed as "Yes" if a pair exists, and "No" otherwise.
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

// Function to perform inorder traversal and store the node values in a vector
void inorder(Node* root, vector<int> &in){
    // Base case: if the node is null, return
    if(root == NULL)
        return;

    // Traverse the left subtree
    inorder(root->left, in);

    // Store the node value in the vector
    in.push_back(root->data);

    // Traverse the right subtree
    inorder(root->right, in);
}

// Function to check if there exist two elements in the BST such that their sum is equal to the given target
bool twoSumInBST(Node* root, int target) {

    // Vector to store the inorder traversal of the BST
    vector<int> inorderVal;

    // Perform inorder traversal and store the node values in the vector
    inorder(root, inorderVal);

    // Use 2-pointer approach to check if a pair exists with sum equal to the target
    int i = 0; 
    int j = inorderVal.size()-1;
    
    while(i < j){
        int sum = inorderVal[i] + inorderVal[j];

        // If the sum of the pair is equal to the target, return true
        if(sum == target){
            return true;
        }
        // If the sum of the pair is greater than the target, decrement the end pointer
        else if(sum > target){
            j--;
        }
        // If the sum of the pair is less than the target, increment the start pointer
        else{
            i++;
        }
    }

    // If no pair exists with sum equal to the target, return false
    return false;
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Check if there exist two elements in the BST such that their sum is equal to the given target
    if(twoSumInBST(root, 10))
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
