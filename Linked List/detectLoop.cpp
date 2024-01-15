/**
 * Time Complexity : O(n)
 * Space Complexity : O(n)
 * @brief This program checks if a singly linked list contains a loop or not.
 * 
 * The program uses a map to store the nodes and their frequency. It traverses the linked list
 * and checks if a node is already present in the map. If it is, then the linked list contains a loop.
 * Otherwise, the linked list does not contain a loop.
 * 
 * @return int Returns 0 to indicate successful execution of the program.
 */
#include <bits/stdc++.h>
using namespace std;

// Class for a node
class Node{
    public:
    int data;
    Node* next;

    Node(int value):data(value),next(nullptr){}
};

// Function to check if a singly linked list is having a loop or not
bool detectLoop(Node* head) {
    // Map to store the nodes and their frequency
    map<Node*, int> visited;
    // Temp pointer to traverse the singly linked list
    Node* temp = head;
    // Traverse the singly linked list until the temp pointer reaches the end of the singly linked list
    while (temp != NULL) {
        // If the node is already present in the map, then the singly linked list is circular
        if (visited[temp] == true) {
            cout<<"Present on element "<<temp->data<<endl;
            return true;
        }
        // Increment the frequency of the node in the map
        visited[temp] = true;
        // Move the temp pointer to the next node
        temp = temp->next;
    }
    // Otherwise, the singly linked list is not having a loop
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    Node* tail = head->next->next;
    // Making tail point to next of head that is 2 so the linked list is 1 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 3 2 ...
    tail->next = head->next;
    if (detectLoop(head)) {
        cout << "Cycle is present.\n";
    } else {
        cout << "No Cycle is present.\n";
    }
    return 0;
}
