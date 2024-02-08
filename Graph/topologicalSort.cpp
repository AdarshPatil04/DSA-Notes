/**
 * Time Complexity: O(N+V)
 * Space Complexity: O(N)
 * This code implements the topological sort algorithm using Depth-First Search (DFS) on a directed graph.
 * Topological sort is a linear ordering of the vertices of a directed graph such that for every directed edge (u, v),
 * vertex u comes before vertex v in the ordering. This algorithm finds a valid topological ordering of the given graph,
 * if it exists.
 *
 * Time Complexity: O(N+V), where N is the number of vertices and V is the number of edges in the graph.
 * Space Complexity: O(N), where N is the number of vertices in the graph.
 *
 * The code first constructs the adjacency list representation of the graph using the given edges.
 * Then, it performs topological sort by calling the topoSort function for each unvisited node.
 * The topoSort function uses DFS to visit all the neighbours of a node and pushes the node into a stack after visiting all its neighbours.
 * Finally, the code retrieves the topological ordering by popping elements from the stack and returns it as the result.
 */
// https://www.codingninjas.com/codestudio/problems/topological-sort_982938
// Time and Space complexity both will be linear such that O(N+V) and O(N) respectively

#include <bits/stdc++.h>
using namespace std;

// Function to perform topological sort using Depth-First Search (DFS)
void topoSort(int node, vector<bool> &visited, unordered_map<int, list<int>> &adj, stack<int> &s)
{
    // Mark the node as visited
    visited[node] = 1;

    // Visit all the neighbours of the node
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, adj, s);
        }
    }

    // Push the node into the stack after visiting all its neighbours
    s.push(node);
}

// Function to perform topological sort on the graph
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // Prepare the adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Initialize the visited array and the stack
    vector<bool> visited(v);
    stack<int> s;

    // Call the topoSort function for each unvisited node
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, adj, s);
        }
    }

    // Prepare the answer by popping elements from the stack
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

// Function to print the adjacency list
void printAdjList(unordered_map<int, list<int>> &adj, int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << i << " -> ";
        for (auto j : adj[i])
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

    // Prepare the adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    // Print the adjacency list
    cout << "Adjacency List: " << endl;
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
