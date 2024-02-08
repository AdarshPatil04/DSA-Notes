/**
// The time complexity is O(N+E) where N is the number of vertices and E is the number of edges.
// The space complexity is O(N+E) for storing the graph and O(N) for the queue and indegree array.
 * This code detects whether a directed graph contains a cycle or not.
 * It uses the Breadth-First Search (BFS) algorithm to detect the cycle.
 * The code creates an adjacency list from the given edge list and calculates the indegree of each vertex.
 * It then adds all vertices with indegree 0 to a queue and processes the vertices in the queue.
 * If a cycle is detected, it returns true; otherwise, it returns false.
 */
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_1062626
// Time & Space Complexity will be O(N+E) where N = no. of vertices and E = no. of edges

#include <bits/stdc++.h>
using namespace std;

// Function to detect a cycle in a directed graph
bool detectCycleInDirectedGraph(int n, int e, vector<pair<int, int>> &edges)
{
    // Create an adjacency list from the edge list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i].first;  // source vertex
        int v = edges[i].second; // destination vertex
        adj[u].push_back(v);     // Add v to u's list
    }

    // Calculate the indegree of each vertex
    // Indegree of a vertex is the number of incoming edges to the vertex
    vector<int> indegree(n + 1, 0);
    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++; // Increment the indegree of vertex j
        }
    }

    // Add all vertices with indegree 0 to the queue
    // Vertices with indegree 0 have no incoming edges
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Process vertices in the queue
    int cnt = 0;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        cnt++;
        for (auto nbr : adj[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
                q.push(nbr);
        }
    }

    // If cnt is not equal to n, there is a cycle
    // cnt is the number of vertices processed
    // If a cycle exists, one or more vertices will not be processed
    return (cnt != n);
}

int main()
{
    int v = 4, e = 4;                                                // Number of vertices and edges
    vector<pair<int, int>> edges = {{1, 2}, {2, 3}, {3, 4}, {4, 2}}; // Edge list
    // If a cycle is detected, print "Cycle detected", else print "No cycle detected"
    cout << (detectCycleInDirectedGraph(v, e, edges) ? "Cycle detected" : "No cycle detected");
    return 0;
}
