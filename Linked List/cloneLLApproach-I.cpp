/**
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 * This code demonstrates the cloning of a singly linked list with random pointers.
 * The code creates a linked list with random pointers and then creates a clone of the linked list.
 * The clone is created by iterating through the original linked list and creating a new node for each node in the original list.
 * The random pointers of the clone are set by mapping the original nodes to their corresponding clone nodes using a hash map.
 * Finally, the original linked list and the cloned linked list are printed to verify the correctness of the cloning process.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node(int value)
    {
        data = value;
        next = NULL;
        random = NULL;
    }
};

// Function to insert a node at the tail of linked list
void insertAtTail(Node *&head, Node *&tail, int val)
{
    Node *temp = new Node(val); // Create a new node
    // if head is NULL
    if (head == NULL)
    {
        head = temp; // Make temp as head
        tail = temp; // Make temp as tail
        return;      // Return
    }
    // if head is not NULL
    else
    {
        tail->next = temp; // Make temp as next of tail
        tail = temp;       // Make temp as tail
    }
}

// Function to copy a linked list
Node *copyList(Node *head)
{
    Node *cloneHead = NULL; // Initialize cloneHead as NULL
    Node *cloneTail = NULL; // Initialize cloneTail as NULL
    Node *temp = head;      // Initialize temp as head
    // Loop till temp is not NULL
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data); // Insert temp->data at tail of clone linked list
        temp = temp->next;                              // Move temp one step ahead
    }
    unordered_map<Node *, Node *> oldToNewNode; // Create a map to store old node to new node mapping
    Node *originalNode = head;                  // Initialize originalNode as head
    Node *cloneNode = cloneHead;                // Initialize cloneNode as cloneHead
    // Loop till originalNode is not NULL
    while (originalNode != NULL)
    {
        oldToNewNode[originalNode] = cloneNode; // Store originalNode and cloneNode in map
        originalNode = originalNode->next;      // Move originalNode one step ahead
        cloneNode = cloneNode->next;            // Move cloneNode one step ahead
    }
    originalNode = head;   // Initialize originalNode as head
    cloneNode = cloneHead; // Initialize cloneNode as cloneHead
    // Loop till originalNode is not NULL
    while (originalNode != NULL)
    {
        cloneNode->random = oldToNewNode[originalNode->random]; // Make the random of cloneNode as the node mapped to originalNode->random
        originalNode = originalNode->next;                      // Move originalNode one step ahead
        cloneNode = cloneNode->next;                            // Move cloneNode one step ahead
    }
    return cloneHead; // Return the head of cloned linked list
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    // Making a random linked list
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 5);
    // Making a random linked list
    head->random = tail;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next->next->next;
    head->next->next->next->next->random = head->next;
    Node *temp = head;
    cout << "Original linked List data: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = head;
    cout << "Original random data: " << endl;
    while (temp != NULL)
    {
        cout << temp->random->data << " ";
        temp = temp->next;
    }
    cout << endl;
    Node *cloneHead = copyList(head);
    temp = cloneHead;
    cout << "Cloned linked List data: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    temp = cloneHead;
    cout << "Cloned random data: " << endl;
    while (temp != NULL)
    {
        cout << temp->random->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
