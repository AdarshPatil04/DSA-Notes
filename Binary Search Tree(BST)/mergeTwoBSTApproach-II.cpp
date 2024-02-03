/**
 * Time Complexity: O(m+n), where m and n are the number of nodes in the two BSTs
 * Space Complexity: O(h1+h2), where h1 and h2 are the heights of the two BSTs
 * @brief This program demonstrates how to merge two Binary Search Trees (BSTs).
 *        It converts each BST into a sorted doubly linked list (DLL), merges the two DLLs,
 *        and then converts the merged DLL back into a balanced BST.
 *        The program also includes functions for converting a BST into a sorted DLL,
 *        merging two sorted DLLs, counting the number of nodes in a DLL,
 *        converting a sorted DLL into a balanced BST, and performing inorder and level order traversals of a BST.
 *
 * @details The program defines a Node structure to represent a Node in the binary tree.
 *          It includes functions to convert a BST into a sorted DLL, merge two sorted DLLs,
 *          count the number of nodes in a DLL, convert a sorted DLL into a balanced BST,
 *          merge two BSTs, perform inorder and level order traversals of a BST.
 *          The main function creates two BSTs, merges them, and prints the inorder and level order traversals of the merged BST.
 *
 * @note The time complexity of merging two BSTs is O(m+n), where m and n are the number of nodes in the two BSTs.
 *       The space complexity is O(h1+h2), where h1 and h2 are the heights of the two BSTs.
 *       The time complexity of converting a BST into a sorted DLL is O(n), where n is the number of nodes in the BST.
 *       The space complexity is O(h), where h is the height of the BST.
 *       The time complexity of merging two sorted DLLs is O(m+n), where m and n are the sizes of the two DLLs.
 *       The space complexity is O(1), as no extra space is used.
 *       The time complexity of counting the number of nodes in a DLL is O(n), where n is the number of nodes in the DLL.
 *       The space complexity is O(1), as no extra space is used.
 *       The time complexity of converting a sorted DLL into a balanced BST is O(n), where n is the number of nodes in the DLL.
 *       The space complexity is O(log n), where n is the number of nodes in the DLL.
 *       The time complexity of performing an inorder traversal of a BST is O(n), where n is the number of nodes in the BST.
 *       The space complexity is O(h), where h is the height of the BST.
 *       The time complexity of performing a level order traversal of a BST is O(n), where n is the number of nodes in the BST.
 *       The space complexity is O(n), as a queue is used to store the nodes.
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

// Function to convert a BST into a sorted doubly linked list
// Time Complexity: O(n), where n is the number of nodes in the BST
// Space Complexity: O(h), where h is the height of the BST
void convertIntoSortedDLL(Node *root, Node *&head)
{
    // Base case
    if (root == NULL)
        return;

    // Recursively convert right subtree
    convertIntoSortedDLL(root->right, head);

    // Insert root into DLL
    root->right = head;

    // Change left pointer of previous head
    if (head != NULL)
        head->left = root;

    // Change head of DLL
    head = root;

    // Recursively convert left subtree
    convertIntoSortedDLL(root->left, head);
}

// Function to merge two sorted doubly linked lists
// Time Complexity: O(m+n), where m and n are the sizes of the two linked lists
// Space Complexity: O(1), as no extra space is used
Node *mergeLL(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    // Merge lists while both are non-empty
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    // Append remaining nodes of list1
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    // Append remaining nodes of list2
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Function to count the number of nodes in a doubly linked list
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(1), as no extra space is used
int countNodes(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// Function to convert a sorted doubly linked list to a balanced BST
// Time Complexity: O(n), where n is the number of nodes in the linked list
// Space Complexity: O(log n), where n is the number of nodes in the linked list
Node *sortedDLLToBST(Node *&head, int n)
{
    // Base case
    if (n <= 0)
        return NULL;

    // Recursively construct the left subtree
    Node *left = sortedDLLToBST(head, n / 2);

    // Allocate memory for root, and link the left subtree with root
    Node *root = head;
    root->left = left;

    // Change head pointer to next
    head = head->right;

    // Recursively construct the right subtree and link it with root
    root->right = sortedDLLToBST(head, n - n / 2 - 1);

    return root;
}

// Function to merge two BSTs
// Time Complexity: O(m+n), where m and n are the number of nodes in the two BSTs
// Space Complexity: O(h1+h2), where h1 and h2 are the heights of the two BSTs
Node *mergeBST(Node *root1, Node *root2)
{
    Node *head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1->left = NULL;

    Node *head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2->left = NULL;

    // Merge two sorted doubly linked lists
    Node *head = mergeLL(head1, head2);

    // Convert sorted linked list into BST
    return sortedDLLToBST(head, countNodes(head));
}

// Function to do inorder traversal of BST
// Time Complexity: O(n), where n is the number of nodes in the BST
// Space Complexity: O(h), where h is the height of the BST
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

// Function to perform level order traversal (Breadth-First Search) of the binary tree
// Time Complexity: O(n), where n is the number of nodes in the BST
// Space Complexity: O(n), as a queue is used to store the nodes
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
    // Create a Binary Search Tree (BST) as shown below
    //       5
    //      / \
    //     3   6
    //    / \   \
    //   2   4   8
    Node *root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(6);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->right = new Node(8);
    Node *temp1 = root1;
    cout << "Inorder Traversal of the first BST: ";
    inorder(temp1);
    cout << endl;

    // Create another Binary Search Tree (BST) as shown below
    //       7
    //      / \
    //     1   9
    //      \
    //       5
    Node *root2 = new Node(7);
    root2->left = new Node(1);
    root2->right = new Node(9);
    root2->left->right = new Node(5);
    Node *temp2 = root2;
    cout << "Inorder Traversal of the second BST: ";
    inorder(temp2);
    cout << endl;

    // Merge the two BSTs
    Node *mergedBST = mergeBST(root1, root2);

    // Print inorder traversal of the merged BST
    cout << "Inorder traversal of the merged BST is: ";
    inorder(mergedBST);
    cout << endl;
    // Print the level order traversal of the merged BST
    cout << "Level order traversal of the merged BST:" << endl;
    levelOrderTraversal(mergedBST);
    return 0;
}
