/**
 * Time Complexity : O(nlogn)
 * Space Complexity : O(logn)
 * @brief This program demonstrates the implementation of merge sort algorithm on a singly linked list.
 * 
 * The program defines a Node class for the linked list and provides functions to print the list, get the mid node,
 * merge two sorted linked lists, and perform merge sort on the linked list. The main function creates a linked list,
 * prints the original list, performs merge sort on the list, and prints the sorted list.
 */
#include <bits/stdc++.h>
using namespace std;

// Node class for singly linked list
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Function to print a linked list
void printList(Node *head)
{
    Node *temp = head; // Initialize temp as head
    // Loop till temp is not NULL
    while (temp != NULL)
    {
        cout << temp->data << " "; // Print temp->data
        temp = temp->next;         // Move temp one step ahead
    }
    cout << endl; // Print a new line
}

// Function to get the mid node of linked list
Node *getMid(Node *head)
{
    Node *slow = head; // Initialize slow as head
    Node *fast = head->next; // Initialize fast as next of head to be two step ahead of slow
    // Loop till fast is not NULL
    while (fast != NULL)
    {
        fast = fast->next; // Move fast by one
        // If fast is not NULL
        if (fast != NULL)
        {
            fast = fast->next; // Move fast by two
            slow = slow->next; // Move slow by one
        }
    }
    return slow; // Return the mid node
}

// Function to merge two sorted linked list
Node *merge(Node *left, Node *right)
{
    // If left is NULL
    if (left == NULL)
    {
        return right; // Return right
    }
    // If right is NULL
    if (right == NULL)
    {
        return left; // Return left
    }
    Node *answer = new Node(-1); // Create a dummy node
    Node *temp = answer; // Initialize temp as answer
    // Loop till left and right are not NULL
    while (left != NULL && right != NULL)
    {
        // If data of left is less than data of right
        if (left->data < right->data)
        {
            temp->next = left; // Make next of temp as left
            temp = left; // Move temp one step ahead
            left = left->next; // Move left one step ahead
        }
        // if date of is less than or equal to date of left
        else
        {
            temp->next = right; // Make next of temp as right
            temp = right; // Move temp one step ahead
            right = right->next; // Move right one step ahead
        }
    }
    // Copy the remaining elements of left and right if any
    // If left is not NULL
    while (left != NULL)
    {
        temp->next = left; // Make next of temp as left
        temp = left; // Move temp one step ahead
        left = left->next; // Move left one step ahead
    }
    // If right is not NULL
    while (right != NULL)
    {
        temp->next = right; // Make next of temp as right
        temp = right; // Move temp one step ahead
        right = right->next; // Move right one step ahead
    }
    return answer->next; // Return the next of dummy node
}

Node *mergeSort(Node *head)
{
    // base case
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    // break the list into two halves
    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;
    // sort the two halves
    left = mergeSort(left);
    right = mergeSort(right);
    // merge the two sorted halves
    Node *result = merge(left, right);
    return result;
}

int main()
{
    Node *head1 = new Node(4);
    head1->next = new Node(2);
    head1->next->next = new Node(1);
    head1->next->next->next = new Node(3);
    Node *temp = head1;
    cout << "Original linked List data: " << endl;
    printList(temp);
    Node *head = mergeSort(head1);
    cout << "Sorted linked List data: " << endl;
    printList(head);
    return 0;
}