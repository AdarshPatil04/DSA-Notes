/**
 * @brief This code implements the vertical order traversal of a binary tree.
 * 
 * The vertical order traversal of a binary tree is a traversal in which nodes are visited in a top-down manner, 
 * starting from the leftmost vertical line and moving towards the right. Nodes at the same vertical line are visited 
 * in the order of their level in the tree.
 * 
 * The code uses a map to store nodes based on their horizontal distance and level. It uses a queue to perform a level 
 * order traversal of the binary tree. The nodes are pushed into the map based on their horizontal distance and level. 
 * Finally, the nodes are traversed in the map and added to the final vertical order traversal vector.
 * 
 * @param root Pointer to the root node of the binary tree.
 * @return A vector containing the vertical order traversal of the binary tree.
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

// Function to find the vertical order traversal of Binary Tree.
vector<int> verticalOrder(Node *root)
{
    // nodes: a map to hold horizontal distance, level and node data
    map<int, map<int,vector<int> > > nodes;
    
    // q: a queue to hold node and its horizontal distance and level
    queue< pair<Node*, pair<int,int> > > q;
    
    // ans: a vector to hold the final vertical order traversal
    vector<int> ans;
    
    // If root is NULL, return empty vector
    if(root == NULL)
        return ans;
        
    // Push root to queue with horizontal distance and level as 0
    q.push(make_pair(root, make_pair(0,0)));
    
    // While there are nodes in queue
    while(!q.empty()) {
        // Pop a node from queue
        pair<Node*, pair<int,int> > temp = q.front();
        q.pop();
        
        // Get the node, horizontal distance and level
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;
        
        // Push node data to corresponding horizontal distance and level in map
        nodes[hd][lvl].push_back(frontNode->data);
        
        // If left child exists, push it to queue with horizontal distance decreased by 1 and level increased by 1
        if(frontNode->left)
            q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
            
        // If right child exists, push it to queue with horizontal distance increased by 1 and level increased by 1
        if(frontNode->right)
            q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
    }
    
    // Traverse the map nodes
    for(auto i: nodes) {
        for(auto j:i.second) {
            for(auto k:j.second)
            {
                // Push node data to ans vector
                ans.push_back(k);
            }
        }
    }
    
    // Return the final vertical order traversal
    return ans;
}

int main()
{
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    
    // Print the vertical order traversal of the binary tree
    cout << "Vertical order traversal of the binary tree: ";
    vector<int> ans = verticalOrder(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
