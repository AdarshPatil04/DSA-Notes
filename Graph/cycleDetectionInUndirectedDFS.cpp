/**
 * Time Complexity : O(N+E)
 * Space Complexity : O(N+E)
 * This code implements cycle detection in an undirected graph using DFS traversal.
 * It takes a set of edges as input and constructs an adjacency list representation of the graph.
 * Then, it traverses each component of the graph and checks if a cycle exists starting from each node.
 * If a cycle is found in any component, it returns "Yes", otherwise it returns "No".
 */

#include <bits/stdc++.h>
using namespace std;

// Function to prepare adjacency list from the given edges
void prepareAdj(vector<vector<int>> &edges, int m, unordered_map<int, list<int>> &adjList)
{
    // Loop through all the edges
    for (int i = 0; i < m; i++)
    {
        // Extract the nodes connected by the edge
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the edge to the adjacency list
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
}

// Function to detect cycle in a graph using DFS traversal
bool isCyclicDFS(int src, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    // Mark the source node as visited
    visited[src] = 1;

    // Recursive call for each adjacent node
    for (auto i : adjList[src])
    {
        if (!visited[i])
        {
            // If the adjacent node is not visited, then check if a cycle exists from that node
            bool cycleDetected = isCyclicDFS(i, src, visited, adjList);
            if (cycleDetected)
                return true;
        }
        // visited[i]
        else if (i != parent)
        {
            // If the adjacent node is visited and is not the parent of the current node, then a cycle exists
            return true;
        }
    }
    // If no cycle is found, return false
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Create an adjacency list and a visited map
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    // Prepare the adjacency list
    prepareAdj(edges, m, adjList);

    // Traverse each component of the graph
    // Checking for all the nodes in the graph in case of disconnected graph
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            // If the node is not visited, then check if a cycle exists from that node
            bool ans = isCyclicDFS(i, -1, visited, adjList);
            if (ans == 1)
            {
                // If a cycle is found, return "Yes"
                return "Yes";
            }
        }
    }
    // If no cycle is found in any component, return "No"
    return "No";
}

int main()
{
    // Number of nodes and edges
    int n = 4, m = 3;
    // Edges of the graph
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {1, 3}};
    // Print the result of cycle detection
    cout << cycleDetection(edges, n, m);
    return 0;
}
