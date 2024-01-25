/**
 * This code implements a solution to find the first non-repeating character in a string for each prefix of the string.
 * It uses a map to store the frequency of each character, a queue to store the characters in the order they appear,
 * and a string to store the answer. The code iterates over each character in the string, pushes it onto the queue,
 * increments its frequency in the map, and checks the frequency of the front character in the queue. If the frequency
 * is more than 1, it means the character is repeating, so it is popped from the queue. If the frequency is 1, it means
 * the character is non-repeating, so it is added to the answer and the loop is broken. If the queue is empty, it means
 * all characters so far are repeating, so a '#' is added to the answer. Finally, the answer is returned.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the first non-repeating character in a string for each prefix of the string
    string FirstNonRepeating(string A)
    {
        // Create a map to store the frequency of each character
        map<char, int> m;
        // Create a string to store the answer
        string ans = "";
        // Create a queue to store the characters in the order they appear
        queue<char> q;

        // Iterate over each character in the string
        for (int i = 0; i < A.length(); i++)
        {
            char ch = A[i];

            // Push the character onto the queue and increment its frequency in the map
            q.push(ch);
            m[ch]++;

            // While the queue is not empty, check the frequency of the front character
            while (!q.empty())
            {
                // If the frequency is more than 1, it means the character is repeating, so pop it from the queue
                if (m[q.front()] > 1)
                {
                    q.pop();
                }
                // If the frequency is 1, it means the character is non-repeating, so add it to the answer and break the loop
                else
                {
                    ans.push_back(q.front());
                    break;
                }
            }
            // If the queue is empty, it means all characters so far are repeating, so add a '#' to the answer
            if (q.empty())
            {
                ans.push_back('#');
            }
        }
        // Return the answer
        return ans;
    }
};

int main()
{
    // Create an object of the Solution class
    Solution sol;
    cout<<sol.FirstNonRepeating("aabc");
    return 0;
}