/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @brief This program removes duplicates from an unsorted linked list.
 * 
 * The program defines a Node class for a singly linked list and implements a function
 * to remove duplicates from the linked list. It uses two pointers, ptr1 and ptr2, to
 * traverse the linked list and a third pointer, dup, to store the duplicate node.
 * The program iterates through the linked list and compares the data of each node with
 * the data of the subsequent nodes. If a duplicate is found, the duplicate node is
 * deleted by adjusting the next pointers of the previous and next nodes.
 * 
 * The main function creates a sample linked list, displays it before removing duplicates,
 * calls the uniqueUnsortedList function to remove duplicates, and displays the linked list
 * after removing duplicates.
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

// Function to remove duplicates from an unsorted linked list
void uniqueUnsortedList(Node *&head)
{
    Node *ptr1 = head; // Pointer to traverse the linked list
    Node *ptr2;        // Pointer to traverse the linked list
    Node *dup;         // Pointer to store the duplicate node
    // Traverse the linked list
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1; // Make ptr2 point to the node pointed by ptr1
        // Traverse the linked list starting from the node pointed by ptr2
        while (ptr2->next != NULL)
        {
            // If the data of the node pointed by ptr1 and the next node of the node pointed by ptr2 are equal, then delete the next node of the node pointed by ptr2
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;              // Make dup point to the next node of the node pointed by ptr2
                ptr2->next = ptr2->next->next; // Make the next pointer of the node pointed by ptr2 point to the next node of the node pointed by ptr2
                delete (dup);                  // Delete the duplicate node
            }
            else
            {
                ptr2 = ptr2->next; // Move ptr2 to the next node
            }
        }
        ptr1 = ptr1->next; // Move ptr1 to the next node
    }
}

int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);
    Node *temp = head; // Keep a reference to the head of the list
    cout << "The linked list before removing duplicates is: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    uniqueUnsortedList(head);
    cout << "The linked list after removing duplicates is: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}
