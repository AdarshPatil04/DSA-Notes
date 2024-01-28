
/**
 * @brief This program demonstrates the bottom view of a binary tree.
 * 
 * The bottom view of a binary tree is the list of nodes visible from the bottom view
 * from left to right. It uses a map to store the horizontal distance of each node
 * from the root node and a queue to perform a level order traversal of the tree.
 * The program returns a vector containing the node values of the bottom view.
 * 
 * @return int The exit status of the program.
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

// Function to return a list of nodes visible from the bottom view
// from left to right in Binary Tree.
vector<int> bottomView(Node *root)
{
    // ans: a vector to hold the final bottom view
    vector<int> ans;

    // If root is NULL, return empty vector
    if (root == NULL)
    {
        return ans;
    }

    // bottomNode: a map to hold horizontal distance and node data
    map<int, int> bottomNode;

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

        // Update the node data for the current horizontal distance
        bottomNode[hd] = frontNode->data;

        // If left child exists, push it to queue with horizontal distance decreased by 1
        if (frontNode->left)
            q.push(make_pair(frontNode->left, hd - 1));

        // If right child exists, push it to queue with horizontal distance increased by 1
        if (frontNode->right)
            q.push(make_pair(frontNode->right, hd + 1));
    }

    // Traverse the map bottomNode
    for (auto i : bottomNode)
    {
        // Push node data to ans vector
        ans.push_back(i.second);
    }

    // Return the final bottom view
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
    cout << "Bottom view of the binary tree: ";
    vector<int> ans = bottomView(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
