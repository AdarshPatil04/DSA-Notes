#include <bits/stdc++.h>
using namespace std;

// Creating a class Node
class Node
{
public:
    // Data
    int data;

    // (Pointer to the next Node) / (Address of the next Node)
    Node *next;

    // Constructor to create a new Node
    Node(int data)
    {

        // data is the data given by the user
        this->data = data;

        // Initially the next pointer is NULL
        next = NULL;
    }
};

// Recursive function to reverse the linked list
void reverse(Node *&head,  Node *curr, Node *prev)
{
    // Base case
    // When the current pointer reaches the end of the linked list
    if (curr == NULL)
    {
        // Making the head point to the last node of the linked list
        head = prev;
        return;
    }
    // Recursive case
    // Making the forward pointer point to the next node
    Node *forward = curr->next;
    // Calling the recursive function
    reverse(head, forward, curr);
    // Making the next pointer of the current node point to the previous node
    curr->next = prev;
}

// Reverse the linked list
Node *reverseLinkedList(Node *&head)
{
    // Making the previous pointer point to NULL
    Node *prev = NULL;
    // Making the current pointer point to the head of the linked list
    Node *curr = head;
    // Calling the recursive function
    reverse(head, curr, prev);
    // Returning the linked list after reversing it
    return head;
}

// Print the linked list
void print(Node *&head)
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
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout << "Before reversing the linked list: ";
    print(head);
    cout << "After reversing the linked list: ";
    head = reverseLinkedList(head);
    print(head);
    return 0;
}