/**
 * Time Complexity : O(N+E)
 * Space Complexity : O(N+E)
 * This code implements the Depth First Search (DFS) traversal algorithm on a graph.
 * It takes an edge list as input and performs DFS on all components of the graph.
 * The code prepares the adjacency list from the edge list and then performs DFS on each component.
 * The DFS algorithm visits all the nodes in a component and adds them to a vector representing the component.
 * Finally, it returns a vector of vectors, where each inner vector represents a component of the graph.
 */
// https://www.codingninjas.com/codestudio/problems/dfs-traversal_630462

#include <bits/stdc++.h>
using namespace std;

// Function to prepare the adjacency list from the edge list
void prepareAdj(unordered_map<int, list<int>> &adjList, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0]; // First vertex of the edge
        int v = edges[i][1]; // Second vertex of the edge

        adjList[u].push_back(v); // Add v to the adjacency list of u
        adjList[v].push_back(u); // Add u to the adjacency list of v
    }
}

// Function to perform DFS on a graph from a given node
void dfs(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
         vector<int> &component, int node)
{
    component.push_back(node); // Add the node to the current component
    visited[node] = 1;         // Mark the node as visited

    // Visit all the neighbours of the node
    for (auto i : adjList[node])
    {
        if (!visited[i]) // If the neighbour has not been visited
        {
            dfs(adjList, visited, component, i); // Visit the neighbour
        }
    }
}

// Function to perform DFS on all components of a graph
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList; // Adjacency list
    unordered_map<int, bool> visited;      // Visited nodes
    vector<vector<int>> ans;               // Answer

    prepareAdj(adjList, edges); // Prepare the adjacency list

    // Traverse all the components of the graph
    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // If the node has not been visited
        {
            vector<int> component;               // Current component
            dfs(adjList, visited, component, i); // Perform DFS from the node
            ans.push_back(component);            // Add the component to the answer
        }
    }
    return ans; // Return the components
}

int main()
{
    int V = 6, E = 5;                                                     // Number of vertices and edges
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 5}}; // Edges
    vector<vector<int>> ans = depthFirstSearch(V, E, edges);              // Perform DFS

    // Print the components
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
