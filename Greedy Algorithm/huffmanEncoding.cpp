/**
 * Time Complexity: O(nlogn)
 * Space Complexity: O(n)
 * @file huffmanEncoding.cpp
 * @brief This file contains the implementation of the Huffman encoding algorithm.
 *
 * The Huffman encoding algorithm is used to compress data by assigning variable-length codes to characters based on their frequencies.
 * This code implements the Huffman encoding algorithm to generate Huffman codes for a given string and its character frequencies.
 * The main function creates a Solution object, calls the huffmanCodes function to generate the Huffman codes, and prints the codes.
 */
// https://practice.geeksforgeeks.org/problems/huffman-encoding3345/1

#include <bits/stdc++.h>
using namespace std;

// Node class to represent the nodes of the Huffman tree
class Node
{
public:
    int data;    // Frequency of the character
    Node *left;  // Pointer to the left child node
    Node *right; // Pointer to the right child node

    // Constructor to initialize a new node
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

// Comparator class for the priority queue
class cmp
{
public:
    // Overload the () operator to compare two nodes
    bool operator()(Node *a, Node *b)
    {
        // Return true if the frequency of a is greater than the frequency of b
        return a->data > b->data;
    }
};

// Solution class to implement the Huffman encoding algorithm
class Solution
{
public:
    // Function to traverse the Huffman tree and generate the Huffman codes
    void traverse(Node *root, vector<string> &ans, string temp)
    {
        // Base case: if the node is a leaf node (it has no children)
        if (root->left == NULL && root->right == NULL)
        {
            // Add the Huffman code of the character to the answer vector
            ans.push_back(temp);
            return;
        }

        // Recursively traverse the left and right subtrees
        traverse(root->left, ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }

    // Function to generate the Huffman codes
    vector<string> huffmanCodes(string S, vector<int> f, int N)
    {
        // Create a min heap to store the nodes of the Huffman tree
        priority_queue<Node *, vector<Node *>, cmp> pq;

        // Create a new node for each character and add it to the min heap
        for (int i = 0; i < N; i++)
        {
            Node *temp = new Node(f[i]);
            pq.push(temp);
        }

        // Build the Huffman tree
        while (pq.size() > 1)
        {
            // Remove the two nodes with the smallest frequencies from the min heap
            Node *left = pq.top();
            pq.pop();
            Node *right = pq.top();
            pq.pop();

            // Create a new node with these two nodes as children and the sum of their frequencies as the frequency
            Node *newNode = new Node(left->data + right->data);
            newNode->left = left;
            newNode->right = right;

            // Add the new node to the min heap
            pq.push(newNode);
        }

        // The remaining node in the min heap is the root of the Huffman tree
        Node *root = pq.top();

        // Generate the Huffman codes by traversing the Huffman tree
        vector<string> ans;
        string temp = "";
        traverse(root, ans, temp);

        // Return the Huffman codes
        return ans;
    }
};

int main()
{
    // Given string
    string S = "abcdef";
    // Frequencies of the characters
    vector<int> f = {5, 9, 12, 13, 16, 45};
    // Number of characters
    int N = 6;
    // Create a Solution object
    Solution ob;
    // Generate and print the Huffman codes
    vector<string> ans = ob.huffmanCodes(S, f, N);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
