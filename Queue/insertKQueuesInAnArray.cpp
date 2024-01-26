/**
 * @brief This code implements the concept of k Queues in a single array.
 *        It provides a class `kQueue` that allows the user to create multiple queues
 *        within a single array and perform enqueue and dequeue operations on them.
 *        The code demonstrates the usage of arrays and linked lists to manage the queues.
 */
#include<iostream>
using namespace std;

// Class to implement k Queues in a single array
class kQueue {

    public:
        int n; // Size of array
        int k; // Number of queues
        int *front; // Array to store front elements of queues
        int *rear; // Array to store rear elements of queues
        int *arr; // Array to store all queue elements
        int freeSpot; // To store the beginning index of free list
        int *next; // To store next of top and next of next available spot

    public:
        // Constructor to create k queues in an array of size n
        kQueue(int n, int k) {
            this -> n = n;
            this -> k = k;
            front = new int[k];
            rear = new int[k];
            for(int i=0; i<k; i++) {
                front[i] = -1;
                rear[i] = -1;
            }

            next = new int[n];
            for(int i=0; i<n; i++) {
                next[i] = i+1;
            }
            next[n-1] = -1;
            arr = new int[n];
            freeSpot = 0;
        }    

        // Function to enqueue an item to queue number 'qn'
        void enqueue(int data, int qn) {

            // If there is no free space, then the queue is full
            if( freeSpot == -1) {
                cout << "No Empty space is present" << endl;
                return;
            }

            // Find first free index
            int index = freeSpot;

            // Update index of free slot to index of next slot in free list
            freeSpot = next[index];

            // If this is the first element added to the queue
            if(front[qn-1] == -1){
                front[qn-1] = index;
            }
            else{
                // Link new element with the previous front
                next[rear[qn-1]] = index;
            }

            // Update next of new element
            next[index] = -1;

            // Update rear
            rear[qn-1] = index;

            // Push element
            arr[index] = data;
        }

        // Function to dequeue an from queue number 'qn'
        int dequeue(int qn) {
            // If front[qn] is empty, then the queue is empty
            if(front[qn-1] == -1)
            {
                cout << "Queue UnderFlow " << endl;
                return -1;
            }

            // Find index of front item in the queue
            int index = front[qn-1];

            // Change top to store next of previous top
            front[qn-1] = next[index];

            // Attach the previous front to the beginning of the free list
            next[index] = freeSpot;
            freeSpot = index;
            return arr[index];
        }

};

int main() {

    // Create 3 queues in an array of size 10
    kQueue q(10, 3);
    q.enqueue(10, 1);
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    // Dequeue elements from the queues
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    return 0;
}
