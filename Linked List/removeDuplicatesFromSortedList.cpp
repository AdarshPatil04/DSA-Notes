/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @brief This program removes duplicates from a sorted linked list.
 *
 * It defines a Node class for a singly linked list and provides a function
 * to remove duplicates from the list. The main function creates a sorted
 * linked list with duplicate elements, calls the function to remove duplicates,
 * and prints the modified list.
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
// Function to remove duplicates from a sorted linked list
Node *uniqueSortedList(Node *&head)
{
    // If the linked list is empty
    if (head == NULL)
    {
        return NULL;
    }
    // Make curr point to the head of the linked list
    Node *curr = head;
    // Traverse the linked list until the curr pointer reaches the last node
    while (curr->next != NULL)
    {
        // If the data of the current node and the next node are equal, then delete the next node
        if (curr->data == curr->next->data)
        {
            //  Make temp point to the next node
            Node *temp = curr->next;
            // Make the next pointer of the current node point to the next node of the next node
            curr->next = curr->next->next;
            // Delete the next node
            delete temp;
        }
        else
        {
            // If the data of the current node and the next node are not equal, then move the curr pointer to the next node
            curr = curr->next;
        }
    }
    // Return the head of the linked list
    return head;
}
// Function to print the linked list
void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(10);
    head->next->next = new Node(20);
    head->next->next->next = new Node(20);
    cout << "Before: ";
    print(head);
    cout << endl;
    cout << "After: ";
    head = uniqueSortedList(head);
    print(head);
    return 0;
}