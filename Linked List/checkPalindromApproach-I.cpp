/**
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 * @brief This code checks whether a given linked list is a palindrome or not.
 * 
 * It defines a Node class for a singly linked list and provides functions to check if an array is a palindrome and if a linked list is a palindrome.
 * The main function creates a linked list and calls the isPalindrome function to check if the linked list is a palindrome.
 * The code uses an array to store the data of the linked list and then checks if the array is a palindrome.
 * If the array is a palindrome, the isPalindrome function returns true; otherwise, it returns false.
 */
#include<bits/stdc++.h>
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

// Function to check if array is palindrome
bool checkPalindrome(vector<int> arr){
    int n = arr.size();
    int s= 0;
    int e = n-1;
    // Loop till start is less than end
    while(s<=e){
        // If start and end elements are not equal
        if(arr[s] != arr[e])
            return false; // Return false
        s++;
        e--;
    }
    // Return true if all elements are equal
    return true;
}

// Function to check if linked list is palindrome
bool isPalindrome(Node* head){
    vector<int> arr;
    Node* temp = head;
    // Store the data of linked list in array
    while(temp != NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }
    return checkPalindrome(arr); // Check if array is palindrome
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    cout<<isPalindrome(head); // '1' if true, '0' otherwise
    return 0;
}