/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * This code demonstrates the cloning of a linked list using an approach that modifies the original list.
 * The code creates a deep copy of the original linked list, where each node in the clone list has the same data value as the corresponding node in the original list.
 * The code also copies the random pointers of the original list to the clone list.
 * The cloning process involves several steps, including creating a clone list, inserting nodes of the clone list in between the original list, copying the random pointers, and reverting the changes made in the second step.
 * The code then prints the data values of the original and cloned linked lists, as well as the data values of their respective random pointers.
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
void insertAtTail(Node *&head, Node *&tail, int d)
{
    Node *newNode = new Node(d); // Create a new node
    // if head is NULL
    if (head == NULL)
    {
        head = newNode; // Make newNode as head
        tail = newNode; // Make newNode as tail
    }
    // if head is not NULL
    else
    {
        tail->next = newNode; // Make newNode as next of tail
        tail = newNode;       // Make newNode as tail
    }
}

// Function to copy a linked list
Node *copyList(Node *head)
{
    // step 1: Create a Clone List
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    Node *temp = head; // Initialize temp as head
    // Loop till temp is not NULL
    while (temp != NULL)
    {
        insertAtTail(cloneHead, cloneTail, temp->data); // Insert temp->data at tail of clone linked list
        temp = temp->next;                              // Move temp one step ahead
    }

    // step 2: insert nodes of Clone List in between originalList
    Node *originalNode = head;   // Initialize originalNode as head
    Node *cloneNode = cloneHead; // Initialize cloneNode as cloneHead
    // Loop till originalNode is not NULL
    while (originalNode != NULL && cloneNode != NULL)
    {
        Node *next = originalNode->next; // Store next of originalNode
        originalNode->next = cloneNode;  // Make cloneNode as next of originalNode
        originalNode = next;             // Move originalNode one step ahead
        next = cloneNode->next;          // Store next of cloneNode
        cloneNode->next = originalNode;  // Make originalNode as next of cloneNode
        cloneNode = next;                // Move cloneNode one step ahead
    }

    // step 3: Random pointer copy
    temp = head; // Initialize temp as head
    // Loop till temp is not NULL
    while (temp != NULL)
    {
        // Loop till next of temp is not NULL
        if (temp->next != NULL)
        {
            temp->next->random = temp->random ? temp->random->next : temp->random; // Make random of temp->next as next of random of temp
        }
        temp = temp->next->next; // Move temp by two steps
    }

    // step 4: revert step 2 changes
    originalNode = head;   // Initialize originalNode as head
    cloneNode = cloneHead; // Initialize cloneNode as cloneHead
    // Loop till originalNode is not NULL
    while (originalNode != NULL && cloneNode != NULL)
    {
        originalNode->next = cloneNode->next; // Make next of originalNode as next of cloneNode
        originalNode = originalNode->next;    // Move originalNode one step ahead
        // if originalNode is not NULL
        if (originalNode != NULL)
        {
            cloneNode->next = originalNode->next; // Make next of cloneNode as next of originalNode
            cloneNode = cloneNode->next;          // Move cloneNode one step ahead
        }
    }
    // step 5 answer return
    return cloneHead;
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
