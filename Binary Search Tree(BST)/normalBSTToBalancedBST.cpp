#include <bits/stdc++.h>
using namespace std;

// Define the structure of a Node in the binary tree
class Node
{
public:
    int data;    // Data to be stored in the Node
    Node *left;  // Pointer to the left child Node
    Node *right; // Pointer to the right child Node

    // Constructor to initialize a new Node
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to perform inorder traversal and store the node values in a vector
void inorder(Node *root, vector<int> &in)
{
    // Base case: if the node is null, return
    if (root == NULL)
        return;

    // Traverse the left subtree
    inorder(root->left, in);

    // Store the node value in the vector
    in.push_back(root->data);

    // Traverse the right subtree
    inorder(root->right, in);
}

Node *inorderToBST(int s, int e, vector<int> &v)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;

    Node *newRoot = new Node(v[mid]);

    newRoot->left = inorderToBST(s, mid - 1, v);
    newRoot->right = inorderToBST(mid + 1, e, v);
    return newRoot;
}

Node *balancedBst(Node *root)
{
    vector<int> v;

    // store inorder -> sorted values
    inorder(root, v);

    return inorderToBST(0, v.size() - 1, v);
}

// Function to print the level order traversal of the binary tree
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

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
            cout << temp->data << " ";  
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Function to print the inorder traversal of the binary tree
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    // Construct the binary tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    root->right->right->right = new Node(30);
    root->right->right->right->right = new Node(35);
    cout << "Level order traversal of the binary tree before balancing:" << endl;
    levelOrderTraversal(root);
    root = balancedBst(root);
    cout << "Level order traversal of the binary tree before balancing:" << endl;
    levelOrderTraversal(root);
    return 0;
}