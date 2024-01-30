/**
 * Time complexity: O(n)
 * Space complexity: O(n)
 * @brief This code calculates the minimum time required for the entire binary tree to burn, starting from a target node.
 * 
 * The code defines a binary tree node structure and implements functions to create a mapping from each node to its parent,
 * find the target node, simulate the burning process, and calculate the minimum time required for the entire tree to burn.
 * 
 * The main function creates a binary tree, specifies a target node, and calls the minTime function to get the result.
 * The result is then printed to the console.
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

// Function to create a mapping from each node to its parent and find the target node
Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
{
    Node *result = NULL;       // To store the target node
    queue<Node *> q;           // Queue for BFS traversal
    q.push(root);              // Start BFS from the root
    nodeToParent[root] = NULL; // Root has no parent

    // Standard BFS loop
    while (!q.empty())
    {
        Node *front = q.front();
        q.pop();

        // If the current node is the target node, store it in result
        if (front->data == target)
        {
            result = front;
        }
        // If the current node has a left child, add it to the queue and map
        if (front->left)
        {
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        // If the current node has a right child, add it to the queue and map
        if (front->right)
        {
            nodeToParent[front->right] = front;
            q.push(front->right);
        }
    }
    // Return the target node
    return result;
}

// Function to simulate the burning process and return the minimum time required for the entire tree to burn
int burnTree(Node *root, map<Node *, Node *> &nodeToParent)
{
    map<Node *, bool> visited; // To keep track of visited nodes
    queue<Node *> q;           // Queue for BFS traversal
    q.push(root);              // Start BFS from the root
    visited[root] = true;      // Mark root as visited

    int answer = 0; // To store the minimum time required for the entire tree to burn

    // Standard BFS loop
    while (!q.empty())
    {
        int size = q.size(); // Number of nodes at the current level
        bool flag = false;   // To check if any new nodes are burned at the current level

        // Process all nodes at the current level
        for (int i = 0; i < size; i++)
        {
            Node *front = q.front();
            q.pop();

            // If the current node has a left child and it has not been visited, add it to the queue and mark it as visited
            if (front->left && !visited[front->left])
            {
                visited[front->left] = true;
                q.push(front->left);
                flag = true;
            }
            // If the current node has a right child and it has not been visited, add it to the queue and mark it as visited
            if (front->right && !visited[front->right])
            {
                visited[front->right] = true;
                q.push(front->right);
                flag = true;
            }
            // If the parent of the current node exists and it has not been visited, add it to the queue and mark it as visited
            if (nodeToParent[front] && !visited[nodeToParent[front]])
            {
                visited[nodeToParent[front]] = true;
                q.push(nodeToParent[front]);
                flag = true;
            }
        }
        // If any new nodes are burned at the current level, increment answer
        if (flag)
        {
            answer++;
        }
    }
    // Return the minimum time required for the entire tree to burn
    return answer;
}

// Function to return the minimum time required for the entire tree to burn, starting from the target node
int minTime(Node *root, int target)
{
    map<Node *, Node *> nodeToParent;                                   // To store the parent of each node
    Node *targetNode = createParentMapping(root, target, nodeToParent); // Find the target node and create the parent mapping
    int answer = burnTree(targetNode, nodeToParent);                    // Simulate the burning process and get the minimum time required
    return answer;                                                      // Return the minimum time required
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);

    int target = 2;

    int answer = minTime(root, target);
    cout << answer << endl;
    return 0;
}
