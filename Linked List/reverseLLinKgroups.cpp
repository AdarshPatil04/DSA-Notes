/**
 * Time Complexity : O(n)
 * Space Complexity : O(n) because of the stack space used by the recursive calls
 * @brief This program demonstrates the reversal of a singly linked list in groups of size k.
 *        It defines a Node class to represent a node in the linked list and provides functions
 *        to insert nodes at the tail and at a specific position in the linked list. The main
 *        function creates a linked list, inserts nodes at specific positions, prints the original
 *        linked list, reverses the linked list in groups of size k, and prints the reversed linked list.
 * 
 * @return 0 on successful execution
 */
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){}
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
    // Step 1: Reverse first k nodes of the singly linked list
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
    // Step 2: Recursion call to reverse the next k nodes of the singly linked list
    if(next!=nullptr){
        // Call the function recursively to reverse the next k nodes of the singly linked list
        head->next = reverseK(next,k);
    }

    // Step 3: Return the pointer to the head of the reversed singly linked list
    return prev;
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
    insertAtPosition(tail,2,2);
    insertAtPosition(tail,3,3);
    insertAtPosition(tail,4,4);
    insertAtPosition(tail,5,5);
    insertAtPosition(tail,6,6);
    print(head);
    Node* newHead = reverseK(head,3);
    print(newHead);
    return 0;
}