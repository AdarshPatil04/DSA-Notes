/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @file
 * This file contains the implementation of finding the kth smallest element in a binary tree using Morris Traversal.
 * The code defines a Node structure for the binary tree and a function to find the kth smallest element.
 * The function uses Morris Traversal, which allows finding the kth smallest element in O(n) time complexity and O(1) space complexity.
 * The main function constructs a binary tree and prints the kth smallest element.
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

// Function to find the kth smallest element in the binary tree
int kthSmallest(Node *root, int k)
{
    // Initialize the current node as root and declare a counter
    Node *curr = root;
    int count = 0;

    // While the current node is not null
    while (curr != NULL)
    {
        // If the left child of the current node is null
        if (curr->left == NULL)
        {
            // Increment the counter
            count++;

            // If the counter equals k, return the data of the current node
            if (count == k)
            {
                return curr->data;
            }

            // Move to the right child of the current node
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of the current node
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }

            // If the right child of the inorder predecessor is null
            if (pre->right == NULL)
            {
                // Make the current node as the right child of its inorder predecessor
                pre->right = curr;

                // Move to the left child of the current node
                curr = curr->left;
            }
            else
            {
                // Revert the changes made in the binary tree
                pre->right = NULL;

                // Increment the counter
                count++;

                // If the counter equals k, return the data of the current node
                if (count == k)
                {
                    return curr->data;
                }

                // Move to the right child of the current node
                curr = curr->right;
            }
        }
    }

    // If k is more than the number of nodes in the binary tree, return -1
    return -1;
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

    // Print the 3rd smallest element in the binary tree
    cout << kthSmallest(root, 3);

    return 0;
}
