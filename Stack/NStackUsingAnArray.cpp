/**
 * Time Complexity: O(1)
 * Space Complexity: O(s+n)
 * @brief This code implements the NStack class, which allows the creation of multiple stacks using a single array.
 *        It provides methods to push elements into a specific stack and pop elements from a specific stack.
 *        The implementation uses three arrays: arr to store the elements, top to store the top of each stack,
 *        and next to store the next index of each element. The code also includes a main function to demonstrate
 *        the usage of the NStack class.
 */
#include <bits/stdc++.h>
using namespace std;

class NStack
{
    int *arr; // array to store the elements
    int *top; // array to store the top of each stack
    int *next; // array to store the next index of each element
    int n, s; // n = number of stacks, s = size of array
    int freespot; // variable to store the index of the free spot

public:
    // Constructor to initialise the variables
    NStack(int N, int S)
    {
        n = N; // initialise n to N (number of stacks)
        s = S; // initialise s to S (size of array)
        arr = new int[s]; // dynamically allocate memory to arr
        top = new int[n]; // dynamically allocate memory to top
        next = new int[s]; // dynamically allocate memory to next
        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1; // initialise top[i] to -1
        }
        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1; // initialise next[i] to i + 1
        }
        next[s - 1] = -1; // update last index value to -1
        freespot = 0; // initialise freespot to 0
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next;
        next[index] = top[m - 1];

        // update top
        top[m - 1] = index;

        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        // Do the reverse of push
        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    int n = 3, s = 10;
    NStack ns(n, s);
    ns.push(11, 1);
    ns.push(9, 2);
    ns.push(7, 3);
    ns.push(15, 2);
    ns.push(20, 1);
    ns.push(40, 2);
    ns.push(50, 3);
    cout << "Popped element from stack 2 is " << ns.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ns.pop(1) << endl;
    cout << "Popped element from stack 3 is " << ns.pop(3) << endl;
    return 0;
}