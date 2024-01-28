/**
 * Time Complexity: O(n) since we visit each node exactly once.
 * Space Complexity: O(n) number of leaves in the tree can be considered is n.
 * @file zigzagTraversal.cpp
 * @brief This file contains the implementation of the zigzag traversal of a binary tree.
 * 
 * The zigzag traversal of a binary tree is a traversal where we visit the nodes in a zigzag pattern,
 * starting from the root node and alternating between left-to-right and right-to-left at each level.
 * This file defines a Node class to represent a node in the binary tree and implements the zigzagTraversal function
 * to store the zigzag order traversal of the tree in a vector.
 * The main function creates a binary tree and prints the zigzag traversal of the tree.
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

// Function to store the zig zag order traversal of tree in a list
vector<int> zigZagTraversal(Node *root)
{
    vector<int> result;

    // If the root is null, return an empty result
    if (root == NULL)
        return result;

    // Initialize a queue and push the root node into it
    queue<Node *> q;
    q.push(root);

    // Variable to keep track of the current direction of traversal
    bool leftToRight = true;

    // While the queue is not empty
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);

        // Process each level
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();

            // Insert the node's data into the answer vector
            // The index depends on the current direction of traversal
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            // If the node has a left child, push it into the queue
            if (frontNode->left)
                q.push(frontNode->left);

            // If the node has a right child, push it into the queue
            if (frontNode->right)
                q.push(frontNode->right);
        }

        // Change the direction of traversal for the next level
        leftToRight = !leftToRight;

        // Add the current level's data to the result
        for (auto i : ans)
        {
            result.push_back(i);
        }
    }
    return result;
}

int main(){
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(5);
    cout<<"Zig Zag Traversal: ";
    vector<int> result = zigZagTraversal(root);
    for(auto i: result){
        cout<<i<<" ";
    }
    return 0;
}