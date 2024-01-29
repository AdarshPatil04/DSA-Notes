/**
 * Time Complexity: O(n^2) because we’re checking all possible subarrays of path for each node in the tree
 * Space Complexity: O(n)
 * This code calculates the number of subarrays in a binary tree that sum up to a given value.
 * It defines a binary tree node structure and implements a recursive function to solve the problem.
 * The solve function traverses the binary tree in a depth-first manner, keeping track of the current path and the count of subarrays.
 * At each node, it checks if any subarray in the path sums up to the given value and increments the count accordingly.
 * The sumK function initializes the path and count, and calls the solve function.
 * The main function creates a binary tree and calls the sumK function to calculate the number of subarrays with a specific sum.
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
void solve(Node *root, int k, int &count, vector<int> path)
{
    // Base case: if the node is NULL, return
    if (root == NULL)
        return;

    // Add the current node's data to the path
    path.push_back(root->data);

    // Recursively call the solve function for the left child of the current node
    solve(root->left, k, count, path); // after it reaches last left node then NULL, call goes for right in the same node for that also it is NULL so further it goes to calculate the sum and pop back

    // Recursively call the solve function for the right child of the current node
    solve(root->right, k, count, path);

    // Check if any subarray in the path array sums up to k
    int size = path.size();
    int sum = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        sum += path[i];
        // If we find such a subarray, increment our count
        if (sum == k)
            count++;
    }

    // Before we end the function call for the current node, remove it from our path (effectively backtracking)
    path.pop_back();
}

// Function to initialize the path and count and call the solve function
int sumK(Node *root, int k)
{
    vector<int> path;
    int count = 0;
    solve(root, k, count, path);
    return count;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(-1);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);
    cout << "Number of subarrays with sum 5: " << sumK(root, 5);
    return 0;
}
