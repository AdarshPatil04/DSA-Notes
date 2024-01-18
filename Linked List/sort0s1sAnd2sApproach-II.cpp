/**
 * @brief This code sorts a linked list containing 0s, 1s, and 2s in non-decreasing order.
 * 
 * The code uses the Dutch National Flag algorithm to sort the linked list by partitioning it into three separate linked lists
 * for 0s, 1s, and 2s. It then connects these linked lists in the desired order to obtain the sorted linked list.
 * 
 * The time complexity of this algorithm is O(n), where n is the number of nodes in the linked list.
 * The space complexity is O(1) as the algorithm only uses a constant amount of extra space.
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

// Function to sort a linked list of 0s, 1s and 2s
Node *sortList(Node *head)
{
    Node *zeroHead = new Node(-1); // Create a dummy node for 0s
    Node *oneHead = new Node(-1);  // Create a dummy node for 1s
    Node *twoHead = new Node(-1);  // Create a dummy node for 2s
    Node *zeroTail = zeroHead;     // Create a pointer to the dummy node for 0s
    Node *oneTail = oneHead;       // Create a pointer to the dummy node for 1s
    Node *twoTail = twoHead;       // Create a pointer to the dummy node for 2s
    Node *temp = head;             // Create a temporary pointer to head
    while (temp != NULL)
    {
        // If the data of the current node is 0, then insert the current node at the end of the linked list of 0s
        if (temp->data == 0)
        {
            zeroTail->next = temp;
            zeroTail = zeroTail->next;
        }
        // If the data of the current node is 1, then insert the current node at the end of the linked list of 1s
        else if (temp->data == 1)
        {
            oneTail->next = temp;
            oneTail = oneTail->next;
        }
        // If the data of the current node is 2, then insert the current node at the end of the linked list of 2s
        else
        {
            twoTail->next = temp;
            twoTail = twoTail->next;
        }
        temp = temp->next; // Move the temp pointer to the next node
    }

    // Connect the sorted linked lists of 0s, 1s, and 2s
    // If the linked list of 0s, 1s, and 2s is not empty
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next; // Connect the linked list of 0s to the linked list of 1s
        oneTail->next = twoHead->next;  // Connect the linked list of 1s to the linked list of 2s
        twoTail->next = NULL;           // Make the next pointer of the last node of the linked list of 2s point to NULL
    }
    // If the linked list of 1s is empty and the linked list of 0s, and 2s is not empty
    else if (twoHead->next != NULL)
    {
        zeroTail->next = twoHead->next; // Connect the linked list of 0s to the linked list of 2s
        twoTail->next = NULL;           // Make the next pointer of the last node of the linked list of 2s point to NULL
    }
    // If the linked list of 0s may or may not be empty and 1s,and 2s is empty
    else
    {
        zeroTail->next = NULL; // Make the next pointer of the last node of the linked list of 0s point to NULL
    }
    head = zeroHead->next; // Make the head of the sorted linked list point to the second node of the linked list of 0s since the first node is a dummy node
    // Delete the dummy nodes
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    // Return the head of the sorted linked list
    return head;
}

// Function to print the linked list
void printList(Node *head)
{
    Node *temp = head; // Create a temporary pointer to head
    while (temp != NULL)
    {
        cout << temp->data << " "; // Print the data of the node
        temp = temp->next;         // Move the temp pointer to the next node
    }
    cout << endl;
}

int main()
{
    // Create a linked list 1->2->0->1->2->1->0->1->2
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next->next = new Node(1);
    head->next->next->next->next->next->next->next->next = new Node(2);
    cout << "The original linked list is: ";
    printList(head);
    head = sortList(head);
    cout << "The sorted linked list is: ";
    printList(head);
    return 0;
}
