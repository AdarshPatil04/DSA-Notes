/**
 * @brief This program demonstrates the reversal of a doubly linked list.
 * 
 * The program defines a Node class for a doubly linked list and provides functions to:
 * - Reverse a doubly linked list
 * - Print a doubly linked list
 * - Insert a node at the end of a doubly linked list
 * 
 * The main function creates a doubly linked list with values 1, 2, 3, 4, 5, and performs the following steps:
 * 1. Prints the original doubly linked list
 * 2. Reverses the doubly linked list
 * 3. Prints the reversed doubly linked list
 * 
 * @return 0 indicating successful execution of the program
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for doubly linked list
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to reverse a doubly linked list
Node* reverseDoublyLinkedList(Node* head) {
    Node* current = head;
    Node* temp = nullptr;

    // Swap next and prev pointers for all nodes of the doubly linked list
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // Move to the next node
        current = current->prev;
    }

    // Update the head pointer to the last node because the temp is at 4 so we need to update the head to 5 which is temp->prev
    if (temp != nullptr) {
        head = temp->prev;
    }
    // Return the head pointer of the reversed doubly linked list
    return head;
}

// Function to print a doubly linked list
void printDoublyLinkedList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Function to insert a node at the end of a doubly linked list
Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node(value);
    // If the doubly linked list is empty, then make the new node as head
    if (head == nullptr) {
        return newNode;
    }
    // Otherwise, traverse the doubly linked list to go to the last node
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    // Change the next of the last node
    temp->next = newNode;
    // Make the last node as the previous of the new node
    newNode->prev = temp;
    // Return the head pointer of the doubly linked list
    return head;
}

int main() {
    // Create a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = nullptr;
    head = insertAtEnd(head, 1);
    head = insertAtEnd(head, 2);
    head = insertAtEnd(head, 3);
    head = insertAtEnd(head, 4);
    head = insertAtEnd(head, 5);

    cout << "Original doubly linked list: ";
    printDoublyLinkedList(head);

    // Reverse the doubly linked list
    head = reverseDoublyLinkedList(head);

    cout << "Reversed doubly linked list: ";
    printDoublyLinkedList(head);

    return 0;
}
