/**
 * This program finds the shortest path in an unweighted graph using modified Breadth-First Search (BFS).
 * The time complexity is O(N+E) where N is the number of vertices and E is the number of edges.
 * The space complexity is O(N+E) for storing the graph, O(N) for the queue and visited array, and O(N) for the parent map.
 */
// https://www.codingninjas.com/codestudio/problems/shortest-path-in-an-unweighted-graph_981297

#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path in an unweighted graph using BFS
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // Create an adjacency list from the edge list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;  // source vertex
        int v = edges[i].second; // destination vertex

        // Since it's an undirected graph, add each vertex to the other's list
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize visited array and parent map
    vector<bool> visited(n);
    unordered_map<int, int> parent;

    // Create a queue for BFS and add the source vertex
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    parent[s] = -1; // Source vertex has no parent

    // BFS traversal
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // Visit all unvisited neighbors of the current node
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                visited[neighbour] = 1;
                parent[neighbour] = frontNode; // Set the parent of the neighbor as the current node
                q.push(neighbour);             // Add the neighbor to the queue
            }
        }
    }

    // Prepare the shortest path using the parent map
    vector<int> ans;
    int currentNode = t;
    ans.push_back(t);

    // Trace the path from the target to the source using the parent map
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    // Reverse the path to get the path from source to target
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 8, m = 9, s = 1, t = 8;                                                                          // Number of vertices, edges, source vertex, and target vertex
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {5, 8}, {3, 8}, {4, 6}, {6, 7}, {7, 8}}; // Edge list

    // Find the shortest path from source to target
    vector<int> ans = shortestPath(edges, n, m, s, t);

    // Print the shortest path
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
