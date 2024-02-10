/**
 * This code implements Kosaraju's algorithm to find the number of strongly connected components in a directed graph.
 * It performs a Depth-First Search (DFS) to find the topological sort of the graph, and then performs DFS on the transpose of the graph using the stack ordering.
 * The number of times the second DFS is called gives the count of strongly connected components in the graph.
 * The time complexity of this algorithm is O(N+E), where N is the number of vertices and E is the number of edges in the graph.
 * The space complexity is O(N+E), where N is the number of vertices and E is the number of edges in the graph.
 */
// https://www.codingninjas.com/codestudio/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151

#include <bits/stdc++.h>
using namespace std;

// Function to perform Depth-First Search (DFS) and find the topological sort of the graph
void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, stack<int> &topo)
{
    // Mark the node as visited
    vis[node] = true;

    // Go through all vertices adjacent to this
    for (int nbr : adj[node])
    {
        if (!vis[nbr])
        {
            dfs(nbr, vis, adj, topo);
        }
    }
    // Push the node to the stack after all of its neighbours are visited
    topo.push(node);
}

// Function to perform DFS for the transpose graph
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    // Mark the node as visited
    vis[node] = true;

    // Go through all vertices adjacent to this
    for (auto nbr : adj[node])
    {
        if (!vis[nbr])
        {
            revDfs(nbr, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // Prepare adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    // Perform topological sort
    stack<int> topo;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, topo);
        }
    }

    // Create transpose of the graph
    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < v; i++)
    {
        vis[i] = false;

        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // Perform DFS call by using stack ordering
    int count = 0;
    while (!topo.empty())
    {
        int top = topo.top();
        topo.pop();

        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}

int main()
{
    int v = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}};
    cout << stronglyConnectedComponents(v, edges);
    return 0;
}
