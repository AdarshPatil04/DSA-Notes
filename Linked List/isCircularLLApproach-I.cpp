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
    Node* prev;

    Node(int value):data(value),next(nullptr),prev(nullptr){}
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

// Function to print a singly linked list
void print(Node* head){
    // If the singly linked list is empty, then return
    if(head==nullptr){
        return;
    }
    // Otherwise, traverse the singly linked list and print the data of each node
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

// Function to insert a node at the end of a singly linked list
Node* insertAtEnd(Node* head,int value){
    // Create a new node
    Node* newNode = new Node(value);
    // If the singly linked list is empty, then make the new node as head
    if(head==nullptr){
        return newNode;
    }
    // Otherwise, traverse the singly linked list to go to the last node
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }
    // Change the next of the last node
    temp->next=newNode;
    // Return the head pointer of the singly linked list
    return head;
}

int main(){
    // Create a singly linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = nullptr;
    head = insertAtEnd(head,1);
    head = insertAtEnd(head,2);
    head = insertAtEnd(head,3);
    head = insertAtEnd(head,4);
    head = insertAtEnd(head,5);

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
