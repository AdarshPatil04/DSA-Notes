/**
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * @brief This code sorts a linked list containing 0s, 1s, and 2s in ascending order.
 *
 * The code counts the number of 0s, 1s, and 2s in the linked list, and then modifies the data of each node
 * to sort the linked list in ascending order. The algorithm uses two passes through the linked list.
 * In the first pass, it counts the occurrences of each element, and in the second pass, it modifies the data
 * of each node based on the counts. The time complexity of this algorithm is O(n), where n is the number of nodes
 * in the linked list.
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
    // Count the number of 0s, 1s and 2s in the linked list
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;
    Node *temp = head; // Pointer to traverse the linked list
    // Traverse the linked list
    while (temp != NULL)
    {
        // If the data of the current node is 0, then increment the zeroCount
        if (temp->data == 0)
        {
            zeroCount++;
        }
        // If the data of the current node is 1, then increment the oneCount
        else if (temp->data == 1)
        {
            oneCount++;
        }
        // If the data of the current node is 2, then increment the twoCount
        else
        {
            twoCount++;
        }
        temp = temp->next; // Move the temp pointer to the next node
    }

    temp = head; // Reset the temp pointer to the head of the linked list
    // Traverse the linked list
    while (temp != NULL)
    {
        // If the zeroCount is not 0, then make the data of the current node 0 and decrement the zeroCount
        if (zeroCount != 0)
        {
            temp->data = 0;
            zeroCount--;
        }
        // If the zeroCount is 0 and the oneCount is not 0, then make the data of the current node 1 and decrement the oneCount
        else if (oneCount != 0)
        {
            temp->data = 1;
            oneCount--;
        }
        // If the zeroCount and the oneCount are 0, then make the data of the current node 2 and decrement the twoCount
        else
        {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next; // Move the temp pointer to the next node
    }
    return head; // Return the head of the sorted linked list
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
