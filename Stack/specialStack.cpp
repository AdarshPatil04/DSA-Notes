/**
 * @brief This code implements a special stack that supports the following operations:
 * - push(x): Inserts an element x to the stack.
 * - pop(): Removes and returns the top element from the stack.
 * - top(): Returns the top element of the stack without removing it.
 * - isEmpty(): Returns true if the stack is empty, else false.
 * - getMin(): Returns the minimum element from the stack in O(1) time and O(1) extra space.
 * 
 * The special feature of this stack is that it supports getMin() operation in constant time
 * and constant extra space. It achieves this by using an auxiliary stack to keep track of the
 * minimum element at any given point. The main stack stores the actual elements, while the
 * auxiliary stack stores the minimum element encountered so far. Whenever a new element is
 * pushed onto the stack, it is compared with the current minimum element and if it is smaller,
 * it is pushed onto the auxiliary stack. When an element is popped from the stack, if it is
 * equal to the current minimum element, the previous minimum element is retrieved from the
 * auxiliary stack. This way, the minimum element is always available in O(1) time and space.
 */
#include <bits/stdc++.h>
using namespace std;

// Design a stack that supports getMin() in O(1) time and O(1) extra space
class SpecialStack
{
    stack<int> s;       // main stack
    int mini = INT_MAX; // to store minimum element
public:
    // push() : Inserts an element x to Special Stack
    void push(int data)
    {
        // if stack is empty, insert data
        if (s.empty())
        {
            s.push(data); // insert data
            mini = data;  // update mini
        }
        // if stack is not empty
        else
        {
            // if data is less than mini
            if (data < mini)
            {
                s.push(2 * data - mini); // insert 2 * data - mini
                mini = data;             // update mini
            }
            // if data is greater than mini
            else
            {
                s.push(data); // insert data
            }
        }
    }

    // pop() : Removes an element from Special Stack
    int pop()
    {
        // if stack is empty, return -1
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top(); // store top element
        s.pop();            // pop top element
        // if top element is less than mini
        if (curr > mini)
        {
            return curr; // return top element
        }
        // if top element is greater than mini
        else
        {
            int prevMin = mini;     // store previous mini
            mini = 2 * mini - curr; // update mini
            return prevMin;         // return previous mini
        }
    }

    // top() : Returns top element of Special Stack
    int top()
    {
        // if stack is empty, return -1
        if (s.empty())
        {
            return -1;
        }
        int curr = s.top(); // store top element
        // if top element is less than mini
        if (curr < mini)
        {
            return mini; // return mini
        }
        // if top element is greater than mini
        else
        {
            return curr; // return top element
        }
    }

    // isEmpty() : Returns true if Special Stack is empty, else false
    bool isEmpty()
    {
        return s.empty();
    }

    // getMin() : Returns minimum element from Special Stack
    int getMin()
    {
        // if stack is empty, return -1
        if (s.empty())
            return -1;
        return mini; // return mini
    }
};

int main()
{
    SpecialStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << endl;
    cout << s.getMin() << endl;
    s.push(5);
    cout << s.top() << endl;
    cout << s.isEmpty() << endl;
    cout << s.getMin() << endl;
    return 0;
}
