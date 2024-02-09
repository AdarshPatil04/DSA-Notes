/**
 * This code demonstrates how to find the shortest path in a directed graph using a topological sort and dynamic programming.
 * The time and space complexity of this algorithm is linear, O(N+E), where N is the number of vertices and E is the number of edges in the graph.
 *
 * The Graph class represents a directed graph using an adjacency list representation.
 * It provides methods to add edges, print the adjacency list, perform a depth-first search (DFS) to fill the stack for topological sort,
 * and find the shortest path from a source vertex using dynamic programming.
 *
 * The main function creates a graph, adds edges to it, performs topological sort, and finds the shortest path from a specified source vertex.
 * The shortest path distances are printed to the console.
 */

#include <bits/stdc++.h>
using namespace std;

// Graph class represents a directed graph using adjacency list representation
class Graph
{
public:
    // Adjacency list
    unordered_map<int, list<pair<int, int>>> adj;

    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight)
    {
        pair<int, int> p = make_pair(v, weight);
        adj[u].push_back(p); // Add v to u's list
    }

    // Function to print the adjacency list
    void printAdj()
    {
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "(" << j.first << "," << j.second << "), ";
            }
            cout << endl;
        }
        cout << endl;
    }

    // Function to perform DFS and fill the stack
    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topo)
    {
        visited[node] = 1; // Mark the current node as visited
        for (auto neighbour : adj[node])
        {
            if (!visited[neighbour.first])
            {
                dfs(neighbour.first, visited, topo); // Recur for all the vertices adjacent to this vertex
            }
        }
        topo.push(node); // Push current vertex to stack which stores result
    }

    // Function to find the shortest path from the source vertex
    void getShortestPath(int src, vector<int> &dist, stack<int> &topo)
    {
        dist[src] = 0; // Distance of source vertex from itself is always 0

        // Process vertices in topological order
        while (!topo.empty())
        {
            int top = topo.top();
            topo.pop();

            // Update dist[] of all adjacent vertices
            if (dist[top] != INT_MAX)
            {
                for (auto neigh : adj[top])
                {
                    if (dist[top] + neigh.second < dist[neigh.first])
                    {
                        dist[neigh.first] = dist[top] + neigh.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    // Add edges to the graph
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    // Print the adjacency list
    g.printAdj();

    int n = 6; // Number of vertices

    // Perform topological sort
    unordered_map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s); // Call the recursive helper function to store Topological Sort
        }
    }

    int src = 1;                  // Source vertex
    vector<int> dist(n, INT_MAX); // Initialize distances to all vertices as infinite and distance to source as 0

    // Find shortest paths from source to all vertices
    g.getShortestPath(src, dist, s);
    cout << "Shortest Path will be => ";
    for (int i = 0; i < dist.size(); i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;

    cout << endl;
    return 0;
}
