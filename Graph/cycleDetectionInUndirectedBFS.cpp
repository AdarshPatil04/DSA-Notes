/**
 * Time Complexity : O(N+E)
 * Space Complexity : O(N+E)
 * This code implements cycle detection in an undirected graph using BFS traversal.
 * It takes a set of edges as input and constructs an adjacency list representation of the graph.
 * Then, it traverses each component of the graph and checks if a cycle exists starting from each node.
 * If a cycle is found in any component, it returns "Yes", otherwise it returns "No".
 */
// https://www.codingninjas.com/codestudio/problems/cycle-detection-in-undirected-graph_1062670
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

// Function to detect cycle in a graph using BFS traversal
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    // Create a map to store the parent of each node
    unordered_map<int, int> parent;
    // Create a queue for BFS traversal
    queue<int> q;

    // Mark the source node as visited and add it to the queue
    parent[src] = -1;
    visited[src] = 1;
    q.push(src);

    // Continue until all nodes are visited
    while (!q.empty())
    {
        // Get the next node from the queue
        int frontNode = q.front();
        q.pop();

        // Check all the adjacent nodes of the current node
        for (auto i : adjList[frontNode])
        {
            // If the adjacent node is visited and is not the parent of the current node, then a cycle exists
            if (i != parent[frontNode] && visited[i] == true)
            {
                return true;
            }
            else if (!visited[i])
            {
                // If the adjacent node is not visited, then mark it as visited and add it to the queue
                q.push(i);
                visited[i] = 1;
                parent[i] = frontNode;
            }
        }
    }
    // If no cycle is found, return false
    return false;
}

// Function to detect cycle in a graph
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    // Create an adjacency list and a visited map
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;

    // Prepare the adjacency list
    prepareAdj(edges, m, adjList);

    // Traverse each component of the graph
    for (int i = 0; i < n; i++)
    {
        // If the node is not visited, then check if a cycle exists from that node
        if (!visited[i])
        {
            bool ans = isCyclicBFS(i, visited, adjList);
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
