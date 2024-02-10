/**
 * The code has a time complexity of O(N+E), where N is the number of vertices and E is the number of edges.
 * The code has a space complexity of O(N+E), where N is the number of vertices and E is the number of edges.
 * This code finds the articulation points in a graph using Depth-First Search (DFS) algorithm.
 * An articulation point is a vertex in a graph that, if removed along with its incident edges,
 * would increase the number of connected components in the graph.
 * It uses an adjacency list representation of the graph and performs DFS to find the articulation points.
 * The articulation points are then printed as output.
 */

#include <bits/stdc++.h>
using namespace std;

// Function to perform Depth-First Search (DFS) and find articulation points in the graph
void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, vector<int> &ap, unordered_map<int, list<int>> &adj)
{
    // Mark the node as visited
    vis[node] = true;
    // Initialize discovery time and low value
    disc[node] = low[node] = timer++;
    // Initialize child count
    int child = 0;

    // Go through all vertices adjacent to this
    for (auto nbr : adj[node])
    {
        // Ignore the vertex if it is the parent of the current vertex
        if (nbr == parent)
            continue;

        // If the vertex is not visited, then recurse on it
        if (!vis[nbr])
        {
            dfs(nbr, node, timer, disc, low, vis, ap, adj);
            // Check if the subtree rooted with nbr has a connection to one of the ancestors of node
            low[node] = min(low[node], low[nbr]);

            // If the lowest vertex reachable from subtree under nbr is above node in DFS tree, then node is an articulation point
            if (low[nbr] >= disc[node] && parent != -1)
            {
                ap[node] = 1;
            }
            child++;
        }
        else
        {
            // Update low value of the node for parent function calls
            low[node] = min(low[node], disc[nbr]);
        }
    }

    // If node is root of DFS tree and has two or more children, then it is an articulation point
    if (parent == -1 && child > 1)
    {
        ap[node] = 1;
    }
}

int main()
{
    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // Prepare adjacency list representation
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;

    // Initialize disc and low, and visited arrays
    vector<int> disc(n, -1);
    vector<int> low(n, -1);
    unordered_map<int, bool> vis;
    vector<int> ap(n, 0);

    // Call the recursive helper function to find Articulation Points in DFS tree rooted with vertex 'i'
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, -1, timer, disc, low, vis, ap, adj);
        }
    }

    // Print Articulation Points
    cout << "Articulation points are as follows " << endl;
    for (int i = 0; i < n; i++)
    {
        if (ap[i] != 0)
        {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}
