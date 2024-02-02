/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @brief This code finds the predecessor and successor of a given key in a binary search tree.
 *
 * The code defines a Node class to represent each node in the binary search tree. It then implements
 * a function called predecessorSuccessor that takes the root of the binary search tree and a key as
 * input and returns the predecessor and successor of the key as a pair. The function uses an iterative
 * approach to traverse the binary search tree and find the predecessor and successor. Finally, the main
 * function constructs a binary search tree, calls the predecessorSuccessor function to find the predecessor
 * and successor of a given key, and prints the result.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class to represent each node in the binary search tree
class Node
{
public:
    int data;    // data of the node
    Node *left;  // pointer to the left child
    Node *right; // pointer to the right child

    // constructor to initialize a new node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to find the predecessor and successor of a given key in the binary search tree
pair<int, int> predecessorSuccessor(Node *root, int key)
{
    // Initialize the current node as root
    Node *temp = root;

    // Initialize the predecessor and successor as -1
    int pred = -1;
    int succ = -1;

    // Traverse the binary search tree until the current node's data equals the key
    while (temp->data != key)
    {
        // If the current node's data is greater than the key, update the successor and move to the left child
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        // If the current node's data is less than the key, update the predecessor and move to the right child
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    // Find the predecessor
    Node *leftTree = temp->left;
    while (leftTree != NULL)
    {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }

    // Find the successor
    Node *rightTree = temp->right;
    while (rightTree != NULL)
    {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }

    // Return the predecessor and successor as a pair
    return {pred, succ};
}

int main()
{
    // Construct the binary search tree
    Node *root = new Node(5);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    // Find the predecessor and successor of 6 in the binary search tree
    pair<int, int> ans = predecessorSuccessor(root, 6);

    // Print the predecessor and successor
    cout << "Predecessor and Successor of 6: " << ans.first << " " << ans.second << endl;

    return 0;
}
