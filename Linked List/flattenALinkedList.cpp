/**
 * @brief This program demonstrates the flattening of a linked list.
 * 
 * The program defines a Node class for a doubly linked list and implements
 * functions to merge two sorted linked lists and flatten a linked list.
 * The flatten function recursively flattens the linked list by merging
 * each node with its next node and returns the flattened list.
 * The main function creates a sample linked list, flattens it, and prints
 * the flattened list.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node *next, *bottom;
    Node(int value)
    {
        data = value;
        next = NULL;
        bottom = NULL;
    }
};

// Function to merge two sorted linked list
Node* merge(Node* a, Node* b) {
    // If a is NULL return b and if b is NULL return a
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Node* result; // Initialize result
    // If a->data is less than b->data
    if (a->data < b->data) {
        result = a; // Make a as result
        result->bottom = merge(a->bottom, b); // Recursively merge the bottom of a and b and store the result in result->bottom
    } else {
        result = b; // Make b as result
        result->bottom = merge(a, b->bottom); // Recursively merge the bottom of a and b and store the result in result->bottom
    }
    result->next = NULL; // Make next of result as NULL
    return result; // Return result
}

// Function to flatten a linked list
Node* flatten(Node* root) {
    // If root is NULL or root is the only node
    if (root == NULL || root->next == NULL)
        return root;
    root->next = flatten(root->next); // Recursively flatten the next node that is next of root is flattened and stored in root->next
    root = merge(root, root->next); // Merge the root and root->next and store the result in root and return root
    return root;
}

int main(){
    Node* root = new Node(5);
    root->next = new Node(10);
    root->next->next = new Node(19);
    root->next->next->next = new Node(28);
    root->next->next->next->next = new Node(7);
    root->next->bottom = new Node(20);
    root->next->next->bottom = new Node(22);
    root->next->next->next->bottom = new Node(35);
    root->next->next->next->next->bottom = new Node(8);
    root->next->bottom->bottom = new Node(50);
    root->next->next->bottom->bottom = new Node(40);
    root->next->next->next->bottom->bottom = new Node(45);
    root->next->next->next->next->bottom->bottom = new Node(30);
    /*5 10 19 28 7
        20 22 35 8
        50 40 45 30*/  
    root = flatten(root);
    // 5 7 8 10 19 20 22 28 30 35 40 45 50
    // Node* root = new Node(1);
    // root->next = new Node(8);
    // root->next->next = new Node(18);
    // root->next->next->next = new Node(29);
    // root->bottom = new Node(2);
    // root->bottom->bottom = new Node(3);
    // root->next->bottom = new Node(10);
    // root->next->bottom->bottom = new Node(15);
    // root->next->next->bottom = new Node(22);
    // /*1 8 18 29
    //   2 10 22
    //   3 15*/
    // root = flatten(root);
    // // 1 2 3 8 10 15 18 22 29
    while (root != NULL) {
        cout << root->data << " ";
        root = root->bottom;
    }
    cout << endl;
    return 0;
}
