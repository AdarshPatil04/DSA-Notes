/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This code calculates the maximum sum of non-adjacent nodes in a binary tree.
 *
 * The code defines a binary tree node structure and implements a function to solve the problem.
 * The solve function recursively calculates the maximum sum of non-adjacent nodes in the tree.
 * The getMaxSum function calls the solve function and returns the maximum sum.
 * The main function creates a binary tree and prints the maximum sum of non-adjacent nodes.
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

// Function to solve the problem
pair<int, int> solve(Node *root)
{
    // Base case: if the node is NULL, return a pair of zeros
    if (root == NULL)
    {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }

    // Recursively call the solve function for the left child of the current node
    pair<int, int> left = solve(root->left);

    // Recursively call the solve function for the right child of the current node
    pair<int, int> right = solve(root->right);

    // Create a pair to store the result
    pair<int, int> res;

    // The first element of the pair is the sum of the current node's data and the maximum sums of non-adjacent nodes in the left and right subtrees
    res.first = root->data + left.second + right.second;

    // The second element of the pair is the sum of the maximum sums of adjacent nodes in the left and right subtrees
    res.second = max(left.first, left.second) + max(right.first, right.second);

    // Return the result pair
    return res;
}

// Function to get the maximum sum of non-adjacent nodes in the tree
int getMaxSum(Node *root)
{
    // Call the solve function and store the result in ans
    pair<int, int> ans = solve(root);

    // Return the maximum of the two elements in the ans pair
    return max(ans.first, ans.second);
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    cout << getMaxSum(root) << endl;
    return 0;
}
