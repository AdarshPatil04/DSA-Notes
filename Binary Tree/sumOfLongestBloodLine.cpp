/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This code calculates the maximum sum of a root-to-leaf path in a binary tree.
 * 
 * The code defines a binary tree node structure and implements a recursive function to calculate the maximum sum.
 * It starts from the root node and traverses down to each leaf node, keeping track of the maximum sum encountered.
 * The function returns the maximum sum of a root-to-leaf path in the given binary tree.
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

// Recursive function to calculate the maximum sum of a root-to-leaf path
void solve(Node* root, int sum, int &maxSum, int len, int &maxLen) {
    // Base case: if the root is NULL, return
    if(root == NULL) {
        // If the length of the current path is greater than the maximum length found so far
        if(len > maxLen) {
            maxLen = len; // Update the maximum length
            maxSum = sum; // Update the maximum sum
        }
        // If the length of the current path is equal to the maximum length
        else if(len == maxLen) {
            // Update the maximum sum if the current sum is greater
            maxSum = max(sum, maxSum);
        }
        return;
    }
    
    // Add the current node's data to the sum
    sum = sum + root->data;
    
    // Recursively call the solve function for the left and right child nodes
    // Increase the length by 1
    solve(root->left, sum, maxSum, len+1, maxLen);
    solve(root->right, sum, maxSum, len+1, maxLen);
}

// Function to return the maximum sum of a root-to-leaf path
int sumOfLongRootToLeafPath(Node *root)
{
    int len = 0; // Initialize the length of the path
    int maxLen = 0; // Initialize the maximum length
    
    int sum = 0; // Initialize the sum of the path
    int maxSum = INT_MIN; // Initialize the maximum sum
    
    // Call the solve function to calculate the maximum sum
    solve(root, sum, maxSum, len, maxLen);
    
    // Return the maximum sum
    return maxSum;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    // Get the maximum sum of a root-to-leaf path
    int ans = sumOfLongRootToLeafPath(root);

    // Print the maximum sum
    cout << ans << endl;

    return 0;
}
