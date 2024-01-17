/**
 * Time Complexity: O(n)
 * Space Complexity: O(n) since we are using a map
 * @brief This code removes duplicates from an unsorted linked list using a map.
 *
 * The code defines a Node class for a singly linked list and implements a function
 * to remove duplicates from the linked list. It uses a map to store the nodes of
 * the linked list and traverses the list to check if a node is already present in
 * the map. If a node is found to be a duplicate, it is deleted from the list. The
 * function modifies the list in-place and does not change the head pointer.
 *
 * The main function creates a sample linked list, calls the uniqueUnsortedList
 * function to remove duplicates, and prints the modified linked list.
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
void uniqueUnsortedList(Node *head)
{                            // Since only Nodes are getting changed and not the head pointer, we can pass the head pointer by value
    map<int, bool> node_map; // Map to store the nodes of the linked list
    Node *current = head;    // Pointer to traverse the linked list
    Node *prev = NULL;       // Pointer to store the previous node
    // Traverse the linked list
    while (current != NULL)
    {
        // If the current node is already present in the map, then delete the current node
        if (node_map[current->data])
        {
            prev->next = current->next; // Make the next pointer of the previous node point to the next node of the current node
            delete (current);           // Delete the current node
        }
        // If the current node is not present in the map, then insert the current node in the map and move the previous pointer to the current node
        else
        {
            node_map[current->data] = true; // Insert the current node in the map
            prev = current;                 // Move the previous pointer to the current node
        }
        current = prev->next; // Move current to the next node
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
