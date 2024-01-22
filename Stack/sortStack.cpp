/**
 * Time Complexity: O(n^2)
 * Space Complexity: O(n) because of the recursive call stack
 * @brief This code implements a sorting algorithm for a stack of integers.
 *        The stack is sorted in ascending order using a recursive approach.
 *        The code defines two functions: sortedInsert() and sortStack().
 *        The sortedInsert() function inserts an element into the stack in sorted order.
 *        The sortStack() function recursively sorts the stack using sortedInsert().
 *        The main() function demonstrates the usage of the sorting algorithm.
 */
#include <bits/stdc++.h>
using namespace std;

// Function to insert an element into a stack in sorted order
void sortedInsert(stack<int> &stack, int num)
{
    // base case
    // if stack is empty or top element is greater than num in will be in ascending order else if top element is less than num it will be in descending order
    if (stack.empty() || (!stack.empty() && stack.top() > num))
    {
        stack.push(num); // push num into the stack
        return; // return
    }
    int n = stack.top(); // store the topmost element of the stack in n
    stack.pop(); // pop the topmost element
    // recursive call
    sortedInsert(stack, num);
    stack.push(n); // push n into the stack
}

// Function to sort a stack
void sortStack(stack<int> &stack)
{
    // base case
    // if stack is empty
    if (stack.empty())
    {
        return; // return
    }
    int num = stack.top(); // store the topmost element of the stack in num
    stack.pop(); // pop the topmost element
    // recursive call
    sortStack(stack);
    sortedInsert(stack, num); // insert num into the stack in sorted order
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(1);
    s.push(3);
    s.push(2);
    s.push(4);
    stack<int> temp = s;
    cout<<"Stack elements before sorting: "<<endl;
    while(!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }cout<<endl;
    sortStack(s);
    cout<<"Stack elements after sorting: "<<endl;
    while(!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}