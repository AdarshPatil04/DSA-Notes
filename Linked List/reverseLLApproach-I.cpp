/**
 * Approach-I: Iterative
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * @brief This code demonstrates the reversal of a linked list.
 * 
 * The code defines a Node class with data and next pointer attributes.
 * It also defines a function to reverse the linked list by modifying the next pointers of each node.
 * The main function creates a linked list, prints it, reverses it, and prints the reversed list.
 */

#include <bits/stdc++.h>
using namespace std;

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

// Reverse the linked list
Node *reverseLinkedList(Node *head)
{
    // If the linked list is empty or has only one node
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // If the linked list has more than one node
    // We will use three pointers to reverse the linked list - prev, curr and forward
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;
    // Traversing the linked list and reversing the links
    while (curr != NULL)
    {
        // Making the forward pointer point to the next node
        forward = curr->next;
        // Making the next pointer of the current node point to the previous node
        curr->next = prev;
        // Making the previous pointer point to the current node
        prev = curr;
        // Making the current pointer point to the next node
        curr = forward;
    }
    // Returning the linked list after reversing it which is prev 
    return prev;
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
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    cout<<"Before reversing the linked list: ";
    print(head);
    cout<<"After reversing the linked list: ";
    head = reverseLinkedList(head);
    print(head);
    return 0;
}