/**
 * Time Complexity : O(n)
 * This code demonstrates the implementation of a doubly linked list and finding the middle node of the list.
 * It includes functions to find the length of the list, insert a node at the end of the list, and print the list.
 * The main function creates a doubly linked list, inserts nodes, prints the list, and finds the middle node.
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

// Function to find the length of a doubly linked list
int getLength(Node* head){
    int len=0;
    // Traverse the doubly linked list and increment the length counter for each node
    while(head!=nullptr){
        len++;
        head=head->next;
    }
    // Return the length of the doubly linked list
    return len;
}

// Function to find the middle node of a doubly linked list
Node* findMid(Node* head){
    // Find the length of the doubly linked list
    int len = getLength(head);
    // Find the middle node of the doubly linked list by traversing it len/2 + 1 times 
    int mid = (len/2)+1;
    Node* temp = head;
    // Count = 1 so to traverse the doubly linked list len/2 + 1 times and head is already counted once
    int count=1;
    // Traverse the doubly linked list len/2 + 1 times
    while(count<mid){
        // Move to the next node
        temp=temp->next;
        count++;
    }
    // Return the middle node of the doubly linked list
    return temp;
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

int main(){
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