/**
 * @brief This code demonstrates the reversal of a singly linked list using a recursive approach.
 *        It defines a Node class with a data member and a pointer to the next Node.
 *        The code includes a recursive function to reverse the linked list and a print function to display the elements.
 *        The main function creates a linked list, prints it, reverses it, and prints the reversed list.
 */

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
Node* reverse1(Node *&head)
{
    // Base case
    // When the current pointer reaches the end of the linked list
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // Recursive case
    // Calling the recursive function
    Node* smallHead = reverse1(head->next);
    // Making the next pointer of the current node point to the previous node
    head->next->next = head;
    // Making the next pointer of the current node point to NULL
    head->next = NULL;
    // Returning the linked list after reversing it
    return smallHead;
}

// Reverse the linked list
Node *reverseLinkedList(Node *&head)
{
    // Calling the recursive function
    return reverse1(head);
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