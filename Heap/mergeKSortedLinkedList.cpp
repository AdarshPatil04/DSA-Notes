/**
// approach 1
//  vector<int> ans; -> sc=O(N*K)
//  join all LL
//  Replace LL nodes data with vector data
// TC = N*KLog(K) + (N*K) + (N*K)

// approach 2
//  minheap -> fist element of k-LL
// ans LL -> head/tail -> head used to return and tail for insertion
// while(minHeap is not empty logic)
// SC => O(K)
// TC => O(KLogK) + O(N*KLogK) => O(N*KLogK) => O(NLogK)
 * This code demonstrates how to merge k sorted linked lists into one sorted list using a min heap.
 * The code defines a Node class for singly linked list and a compare class for the priority queue.
 * The mergeKLists function takes a vector of linked lists as input and returns the head of the final sorted list.
 * The code uses a min heap to store the smallest element not yet added to the final sorted list from each list.
 * It iteratively selects the smallest node from the min heap, adds it to the final sorted list, and updates the min heap.
 * Finally, the code prints the data in each node of the merged list.
 */

#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;       // The value of the node
    Node *next;     // Pointer to the next node in the list
    Node(int value) // Constructor
    {
        data = value;
        next = NULL;
    }
};

// Comparator class for the priority queue
class compare
{
public:
    // Overloads the () operator to compare two nodes
    bool operator()(Node *a, Node *b)
    {
        // Returns true if a's data is greater than b's data
        return a->data > b->data;
    }
};

// Function to merge k sorted linked lists
Node *mergeKLists(vector<Node *> &listArray)
{
    // Min heap to store the smallest element not yet added to the final sorted list from each list
    priority_queue<Node *, vector<Node *>, compare> minHeap;

    int k = listArray.size(); // The number of linked lists
    if (k == 0)               // If there are no linked lists, return NULL
        return NULL;

    // Insert the first node of each linked list into the min heap
    for (int i = 0; i < k; i++)
    {
        if (listArray[i] != NULL) // If the linked list is not empty
        {
            minHeap.push(listArray[i]); // Push the first node of the list into the min heap
        }
    }

    Node *head = NULL; // Head of the final sorted list
    Node *tail = NULL; // Tail of the final sorted list

    // While the min heap is not empty
    while (!minHeap.empty())
    {
        // Get the smallest node from the min heap
        Node *top = minHeap.top();
        minHeap.pop();

        // If there is a next node in the smallest node's list
        if (top->next != NULL)
        {
            // Push the next node into the min heap
            minHeap.push(top->next);
        }

        // If the final sorted list is empty
        if (head == NULL)
        {
            // Set the head and tail to the smallest node
            head = top;
            tail = top;
        }
        else // If the final sorted list is not empty
        {
            // Add the smallest node to the end of the list
            tail->next = top;
            tail = top; // Update the tail
        }
    }

    // Return the head of the final sorted list
    return head;
}

int main()
{
    vector<Node *> listArray; // Vector to store the linked lists

    // First linked list
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    listArray.push_back(head1); // Add the first linked list to the vector

    // Second linked list
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    listArray.push_back(head2); // Add the second linked list to the vector

    // Third linked list
    Node *head3 = new Node(0);
    head3->next = new Node(7);
    head3->next->next = new Node(8);
    listArray.push_back(head3); // Add the third linked list to the vector

    // Merge the linked lists into one sorted list
    Node *mergedList = mergeKLists(listArray);

    // Print the data in each node of the merged list
    while (mergedList != NULL)
    {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }

    return 0;
}
