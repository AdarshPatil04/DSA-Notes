/**
 * Time Complexity : O(V+E)
 * Space Complexity : O(V+E)
 * This code implements topological sort in a directed graph using BFS traversal.
 * It takes a set of edges as input and constructs an adjacency list representation of the graph.
 * Then, it calculates the indegree of each vertex and pushes the vertices with 0-indegree into a queue.
 * It performs BFS traversal and updates the indegree of each vertex's neighbours.
 * If a neighbour's indegree becomes 0, it is pushed into the queue.
 * The vertices are popped from the queue and added to the result vector.
 */
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938
// Time and space complexity will be linear such as O(N+E) and O(N) respectively.

#include <bits/stdc++.h>
using namespace std;

// Function to prepare adjacency list from the given edges
void prepareAdj(vector<vector<int>> &edges, unordered_map<int, list<int>> &adj)
{
    // Loop through all the edges
    for (int i = 0; i < edges.size(); i++)
    {
        // Extract the nodes connected by the edge
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the edge to the adjacency list
        adj[u].push_back(v);
    }
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Create an adjacency list
    unordered_map<int, list<int>> adj;
    prepareAdj(edges, adj);

    // Calculate the indegree of each vertex
    vector<int> indegree(v, 0);
    for (auto &i : adj)
    {
        for (auto &j : i.second)
        {
            indegree[j]++;
        }
    }

    // Initialize a queue and enqueue all vertices with 0-indegree
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    // Perform BFS traversal
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        // Add the front node to the result vector
        ans.push_back(frontNode);

        // Update the indegree of the front node's neighbours
        for (auto &neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            // If a neighbour's indegree becomes 0, enqueue it
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }

    // Return the result vector
    return ans;
}

// Function to print the adjacency list
void printAdjList(unordered_map<int, list<int>> &adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto &j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    // Define the number of vertices and edges
    int v = 6, e = 6;

    // Define the edges of the graph
    vector<vector<int>> edges = {{5, 2}, {5, 0}, {4, 0}, {4, 1}, {2, 3}, {3, 1}};

    // Print the adjacency list
    cout << "Adjacency List: " << endl;
    unordered_map<int, list<int>> adj;
    prepareAdj(edges, adj);
    printAdjList(adj, v);

    // Perform topological sort and print the result
    vector<int> ans = topologicalSort(edges, v, e);
    cout << "Topological Sort: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
