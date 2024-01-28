
/**
 * @brief This code demonstrates the diagonal traversal of a binary tree.
 * 
 * The diagonal traversal of a binary tree involves printing the nodes of the tree in a diagonal pattern.
 * The nodes are printed from the top-left to the bottom-right diagonal.
 * 
 * The code defines a Node class to represent a node in the binary tree.
 * It also includes a recursive function to fill a map with nodes at each diagonal.
 * The diagonalFill function uses depth-first search to traverse the tree and add nodes to the map.
 * Finally, the diagonalTraversal function prints the nodes in the diagonal order using the map.
 * 
 * The main function creates a binary tree and performs the diagonal traversal on it.
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

// Recursive function to fill the map with nodes at each diagonal
void diagonalFill(Node *root, int d, map<int,vector<int>> &diagonal)
{
    // Base case: if the root is NULL, return
    if(root == NULL)
        return;

    // Add the node's data to its corresponding diagonal in the map
    diagonal[d].push_back(root->data);

    // For left child, the diagonal distance is d + 1
    diagonalFill(root->left, d + 1, diagonal);

    // For right child, the diagonal distance is same as the node's
    diagonalFill(root->right, d, diagonal);
}

// Function to perform diagonal traversal on the binary tree
void diagonalTraversal(Node* root) {
    // Map to hold nodes at each diagonal
    map<int,vector<int>> diagonal;

    // Fill the map with nodes at each diagonal
    diagonalFill(root, 0, diagonal);

    // Print the diagonal traversal
    for(auto it : diagonal) {
        for(auto i : it.second)
            cout << i << " ";
        cout << endl;
    }
}

int main() {
    // Create a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->right = new Node(6);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(7);
    root->left->right->right->right = new Node(8);

    // Perform diagonal traversal on the binary tree
    cout << "Diagonal Traversal: " << endl;
    diagonalTraversal(root);

    return 0;
}
