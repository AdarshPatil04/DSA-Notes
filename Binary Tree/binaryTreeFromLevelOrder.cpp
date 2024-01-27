/**
 * @brief This program demonstrates how to build a binary tree from level order input.
 *        It prompts the user to enter the data for each node in level order and creates
 *        the binary tree accordingly. The program uses a queue to store the nodes of the
 *        binary tree and performs a breadth-first search to build the tree.
 * Input: 3 4 5 6 -1 -1 7 -1 -1 -1 -1
 * OutputL 3 4 5 6 7
 */
#include <bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

// Function to build a binary tree from level order input
void buildFromLevelOrder(node* &root) {
    queue<node*> q; // Queue to store the nodes of the binary tree

    // Input the data for the root node
    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root); // Push the root node into the queue

    // While the queue is not empty
    while(!q.empty()) {
        node* temp = q.front(); // Store the front element of the queue in temp
        q.pop(); // Pop the front element of the queue

        // Input the left and right child of the node
        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        // If the left child exists, create a node and push it into the queue
        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        // Input the right child of the node
        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        // If the right child exists, create a node and push it into the queue
        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
}

int main() {
    node* root = NULL;
    buildFromLevelOrder(root); // Build the binary tree from level order input
    return 0;
}
