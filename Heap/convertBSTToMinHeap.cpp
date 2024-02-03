/**
 * @brief This program demonstrates the conversion of a binary search tree (BST) into a min heap.
 *        It performs an in-order traversal of the BST to obtain a sorted list of Node values.
 *        Then, it uses a pre-order traversal to replace the Node values in the BST with the values from the sorted list.
 *        Finally, it prints the level order traversal of the BST before and after the conversion.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class to represent a Node in a binary tree
class Node
{
public:
    int data;    // data stored in the Node
    Node *left;  // pointer to the left child Node
    Node *right; // pointer to the right child Node

    // constructor to initialize a new Node
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to perform in-order traversal of the binary tree and store the Node values in a vector
void inOrder(Node *root, vector<int> &v)
{
    // base case: if the Node is null, return
    if (root == NULL)
        return;

    // first recur for the left subtree
    inOrder(root->left, v);
    // then save the value of the Node
    v.push_back(root->data);
    // finally recur for the right subtree
    inOrder(root->right, v);
}

// Function to convert a binary tree into a min heap using pre-order traversal
void preOrder(Node *root, vector<int> &v, int &index)
{
    // base case: if the Node is null, return
    if (!root)
        return;

    // first replace the root Node value with the next value from the sorted list
    root->data = v[index++];
    // then recur for the left subtree
    preOrder(root->left, v, index);
    // finally recur for the right subtree
    preOrder(root->right, v, index);
}

// Function to convert a binary search tree into a min heap
Node *convertBSTToMinHeap(Node *root)
{
    // edge case: if the tree is empty, return null
    if (root == NULL)
        return NULL;

    // vector to store the in-order traversal of the tree
    vector<int> v;
    // perform in-order traversal and fill the vector
    inOrder(root, v);
    // variable to keep track of the index in the vector
    int index = 0;
    // convert the binary tree into a min heap using pre-order traversal
    preOrder(root, v, index);
    // return the root of the converted tree
    return root;
}

// Function to perform level order traversal of the binary tree
void levelOrderTraversal(Node *root)
{
    queue<Node *> q; // Queue to store the Nodes of the binary tree
    q.push(root);    // Push the root Node into the queue
    q.push(NULL);    // Push NULL into the queue to mark the end of the current level

    // While the queue is not empty
    while (!q.empty())
    {
        Node *temp = q.front(); // Store the front Node of the queue in temp
        q.pop();                // Pop the front Node from the queue

        // If temp is NULL, print a new line and push NULL into the queue if it is not empty
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            // Print the data of the Node and push its left and right child Nodes into the queue if they exist
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    Node *temp = root;
    // Perform level order traversal of the tree before conversion
    cout << "Level Order Traversal of the tree before conversion: \n";
    levelOrderTraversal(temp);

    // Convert the binary search tree into a min heap
    root = convertBSTToMinHeap(root);

    // Perform level order traversal of the tree after conversion
    cout << "Level Order Traversal of the tree after conversion: \n";
    levelOrderTraversal(root);

    return 0;
}
