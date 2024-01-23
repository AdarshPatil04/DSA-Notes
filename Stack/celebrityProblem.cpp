/**
 * @brief This code implements the "celebrity" problem using a stack.
 * Time Complexity: O(n)
 * The "celebrity" problem is to find a person in a party who is known by everyone but doesn't know anyone.
 * The code uses a stack to keep track of potential celebrities. It starts by pushing all the people into the stack.
 * Then, it repeatedly pops two people from the stack and checks if one knows the other.
 * If the first person knows the second, the first person cannot be a celebrity and the second person is pushed back into the stack.
 * If the second person knows the first, the second person cannot be a celebrity and the first person is pushed back into the stack.
 * This process continues until only one person remains in the stack, which is the potential celebrity.
 * Finally, the code checks if the potential celebrity is known by everyone and doesn't know anyone to confirm if they are the celebrity.
 * @param M A 2D vector representing the matrix of relationships between people.
 * @param n The number of people in the party.
 * @return The index of the celebrity if found, otherwise -1.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Function to find the next smaller element
    bool knows(vector<vector<int>> &M, int a, int b, int n)
    {
        // if a knows b then a cannot be a celeb
        if (M[a][b] == 1)
        {
            return true; // return true
        }
        // if a does not know b then b cannot be a celeb
        else
        {
            return false; // return false
        }
    }

public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        stack<int> s; // stack to store the elements
        // step1: push all elements in stack
        for (int i = 0; i < n; i++)
        {
            s.push(i); // push i into the stack
        }
        // step2: pop two elements from stack and check if a knows b
        while (s.size() > 1)
        {
            int a = s.top(); // store the top of stack in a
            s.pop();         // pop the top of stack
            int b = s.top(); // store the top of stack in b
            s.pop();         // pop the top of stack
            // if a knows b then a cannot be a celeb
            if (knows(M, a, b, n))
            {
                s.push(b); // push b into the stack
            }
            // if b know a then b cannot be a celeb
            else
            {
                s.push(a); // push a into the stack
            }
        }
        int ans = s.top(); // store the top of stack in ans
        int zeroCount = 0; // count of zeroes in ans row
        // row check
        for (int i = 0; i < n; i++)
        {
            // if ans knows i then ans cannot be a celeb
            if (M[ans][i] == 0)
            {
                zeroCount++; // increment zeroCount
            }
        }
        // if zeroCount is not equal to n then ans cannot be a celeb
        if (zeroCount != n)
        {
            return -1; // return -1
        }
        int oneCount = 0; // count of ones in ans column
        // column check
        for (int i = 0; i < n; i++)
        {
            // if i knows ans then ans cannot be a celeb
            if (M[i][ans] == 1)
            {
                oneCount++; // increment oneCount
            }
        }
        // if oneCount is not equal to n-1 then ans cannot be a celeb
        if (oneCount != n - 1)
        {
            return -1; // return -1
        }
        return ans; // return ans
    }
};

int main()
{
    int n = 3;
    vector<vector<int>> M(n, vector<int>(n));
    M = {{0, 1, 0}, {0, 0, 0}, {0, 1, 0}};
    Solution obj;
    cout << obj.celebrity(M, n);
    return 0;
}
