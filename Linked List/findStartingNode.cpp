/**
 * This code demonstrates how to detect and find the starting node of a cycle in a singly linked list.
 * It uses Floyd's Tortoise and Hare algorithm to detect the cycle and then finds the starting node of the cycle.
 * The code creates a linked list with a cycle and finds the starting node of the cycle, if present.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

// Function to detect a loop  in a singly linked list
Node *floydDetectLoop(Node *head)
{
    // If the head is null, then return null
    if (head == nullptr)
    {
        return nullptr;
    }
    // Initialize two pointers slow and fast to the head
    Node *slow = head;
    Node *fast = head;
    // Traverse the doubly linked list until the fast pointer reaches the end of the doubly linked list
    while (slow != nullptr && fast != nullptr)
    {
        // Move the fast pointer two nodes ahead of the slow pointer
        fast = fast->next;
        if (fast != nullptr)
        {
            fast = fast->next;
        }
        // Move the slow pointer one node ahead
        slow = slow->next;
        // If the slow pointer and the fast pointer meet, then return the slow pointer
        if (slow == fast)
        {
            cout << "Present at " << slow->data << endl;
            return slow;
        }
    }
    // Return null if the loop is not found
    return NULL;
}

// Function to find the node where the cycle starts
Node *findStartingNode(Node *head)
{
    // If the head is null, then return null
    if (head == nullptr)
    {
        return nullptr;
    }
    // Find the node where the cycle starts
    // intersection is the node where the slow pointer and the fast pointer meet
    Node *intersection = floydDetectLoop(head);
    // Move the slow pointer to the head
    Node *slow = head;
    // Traverse the linked list until the slow pointer and the intersection meet
    while (slow != intersection)
    {
        // Move the slow pointer one node ahead
        slow = slow->next;
        // Move the intersection pointer one node ahead
        intersection = intersection->next;
    }
    // Return the slow pointer when slow and intersection meet again after floydDetectLoop
    return slow;
}

int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node *tail = head->next->next;
    // Making tail point to next of head that is 2 so the linked list is 1 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 ...
    tail->next = head->next;
    // Find the node where the cycle starts
    Node *startingNode = findStartingNode(head);
    // If the starting node is not null, then print the starting node
    if (startingNode != NULL)
    {
        cout << "Cycle is present.\n";
        cout << "Starting node is " << startingNode->data << endl;
    }
    else
    {
        cout << "No Cycle is present.\n";
    }
}