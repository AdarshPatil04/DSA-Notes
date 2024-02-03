/**
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * @brief This code checks whether a given binary tree is a max heap or not.
 *
 * The code defines a binary tree structure and a class Solution that contains
 * three helper functions: countNodes, isCBT, and isMaxOrder. The countNodes
 * function counts the number of nodes in the tree. The isCBT function checks
 * if the tree is a complete binary tree. The isMaxOrder function checks if the
 * tree satisfies the max heap property. Finally, the isHeap function combines
 * the results of the previous functions to determine if the tree is a max heap.
 *
 * The main function constructs a binary tree and calls the isHeap function to
 * check if it is a max heap. The result is printed to the console.
 */
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor to create a new node
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{

    // Function to count the number of nodes in the tree
    int countNodes(struct Node *tree)
    {
        // Base case
        if (tree == NULL)
            return 0;

        // Count the current node and the nodes in the left and right subtrees
        int ans = 1 + countNodes(tree->left) + countNodes(tree->right);
        return ans;
    }

    // Function to check if the tree is a complete binary tree
    bool isCBT(struct Node *tree, int index, int cnt)
    {
        if (tree == NULL)
            return true;

        // If the index is greater than or equal to the count, the tree is not complete
        if (index >= cnt)
        {
            return false;
        }
        else
        {
            // Check the left and right subtrees
            bool left = isCBT(tree->left, 2 * index + 1, cnt);
            bool right = isCBT(tree->right, 2 * index + 2, cnt);
            return (left && right);
        }
    }

    // Function to check if the tree is a max heap
    bool isMaxOrder(struct Node *root)
    {
        // If the node is a leaf node, it is a max heap
        if (root->left == NULL && root->right == NULL)
            return true;

        // If there is only a left child
        if (root->right == NULL)
        {
            // Check if the root is greater than the left child
            return (root->data > root->left->data);
        }
        else
        {
            // Check the left and right subtrees
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            // The tree is a max heap if the root is greater than both children
            // and the left and right subtrees are max heaps
            return (left && right &&
                    (root->data > root->left->data) && (root->data > root->right->data));
        }
    }

public:
    // Function to check if the tree is a max heap
    bool isHeap(struct Node *tree)
    {

        int index = 0;
        int totalCount = countNodes(tree);

        // The tree is a max heap if it is a complete binary tree and a max heap
        if (isCBT(tree, index, totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    // Construct the binary tree
    Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(0);
    cout << Solution().isHeap(root);
    return 0;
}
