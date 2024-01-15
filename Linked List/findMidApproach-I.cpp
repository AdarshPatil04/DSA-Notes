/**
 * TIme Complexity : O(n)
 * @brief This code demonstrates finding the middle node of a singly linked list.
 * 
 * The code defines a Node class to represent a node in the linked list. It also includes functions to find the length of the linked list,
 * find the middle node of the linked list, insert a node at the tail of the linked list, insert a node at a specific position in the linked list,
 * and print the linked list.
 * 
 * The main function creates a linked list with nodes containing values from 1 to 10. It then calls the findMid function to find the middle node
 * of the linked list and prints its value.
 */

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){}
};

// Function to find the length of a singly linked list
int getLength(Node* head){
    int len=0;
    // Traverse the singly linked list and increment the length counter for each node
    while(head!=nullptr){
        len++;
        head=head->next;
    }
    // Return the length of the singly linked list
    return len;
}

// Function to find the middle node of a singly linked list
Node* findMid(Node* head){
    // Find the length of the singly linked list
    int len = getLength(head);
    // Find the middle node of the singly linked list by traversing it len/2 + 1 times 
    int mid = (len/2)+1;
    Node* temp = head;
    // Count = 1 so to traverse the singly linked list len/2 + 1 times and head is already counted once
    int count=1;
    // Traverse the singly linked list len/2 + 1 times
    while(count<mid){
        // Move to the next node
        temp=temp->next;
        count++;
    }
    // Return the middle node of the singly linked list
    return temp;
}

// Insert at tail
void insertAtTail(Node *&tail, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = new Node(data);

    // Making the next pointer of the tail point to the new Node
    tail->next = temp;

    // Making the tail point to the new Node
    tail = tail->next;
}

void insertAtPosition(Node *&head, int position, int data)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;
    int count = 1;

    // Traversing the linked list before the position-1 because position-1 is the temp Node
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // If the position is greater than the length of the linked list then insert at tail
    if (temp->next == NULL)
    {
        insertAtTail(temp, data);
        return;
    }

    // Creating a new Node to insert at the given position
    Node *nodeToInsert = new Node(data);

    // Making the next pointer of the new Node point to the next Node of the temp Node
    nodeToInsert->next = temp->next;

    // Making the next pointer of the temp Node point to the new Node
    temp->next = nodeToInsert;
}

// Print the linked list
void print(Node *head)
{
    // Creating a temporary Node to traverse the linked list
    Node *temp = head;

    // Traversing the linked list and printing the data until temp->next is NULL
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    Node* tail = head;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    insertAtTail(tail,6);
    insertAtTail(tail,7);
    insertAtTail(tail,8);
    insertAtTail(tail,9);
    insertAtTail(tail,10);
    Node* mid = findMid(head);
    cout<<"Middle node is "<<mid->data<<endl;

    return 0;
}