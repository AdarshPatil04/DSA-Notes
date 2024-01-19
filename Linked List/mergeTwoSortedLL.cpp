/**
 * @brief This code demonstrates the merging of two sorted linked lists.
 *        It takes two sorted linked lists as input and merges them into a single sorted linked list.
 *        The code uses the Node class to represent each node in the linked list.
 *        The solve() function is used to merge the two lists by rearranging the pointers.
 *        The sortTwoLists() function is used to determine which list is smaller and calls the solve() function accordingly.
 *        The main() function creates two sorted linked lists, prints them, merges them using the sortTwoLists() function,
 *        and then prints the merged linked list.
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

// Function to merge two sorted linked list
Node *solve(Node *first, Node *second)
{
    // If first linked list is empty
    if (first->next == NULL)
    {
        first->next = second; // Link first list with second list
        return first; // Return the head of new sorted list
    }
    // Initialize current and next pointers of both lists
    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;
    // Loop till there are nodes in second list
    while (next1 != NULL && curr2 != NULL)
    {
        // If curr2 lies in between curr1 and next1
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next = curr2; // Make curr2 as next of curr1
            next2 = curr2->next; // Make next2 as next of curr2
            curr2->next = next1; // Make next of curr2 as next1
            curr1 = curr2; // Make curr2 as next of curr1
            curr2 = next2; // Make curr2 as next of curr1
        }
        // If curr2 doesn't lie in between curr1 and next1
        else
        {
            curr1 = next1; // Make curr1 as next of curr1
            next1 = next1->next; // Make next1 as next of curr1
            // If next1 is NULL then link curr2 with it
            if (next1 != NULL)
            {
                curr1->next = curr2; // Make curr2 as next of curr1
                return first; // Return the head of new sorted list
            }
        }
    }
    return first; // Return the head of new sorted list
}

// Function to merge two sorted linked list
Node *sortTwoLists(Node *first, Node *second)
{
    // If first linked list is empty
    if (first == NULL)
        return second;
    // If second linked list is empty
    if (second == NULL)
        return first;
    // If first linked list is smaller
    if (first->data <= second->data)
    {
        return solve(first, second);
    }
    // If second linked list is smaller
    else
    {
        return solve(second, first);
    }
}

int main()
{
    Node *head1 = new Node(1);
    head1->next = new Node(3);
    head1->next->next = new Node(5);
    head1->next->next->next = new Node(7);
    head1->next->next->next->next = new Node(9);
    Node* temp1 = head1; // Temporary pointer to head of first list
    // Print the first linked list
    while (temp1 != NULL)
    {
        cout << temp1->data << " ";
        temp1 = temp1->next;
    }
    cout << endl;
    Node *head2 = new Node(2);
    head2->next = new Node(4);
    head2->next->next = new Node(6);
    head2->next->next->next = new Node(8);
    head2->next->next->next->next = new Node(10);
    Node* temp2 = head2; // Temporary pointer to head of second list
    // Print the second linked list
    while (temp2 != NULL)
    {
        cout << temp2->data << " ";
        temp2 = temp2->next;
    }
    cout << endl;
    Node *head = sortTwoLists(head1, head2); // Merge two sorted linked list
    // Print the merged linked list
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}