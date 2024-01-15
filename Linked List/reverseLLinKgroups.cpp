/**
 * TIme Complexity : O(n)
 * Space Complexity : O(n) because of the recursive stack
 * This code demonstrates the reversal of a doubly linked list in groups of size k.
 * The reverseK function takes the head of the linked list and the group size as input,
 * and returns the head of the reversed linked list.
 * The insertAtEnd function is used to insert a node at the end of the doubly linked list.
 * The print function is used to print the elements of the doubly linked list.
 * The main function creates a doubly linked list, prints it, reverses it in groups of size 3,
 * and then prints the reversed linked list.
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

Node* reverseK(Node* head,int k){
    // Base case
    if(head==nullptr){
        return head;
    }
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;
    int count=0;
    // Step 1: Reverse first k nodes of the doubly linked list
    // Loop till the current node is not null and count is less than k
    while(current!=nullptr && count<k){
        // Store the next node of the current node
        next = current->next;
        // Change the next of the current node to point to the previous node
        current->next = prev;
        // Change the previous of the current node to point to the next node
        prev = current;
        // Move the current node to the next node
        current = next;
        // Increment the count
        count++;
    }
    // Step 2: Recursion call to reverse the next k nodes of the doubly linked list
    if(next!=nullptr){
        // Call the function recursively to reverse the next k nodes of the doubly linked list
        head->next = reverseK(next,k);
    }

    // Step 3: Return the pointer to the head of the reversed doubly linked list
    return prev;
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
    Node* newHead = reverseK(head,3);
    print(newHead);
    return 0;
}