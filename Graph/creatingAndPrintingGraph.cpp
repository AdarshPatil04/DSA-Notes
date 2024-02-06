/**
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 * This code demonstrates the creation of an adjacency list representation of a graph
 * and printing the adjacency list.
 *
 * The function `printAdjacency` takes the number of nodes, number of edges, and a vector
 * of edges as input. It creates an empty adjacency list and adds edges to it. Then, it
 * creates the final adjacency list by adding the node number and all the adjacent nodes
 * to each node's list. The function returns the adjacency list.
 *
 * In the `main` function, the number of nodes, number of edges, and edges of the graph
 * are defined. The `printAdjacency` function is called to create the adjacency list.
 * Finally, the adjacency list is printed.
 */
// https://www.codingninjas.com/codestudio/problems/create-a-graph-and-print-it_1214551

#include <bits/stdc++.h>
using namespace std;

// Function to create the adjacency list representation of a graph
vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // Create an empty adjacency list
    vector<int> ans[n];

    // Add edges to the adjacency list
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        // Add edge from u to v
        ans[u].push_back(v);
        // Add edge from v to u
        ans[v].push_back(u);
    }

    // Create the final adjacency list
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        // Add the node number to the adjacency list
        adj[i].push_back(i);

        // Add all the nodes that are adjacent to the current node
        for (int j = 0; j < ans[i].size(); j++)
        {
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}

int main()
{
    // Number of nodes
    int n = 4;
    // Number of edges
    int m = 3;
    // Edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}};

    // Create the adjacency list representation of the graph
    vector<vector<int>> adj = printAdjacency(n, m, edges);

    // Print the adjacency list
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
