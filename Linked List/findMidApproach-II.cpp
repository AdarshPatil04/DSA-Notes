/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * This code demonstrates how to find the middle node of a doubly linked list.
 * It defines a Node class with data, next, and prev pointers.
 * The getMid function finds the middle node using a slow and fast pointer approach.
 * The findMid function is a wrapper function that calls getMid to find the middle node.
 * The insertAtEnd function inserts a node at the end of the doubly linked list.
 * The print function prints the elements of the doubly linked list.
 * The main function creates a doubly linked list, inserts elements, finds the middle node, and prints it.
 */

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

// Function to find the middle node of a doubly linked list
Node *getMid(Node *head)
{
    // If the doubly linked list is empty or has only one node, then return the head
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // If the doubly linked list has only two nodes, then return the second node
    if (head->next->next == NULL)
    {
        return head->next;
    }
    // Otherwise, initialize two pointers slow and fast to the head and head->next respectively
    Node *slow = head;
    Node *fast = head->next;
    // Traverse the doubly linked list until the fast pointer reaches the end of the doubly linked list
    while (fast != NULL)
    {
        // Move the fast pointer two nodes ahead of the slow pointer
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    // Return the middle node of the doubly linked list
    return slow;
}

// Recursive function to find the middle node of a doubly linked list
Node *findMid(Node *head)
{
    // Return the middle node of the doubly linked list
    return getMid(head);
}

// Function to print a doubly linked list
void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Function to insert a node at the end of a doubly linked list
Node* insertAtEnd(Node* head,int value){
    Node* newNode = new Node(value);
    if(head==nullptr){
        return newNode;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

int main()
{
    Node* head = nullptr;
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);
    head = insertAtEnd(head,6);
    head = insertAtEnd(head,7);
    head = insertAtEnd(head,8);
    head = insertAtEnd(head,9);
    head = insertAtEnd(head,10);
    print(head);
    Node* mid = findMid(head);
    cout<<mid->data<<endl;
    return 0;
}
