/**
 * Time Complexity : O(n)
 * Space Complexity : O(1) since after reversing the linked list, again reversing it will give the original linked list. So, no extra space is required.
 * This code checks if a given linked list is a palindrome or not.
 * It uses the approach of reversing the second half of the linked list and comparing it with the first half.
 * If the data of all corresponding nodes in the first and second halves are equal, the linked list is a palindrome.
 * The code defines a Node class for a singly linked list and provides functions to reverse the linked list,
 * get the middle node, and check if the linked list is a palindrome.
 * The main function creates a linked list and calls the isPalindrome function to check if it is a palindrome.
 * It prints '1' if the linked list is a palindrome, and '0' otherwise.
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
Node *getMid(Node *head)
{
    // Make two pointers slow and fast and initialize them with head
    Node *slow = head;
    Node *fast = head;
    // Loop till fast is not NULL
    while (fast != NULL)
    {
        fast = fast->next; // Move fast by one
        // If fast is not NULL
        if (fast != NULL)
        {
            fast = fast->next; // Move fast by two
            slow = slow->next; // Move slow by one
        }
    }
    return slow; // Return the mid node
}

// Function to check if linked list is palindrome
bool isPalindrome(Node *head)
{
    // Return true if head is NULL or head is the only node
    if (head == NULL || head->next == NULL)
        return true;              //
    Node *middle = getMid(head);  // Get the mid node
    Node *temp = middle->next;    // Make temp as next of mid node
    middle->next = reverse(temp); // Reverse the next of mid node
    Node *head1 = head;           // Make head1 as head of first half
    Node *head2 = middle->next;   // Make head2 as head of second half
    // Loop till head2 is not NULL
    while (head2 != NULL)
    {
        // If the data of both nodes is not equal
        if (head1->data != head2->data)
            return false;    // Return false
        head1 = head1->next; // Move head1 one step ahead
        head2 = head2->next; // Move head2 one step ahead
    }
    temp = reverse(middle->next); // Reverse the next of mid node
    return true;                  // Return true
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    cout << isPalindrome(head); // '1' if true, '0' otherwise
    return 0;
}