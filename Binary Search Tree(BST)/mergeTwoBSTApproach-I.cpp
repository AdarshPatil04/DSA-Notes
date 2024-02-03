/**
 * This code merges two Binary Search Trees (BSTs) into a single BST.
 * It performs the following steps:
 * 1. Traverses both BSTs in inorder and stores the elements in two separate arrays.
 * 2. Merges the two sorted arrays into a single sorted array.
 * 3. Constructs a new BST using the merged sorted array.
 * 4. Prints the inorder and level order traversal of the merged BST.
 * 
 * Time Complexity: O(m + n), where m and n are the number of nodes in the two BSTs respectively.
 * Space Complexity: O(m + n), as it uses additional space to store the inorder traversal of the two BSTs and the merged array.
 */
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

// Function to perform inorder traversal of the binary tree
void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }

    // First recur for left subtree
    inorder(root->left, in);
    // Then store the data of node
    in.push_back(root->data);
    // Now recur for right subtree
    inorder(root->right, in);
}

// Function to perform level order traversal (Breadth-First Search) of the binary tree
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

// Function to merge two sorted arrays
vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0, k = 0;

    // Traverse both array
    while (i < a.size() && j < b.size())
    {
        // Check if current element of first array is smaller than current element of second array.
        // If yes, store first array element and increment first array index. Otherwise do same with second array
        if (a[i] < b[j])
        {
            ans[k++] = a[i++];
        }
        else
        {
            ans[k++] = b[j++];
        }
    }

    // Store remaining elements of first array
    while (i < a.size())
    {
        ans[k++] = a[i++];
    }

    // Store remaining elements of second array
    while (j < b.size())
    {
        ans[k++] = b[j++];
    }

    return ans;
}

// Function to convert a sorted array to a balanced BST
Node *inorderToBST(int s, int e, vector<int> &in)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    // Get the middle element and make it root
    int mid = (s + e) / 2;

    Node *root = new Node(in[mid]);

    // Recursively construct the left subtree and make it left child of root
    root->left = inorderToBST(s, mid - 1, in);
    // Recursively construct the right subtree and make it right child of root
    root->right = inorderToBST(mid + 1, e, in);

    return root;
}

// Function to merge two BSTs into a single BST
Node *mergeBST(Node *root1, Node *root2)
{
    // step1 : store inorder
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    // step 2 : merge two sorted array/vector
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    // step 3 : create Tree using inorderToBST
    //(use merged inorder array to build)
    int s = 0;
    int e = mergeArray.size() - 1;

    return inorderToBST(s, e, mergeArray);
}

int main()
{
    // Create the first BST
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(1);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);
    cout << "Inorder Traversal of the first BST: " << endl;
    vector<int> in1;
    inorder(root1, in1);
    for (int i = 0; i < in1.size(); i++)
    {
        cout << in1[i] << " ";
    }
    // Create the second BST
    Node *root2 = new Node(10);
    root2->left = new Node(9);
    root2->right = new Node(11);
    root2->left->left = new Node(8);
    root2->left->right = new Node(12);
    root2->right->left = new Node(7);
    root2->right->right = new Node(13);
    cout << endl
         << "Inorder Traversal of the second BST: " << endl;
    vector<int> in2;
    inorder(root2, in2);
    for (int i = 0; i < in2.size(); i++)
    {
        cout << in2[i] << " ";
    }
    cout << endl;
    // Merge the two BSTs
    Node *mergedBST = mergeBST(root1, root2);
    Node *temp = mergedBST;
    // Print the inorder traversal of the merged BST
    cout << "Inorder Traversal of the Merged BST: " << endl;
    vector<int> in;
    inorder(mergedBST, in);
    for (int i = 0; i < in.size(); i++)
    {
        cout << in[i] << " ";
    }
    cout << endl;

    // Print the level order traversal of the merged BST
    cout << "Level Order Traversal of the Merged BST: " << endl;
    levelOrderTraversal(temp);

    return 0;
}
