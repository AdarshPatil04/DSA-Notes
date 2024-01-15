/**
 * @brief This code checks whether a singly linked list is circular or not.
 * 
 * It uses a map to store the nodes and their frequency while traversing the linked list.
 * If a node is already present in the map, it means the linked list is circular.
 * Otherwise, the linked list is not circular.
 */
#include <bits/stdc++.h>
using namespace std;

// Class for a node
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int value):data(value),next(nullptr),prev(nullptr){}
};

// Function to check if a singly linked list is circular or not
bool isCircular(Node* head) {
    // Map to store the nodes and their frequency
    map<Node*, int> nodeMap;
    // Temp pointer to traverse the singly linked list
    Node* temp = head;
    // Traverse the singly linked list until the temp pointer reaches the end of the singly linked list
    while (temp != NULL) {
        // If the node is already present in the map, then the singly linked list is circular
        if (nodeMap.count(temp)) {
            return true;
        }
        // Increment the frequency of the node in the map
        nodeMap[temp]++;
        // Move the temp pointer to the next node
        temp = temp->next;
    }
    // Otherwise, the singly linked list is not circular
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = head;  
    if (isCircular(head)) {
        cout << "The linked list is circular.\n";
    } else {
        cout << "The linked list is not circular.\n";
    }
    return 0;
}
