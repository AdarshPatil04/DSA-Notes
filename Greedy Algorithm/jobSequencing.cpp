/**
 * Time Complexity: O(n*k)
 * Space Complexity: O(n)
 * @brief This code implements the Job Scheduling problem using a Greedy algorithm.
 *
 * The Job Scheduling problem involves finding the maximum profit and the number of jobs done,
 * given a set of jobs with their respective deadlines and profits. The goal is to schedule the jobs
 * in such a way that the maximum profit is achieved while meeting the deadlines.
 *
 * The code sorts the jobs in descending order of profit and then iterates over the jobs, assigning
 * each job to the latest possible deadline slot. If a slot is already occupied, the code moves to
 * the previous deadline slot until an empty slot is found. The count of jobs done and the maximum
 * profit are returned as the result.
 */
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
    // Comparator function to sort jobs in descending order of profit
    static bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        // Sort the jobs in descending order of profit
        sort(arr, arr + n, cmp);

        // Find the maximum deadline among all jobs
        int maxiDeadline = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }

        // Create a schedule vector to store the job id at each deadline
        vector<int> schedule(maxiDeadline + 1, -1);

        // Initialize count of jobs done and maximum profit
        int cnt = 0;
        int maxProfit = 0;

        // Iterate over all jobs
        for (int i = 0; i < n; i++)
        {
            // For each job, iterate from its deadline to 1
            for (int k = arr[i].dead; k > 0; k--)
            {
                // If the slot is empty, schedule the job and update count and profit
                if (schedule[k] == -1)
                {
                    cnt++;
                    maxProfit += arr[i].profit;
                    schedule[k] = arr[i].id;
                    break;
                }
            }
        }
        // Return the count of jobs done and maximum profit
        vector<int> ans;
        ans.push_back(cnt);
        ans.push_back(maxProfit);

        return ans;
    }
};

int main()
{
    // Number of jobs
    int n = 4;
    // Array of jobs
    Job arr[n];
    arr[0].id = 1;
    arr[0].dead = 4;
    arr[0].profit = 20;
    arr[1].id = 2;
    arr[1].dead = 1;
    arr[1].profit = 10;
    arr[2].id = 3;
    arr[2].dead = 1;
    arr[2].profit = 40;
    arr[3].id = 4;
    arr[3].dead = 1;
    arr[3].profit = 30;
    // Create a Solution object
    Solution ob;
    // Find the maximum profit and the number of jobs done
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << "The number of jobs done: " << ans[0] << endl;
    cout << "The maximum profit: " << ans[1] << endl;
    return 0;
}