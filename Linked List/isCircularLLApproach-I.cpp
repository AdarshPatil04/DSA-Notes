/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * @brief This code checks whether a singly linked list is circular or not.
 * 
 * The code defines a Node class to represent each node in the linked list.
 * It provides functions to check if the linked list is circular, print the linked list,
 * and insert a node at the end of the linked list.
 * 
 * The main function creates a singly linked list and makes it circular by connecting the last node to the head.
 * It then calls the isCircular function to check if the linked list is circular or not.
 * Finally, it prints the result.
 */

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){}
};

// Function to check if a singly linked list is circular or not
bool isCircular(Node* head){
    // If the head is null, then the singly linked list is circular
    if(head==nullptr){
        return true;
    }
    // Initialize a pointer to the next node of the head
    Node* temp = head->next;
    // Traverse the singly linked list until the temp pointer reaches the head (Non-circular && Circular condition)
    while(temp!=nullptr && temp!=head){
        // Move the temp pointer to the next node
        temp=temp->next;
    }
    // If the temp pointer reaches the head, then the singly linked list is circular
    if(temp==head){
        return true;
    }
    // Otherwise, the singly linked list is not circular
    return false;
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
    // Create a singly linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    insertAtPosition(head,1,1);
    insertAtPosition(head,2,2);
    insertAtPosition(head,3,3);
    insertAtPosition(head,4,4);
    insertAtPosition(head,5,5);

    // Make the singly linked list circular
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    temp->next=head;

    // Check if the singly linked list is circular or not
    if(isCircular(head)){
        cout<<"The singly linked list is circular"<<endl;
    }else{
        cout<<"The singly linked list is not circular"<<endl;
    }
    return 0;
}
