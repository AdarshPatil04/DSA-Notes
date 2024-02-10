/**
 * This code finds all the bridges in an undirected graph using Depth-First Search (DFS) algorithm.
 * A bridge is an edge in the graph whose removal increases the number of connected components in the graph.
 * The code takes an input of the number of vertices (v), number of edges (e), and a list of edges.
 * It returns a vector of vectors, where each inner vector represents a bridge in the graph.
 * The time complexity of the code is O(V+E), where V is the number of vertices and E is the number of edges in the graph.
 * The space complexity is also O(V+E) due to the usage of adjacency list and other auxiliary data structures.
 */
// https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026

#include <bits/stdc++.h>
using namespace std;

// Function to perform Depth-First Search (DFS) and find bridges in the graph
void dfs(int node, int parent, int &timer, vector<int> &low,
         vector<int> &disc, unordered_map<int, bool> &vis,
         unordered_map<int, list<int>> &adj, vector<vector<int>> &result)
{
    // Mark the node as visited
    vis[node] = true;
    // Initialize discovery time and low value
    disc[node] = low[node] = timer++;

    // Go through all vertices adjacent to this
    for (auto neighbour : adj[node])
    {
        // Ignore the vertex if it is the parent of the current vertex
        if (neighbour == parent)
        {
            continue;
        }
        // If the vertex is not visited, then recurse on it
        else if (!vis[neighbour])
        {
            dfs(neighbour, node, timer, low, disc, vis, adj, result);
            // Check if the subtree rooted with neighbour has a connection to one of the ancestors of node
            low[node] = min(low[node], low[neighbour]);

            // If the lowest vertex reachable from subtree under neighbour is below node in DFS tree, then node-neighbour is a bridge
            if (low[neighbour] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }
        // else if the vertex is already visited
        else
        {
            // Update low value of the node for parent function calls
            low[node] = min(low[node], disc[neighbour]);
        }
    }
}

// Function to find bridges in an undirected graph
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Prepare adjacency list representation
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Initialize disc and low, and visited arrays
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    unordered_map<int, bool> visited;

    int parent = -1;
    int timer = 0;

    vector<vector<int>> result;

    // Call the recursive helper function to find Bridges in DFS tree rooted with vertex 'i'
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, timer, low, disc, visited, adj, result);
        }
    }

    return result;
}

int main()
{
    int v = 5, e = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 2}};
    vector<vector<int>> result = findBridges(edges, v, e);
    for (auto i : result)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}
