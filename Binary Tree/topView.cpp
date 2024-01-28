/**
 * @file topView.cpp
 * @brief This file contains the implementation of a function to return the top view of a binary tree.
 * The top view of a binary tree is defined as the nodes visible from the top when looking at the tree from left to right.
 * The function uses a map to store the nodes at each horizontal distance from the root.
 * It performs a level order traversal of the tree using a queue and updates the map with the first node encountered at each horizontal distance.
 * Finally, it returns a vector containing the nodes in the top view from left to right.
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

// Function to return a list of nodes visible from the top view
// from left to right in Binary Tree.
vector<int> topView(Node *root)
{
    // ans: a vector to hold the final top view
    vector<int> ans;

    // If root is NULL, return empty vector
    if (root == NULL)
    {
        return ans;
    }

    // topNode: a map to hold horizontal distance and node data
    map<int, int> topNode;

    // q: a queue to hold node and its horizontal distance
    queue<pair<Node *, int>> q;

    // Push root to queue with horizontal distance as 0
    q.push(make_pair(root, 0));

    // While there are nodes in queue
    while (!q.empty())
    {
        // Pop a node from queue
        pair<Node *, int> temp = q.front();
        q.pop();

        // Get the node and horizontal distance
        Node *frontNode = temp.first;
        int hd = temp.second;

        // If no value is present for a horizontal distance in map, add node data
        if (topNode.find(hd) == topNode.end()) // topNode.end() return a fixed iterator "past the end"
            topNode[hd] = frontNode->data;

        // If left child exists, push it to queue with horizontal distance decreased by 1
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        // If right child exists, push it to queue with horizontal distance increased by 1
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // Traverse the map topNode
    for (auto i : topNode)
    {
        // Push node data to ans vector
        ans.push_back(i.second);
    }

    // Return the final top view
    return ans;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);
    cout << "Top view of the binary tree: ";
    vector<int> ans = topView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
