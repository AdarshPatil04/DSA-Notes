/**
 * Time Complexity : O(m+n)
 * Space Complexity : O(m+n)
 * This code demonstrates the addition of two numbers represented by linked lists.
 * The code defines a Node class for a singly linked list and provides functions to reverse a linked list,
 * insert a node at the tail of a linked list, and add two linked lists.
 * The main function creates two linked lists, adds them together, and prints the result.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to reverse a linked list
Node *reverse(Node *head)
{
    Node *curr = head; // Store the head of linked list
    Node *prev = NULL; // Make prev as NULL
    Node *next = NULL; // Make next as NULL
    // Loop till curr is not NULL
    while (curr != NULL)
    {
        next = curr->next; // Make next of current as next
        curr->next = prev; // Make the next of current as prev
        prev = curr;       // Move prev one step ahead
        curr = next;       // Move curr one step ahead
    }
    return prev; // Return the head of reversed linked list
}

// Function to get the mid node of linked list
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

// Function to add two numbers represented by linked list.
Node *add(Node *first, Node *second)
{
    int carry = 0;        // Initialize carry as 0
    Node *ansHead = NULL; // Initialize ansHead as NULL
    Node *ansTail = NULL; // Initialize ansHead and ansTail as NULL
    // Loop till first is not NULL or second is not NULL or carry is not 0
    while (first != NULL || second != NULL || carry != 0)
    {
        int val1 = 0; // Initialize val1 as 0
        // if first is not NULL
        if (first != NULL)
        {
            val1 = first->data; // Store the data of first in val1
        }
        int val2 = 0; // Initialize val2 as 0
        // if second is not NULL
        if (second != NULL)
        {
            val2 = second->data; // Store the data of second in val2
        }
        int sum = carry + val1 + val2; // Calculate sum of val1, val2 and carry
        int digit = sum % 10;          // Calculate digit
        // create node and add in answer Linked List
        insertAtTail(ansHead, ansTail, digit);
        carry = sum / 10; // Calculate carry
        // Move first and second by one step ahead
        if (first != NULL)
        {
            first = first->next; // Make first as next of first
        }
        // Move second by one step ahead
        if (second != NULL)
        {
            second = second->next; // Make second as next of second
        }
    }
    return ansHead; // Return the head of ans linked list
}

// Function to add two numbers represented by linked list.
Node *addTwoLists(Node *first, Node *second)
{
    // reverse input LL
    first = reverse(first);
    second = reverse(second);
    // Make ans as head of reversed linked list
    Node *ans = add(first, second);
    ans = reverse(ans); // Reverse the ans linked list
    return ans;         // Return the ans linked list
}

int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(5);
    Node *temp1 = head1; // Make temp1 as head of first half
    cout << "  ";        // Just an extra space for better look
    // Loop till temp1 is not NULL
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;
    Node *head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    Node *temp2 = head2; // Make temp2 as head of second half
    // Loop till temp2 is not NULL
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    Node *head3 = addTwoLists(head1, head2); // Add two linked lists
    // Loop till head3 is not NULL
    while (head3 != NULL)
    {
        cout << head3->data << " ";
        head3 = head3->next;
    }
    return 0;
}