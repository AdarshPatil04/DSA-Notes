/**
 * @brief This code finds the starting petrol pump from where a truck can complete a full circle.
 * 
 * The code uses a greedy approach to find the starting petrol pump. It iterates through each petrol pump,
 * keeping track of the balance petrol and deficit petrol. If the balance becomes negative, it moves the
 * starting point to the next petrol pump and updates the deficit and balance accordingly. Finally, it checks
 * if the total petrol is greater than or equal to 0, and returns the starting point if true. Otherwise, it
 * returns -1 indicating that it is not possible to complete the circle.
 */
#include <bits/stdc++.h>
using namespace std;

// Define a struct to represent a petrol pump
struct petrolPump
{
    int petrol;   // Amount of petrol
    int distance; // Distance to next petrol pump
    petrolPump(int p, int d) : petrol(p), distance(d){};
};

class Solution
{
public:
    // Function to find the starting petrol pump from where the truck can complete a full circle
    int tour(petrolPump p[], int n)
    {
        int deficit = 0; // Keep track of deficit petrol
        int balance = 0; // Keep track of balance petrol
        int start = 0;   // Starting petrol pump

        // Traverse through each petrol pump
        for (int i = 0; i < n; i++)
        {
            // Update balance petrol
            balance += p[i].petrol - p[i].distance;
            // If balance is negative, move the starting point to the next petrol pump
            if (balance < 0)
            {
                start = i + 1;
                deficit += balance;
                balance = 0;
            }
        }
        // If total petrol is greater than or equal to 0, return the starting point
        if (balance + deficit >= 0)
            return start;
        return -1; // If not possible to complete the circle, return -1
    }
};

int main()
{
    int n = 6;
    petrolPump p[] = {{6, 5}, {7, 6}, {4, 7}, {10, 8}, {6, 6}, {5, 4}};
    Solution obj;
    cout << obj.tour(p, n) << endl;
    return 0;
}
