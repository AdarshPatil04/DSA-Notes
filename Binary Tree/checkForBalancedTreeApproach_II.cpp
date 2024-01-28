/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This code checks if a binary tree is balanced or not.
 * 
 * The code defines a binary tree node structure and provides a function to check if the tree is balanced.
 * It uses a recursive approach to calculate the height of the left and right subtrees and checks if their heights differ by at most 1.
 * If the tree is balanced, it returns true; otherwise, it returns false.
 * The main function creates a binary tree and prints whether the tree is balanced or not.
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

// Function to check if a binary tree is balanced
pair<bool, int> isBalancedFast(Node *root)
{
    // Base case: if the node is null, it is balanced
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // Recursively check if the left and right subtrees are balanced
    pair<int, int> left = isBalancedFast(root->left);
    pair<int, int> right = isBalancedFast(root->right);

    // Store the results of the recursive calls
    bool leftAns = left.first;
    bool rightAns = right.first;

    // Check if the heights of the left and right subtrees differ by at most 1
    bool diff = abs(left.second - right.second) <= 1;

    // Prepare the answer
    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    // If the left and right subtrees are balanced and their heights differ by at most 1, the tree is balanced
    if (leftAns && rightAns && diff)
    {
        ans.first = true;
    }
    else
    {
        ans.first = false;
    }
    return ans;
}

// Wrapper function to check if a binary tree is balanced
bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}

// Main function
int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    // Print whether the tree is balanced or not
    cout << "Is the tree balanced? " << (isBalanced(root) ? "Yes" : "No") << endl;
    return 0;
}
