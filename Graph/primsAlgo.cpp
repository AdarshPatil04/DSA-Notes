/**
 * This code implements Prim's algorithm for finding the Minimum Spanning Tree (MST) of a graph.
 * The algorithm starts from a given source node and repeatedly adds the shortest edge that connects a node in the MST to a node outside the MST.
 * The time complexity of the algorithm is O(MlogN), where M is the number of edges and N is the number of vertices in the graph.
 * The space complexity is linear, O(M+N).
 */
//https://www.codingninjas.com/codestudio/problems/prim-s-mst_1095633

#include <bits/stdc++.h>
using namespace std;

// Function to implement Prim's algorithm for Minimum Spanning Tree (MST)
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Create an adjacency list from the edge list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;  // Start node of edge
        int v = g[i].first.second; // End node of edge
        int w = g[i].second;       // Weight of edge

        // Add edge to adjacency list
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Initialize the arrays for storing the MST, the shortest edge, and the parent nodes
    vector<int> dist(n + 1, INT_MAX); // Shortest edge to each node
    vector<bool> mst(n + 1, 0);       // Whether each node is included in the MST
    vector<int> parent(n + 1, -1);    // Parent node of each node in the MST

    // Start from node 1
    int src = 1;
    dist[src] = 0;
    parent[src] = -1;

    // Create a priority queue to store the nodes, sorted by their shortest edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});

    // Process each node
    while (!pq.empty())
    {
        // Get the node with the shortest edge
        int topNode = pq.top().second;
        pq.pop();

        // Include this node in the MST
        mst[topNode] = true;

        // Update the shortest edges of its neighbors
        for (auto i : adj[topNode])
        {
            int v = i.first;  // Neighbor node
            int w = i.second; // Edge weight

            // If the neighbor is not in the MST and the edge is shorter
            if (mst[v] == false && w < dist[v])
            {
                // Update the parent and the shortest edge
                parent[v] = topNode;
                dist[v] = w;

                // Add the neighbor to the priority queue
                pq.push({w, v});
            }
        }
    }

    // Create the MST as a list of edges
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, dist[i]});
    }

    // Return the MST
    return result;
}

int main()
{
    // Number of nodes and edges
    int n = 4, m = 5;

    // Edge list: each edge is a pair of nodes and a weight
    vector<pair<pair<int, int>, int>> g = {{{1, 2}, 1}, {{1, 3}, 2}, {{1, 4}, 3}, {{2, 3}, 4}, {{3, 4}, 5}};

    // Calculate the MST
    vector<pair<pair<int, int>, int>> result = calculatePrimsMST(n, m, g);

    // Print the MST
    for (auto i : result)
    {
        cout << i.first.first << " " << i.first.second << " " << i.second << endl;
    }

    return 0;
}
