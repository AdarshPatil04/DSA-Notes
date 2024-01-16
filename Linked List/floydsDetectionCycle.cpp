/**
 * Time Complexity : O(n)
 * Space Complexity : O(1)
 * This code demonstrates the Floyd's Cycle Detection algorithm to detect a loop in a singly linked list.
 * It creates a linked list with a cycle and then uses the Floyd's algorithm to detect the cycle.
 * If a cycle is present, it prints "Cycle is present." Otherwise, it prints "No Cycle is present."
 */

#include<bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){}
};

// Function to detect a loop  in a singly linked list
Node* floydDetectLoop(Node* head){
    // If the head is null, then return null
    if(head==nullptr){
        return nullptr;
    }
    // Initialize two pointers slow and fast to the head
    Node* slow = head;
    Node* fast = head;
    // Traverse the doubly linked list until the fast pointer reaches the end of the doubly linked list
    while(slow!=nullptr && fast!=nullptr){
        // Move the fast pointer two nodes ahead of the slow pointer    
        fast=fast->next;
        if(fast!=nullptr){
            fast=fast->next;
        }
        // Move the slow pointer one node ahead
        slow=slow->next;
        // If the slow pointer and the fast pointer meet, then return the slow pointer
        if(slow==fast){
            cout<<"Present at "<<slow->data<<endl;
            return slow;
        }
    }
    // Return null if the loop is not found
    return NULL;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* tail = head->next->next;
    // Making tail point to next of head that is 2 so the linked list is 1 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 ...
    tail->next = head->next;
    if (floydDetectLoop(head) != NULL) {  
        cout << "Cycle is present.\n";
    } else {
        cout << "No Cycle is present.\n";
    }
    return 0;
}