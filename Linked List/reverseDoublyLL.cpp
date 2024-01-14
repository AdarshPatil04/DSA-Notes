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
    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

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
