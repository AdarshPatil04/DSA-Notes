#include <bits/stdc++.h>
using namespace std;

// approach 2;
// sc reduced to o(k)
int getKthLargest(vector<int> &arr, int k)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (minHeap.size() < k)
            {
                minHeap.push(sum);
            }
            else
            {
                if (sum > minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(sum);
                }
            }
        }
    }

    return minHeap.top();
}

int main()
{
    vector<int> arr = {10, -10, 20, -40};
    int k = 6;

    cout << getKthLargest(arr, k) << endl;

    return 0;
}