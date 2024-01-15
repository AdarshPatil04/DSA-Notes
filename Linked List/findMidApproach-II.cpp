/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * This code demonstrates how to find the middle node of a singly linked list.
 * It defines a Node class with data, next, and prev pointers.
 * The getMid function finds the middle node of the linked list using two pointers - slow and fast.
 * The findMid function is a wrapper function that calls getMid to find the middle node.
 * The insertAtTail function inserts a new node at the end of the linked list.
 * The insertAtPosition function inserts a new node at a specific position in the linked list.
 * The print function prints the data of all nodes in the linked list.
 * The main function creates a linked list, inserts nodes, prints the list, and finds the middle node.
 */
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to find the middle node of a singly linked list
Node *getMid(Node *head)
{
    // If the singly linked list is empty or has only one node, then return the head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // If the singly linked list has only two nodes, then return the second node
    if (head->next->next == NULL)
    {
        return head->next;
    }
    // Otherwise, initialize two pointers slow and fast to the head and head->next respectively
    Node *slow = head;
    Node *fast = head->next;
    // Traverse the singly linked list until the fast pointer reaches the end of the singly linked list
    while (fast != NULL)
    {
        // Move the fast pointer two nodes ahead of the slow pointer
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    // Return the middle node of the singly linked list
    return slow;
}

// Recursive function to find the middle node of a singly linked list
Node *findMid(Node *head)
{
    // Return the middle node of the singly linked list
    return getMid(head);
}

// Insert at tail
void insertAtTail(Node *&tail, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = new Node(data);

    // Making the next pointer of the tail point to the new Node
    tail->next = temp;

    // Making the tail point to the new Node
    tail = tail->next;
}

void insertAtPosition(Node *&head, int position, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;
    int count = 1;

    // Traversing the linked list before the position-1 because position-1 is the temp Node
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // If the position is greater than the length of the linked list then insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(temp, data);
        return;
    }

    // Creating a new Node to insert at the given position
    Node *nodeToInsert = new Node(data);

    // Making the next pointer of the new Node point to the next Node of the temp Node
    nodeToInsert->next = temp->next;

    // Making the next pointer of the temp Node point to the new Node
    temp->next = nodeToInsert;
}

// Print the linked list
void print(Node *head)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;

    // Traversing the linked list and printing the data until temp->next is NULL
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *tail = head;
    insertAtPosition(head, 2, 2);
    insertAtPosition(head, 3, 3);
    insertAtPosition(head, 4, 4);
    insertAtPosition(head, 5, 5);
    insertAtPosition(head, 6, 6);
    insertAtPosition(head, 7, 7);
    insertAtPosition(head, 8, 8);
    insertAtPosition(head, 9, 9);
    insertAtPosition(head, 10, 10);
    print(head);
    Node *mid = findMid(head);
    cout << mid->data << endl;
    return 0;
}
