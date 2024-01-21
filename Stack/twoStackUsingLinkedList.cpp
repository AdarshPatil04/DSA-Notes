/**
 * @brief This code implements a class called TwoStack that represents two stacks using a single array.
 *        The class provides methods to push elements into each stack, pop elements from each stack,
 *        and initialize the size of the stacks.
 *        The implementation uses the concept of two pointers, top1 and top2, to keep track of the topmost
 *        elements of each stack in the array.
 *        The push1() method pushes an element into stack 1, the push2() method pushes an element into stack 2,
 *        the pop1() method pops an element from stack 1, and the pop2() method pops an element from stack 2.
 *        The code also includes a main function that demonstrates the usage of the TwoStack class.
 */
#include <bits/stdc++.h>
using namespace std;

class TwoStack
{
    int *arr; // Array to store elements
    int top1; // Index of topmost element of stack 1
    int top2; // Index of topmost element of stack 2
    int size; // Size of stack

public:
    // Initialize TwoStack.
    TwoStack(int s)
    {
        this->size = s;   // Initialize size
        top1 = -1;        // Initialize top1
        top2 = s;         // Initialize top2
        arr = new int[s]; // Create an array of size 'size'
    }

    // Push in stack 1.
    void push1(int num)
    {
        // atleast a empty space present
        if (top2 - top1 > 1)
        {
            top1++;          // Increment top1
            arr[top1] = num; // Insert num at top1
        }
    }

    // Push in stack 2.
    void push2(int num)
    {
        // atleast a empty space present
        if (top2 - top1 > 1)
        {
            top2--;          // Decrement top2
            arr[top2] = num; // Insert num at top2
        }
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // atleast a element present
        if (top1 >= 0)
        {
            int ans = arr[top1]; // Store top1 element in ans
            top1--;              // Decrement top1
            return ans;          // Return ans
        }
        // If top1 is less than 0
        else
        {
            return -1; // Return -1
        }
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // atleast a element present
        if (top2 < size)
        {
            int ans = arr[top2]; // Store top2 element in ans
            top2++;              // Increment top2
            return ans;          // Return ans
        }
        // If top2 is greater than or equal to size
        else
        {
            return -1; // Return -1
        }
    }
};

int main()
{
    TwoStack s(5);
    s.push1(1);
    s.push1(2);
    s.push1(3);
    s.push2(4);
    s.push2(5);
    // 1 2 3 | 4 5
    cout << s.pop1() << endl; // pop1
    cout << s.pop2() << endl; // pop2
    cout << s.pop1() << endl;
    cout << s.pop2() << endl;
    cout << s.pop1() << endl;
    cout << s.pop2() << endl;
    return 0;
}