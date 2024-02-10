/**
 * The time complexity of this algorithm is O(N*M), where N is the number of nodes and M is the number of edges.
 * The space complexity is linear, O(N).
 * @brief This code implements the Bellman Ford algorithm to find the shortest distance between a source and destination vertex in a weighted directed graph.
 *
 * @param n The number of vertices in the graph.
 * @param m The number of edges in the graph.
 * @param src The source vertex.
 * @param dest The destination vertex.
 * @param edges The list of edges, where each edge is represented as a vector of three elements: starting vertex, ending vertex, and weight of the edge.
 * @return The shortest distance from the source vertex to the destination vertex. If there is a negative weight cycle, it returns -1.
 */
// https://www.codingninjas.com/codestudio/problems/bellmon-ford_2041977

#include <bits/stdc++.h>
using namespace std;

// Function to implement Bellman Ford Algorithm
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // Initialize the distance from the source to all vertices as infinite (1e9)
    vector<int> dist(n + 1, 1e9);
    // Distance from source to itself is always 0
    dist[src] = 0;

    // Relax all edges 'n' times which is actually n-1 times
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];  // Starting vertex of the edge
            int v = edges[j][1];  // Ending vertex of the edge
            int wt = edges[j][2]; // Weight of the edge

            // If the starting vertex is reachable and the new distance is shorter
            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                // Update the distance to the ending vertex
                dist[v] = dist[u] + wt;
            }
        }
    }

    // Check for negative weight cycle / Actually checking for nth time
    bool flag = 0;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        // If we can still relax the edge, then we have a negative weight cycle
        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
        {
            flag = 1;
            break;
        }
    }

    // If no negative weight cycle, return shortest distance, else return -1
    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}

int main()
{
    // Number of vertices and edges
    int n = 5, m = 8;
    // Edge list where each edge is a vector of three elements: starting vertex, ending vertex, and weight of the edge
    vector<vector<int>> edges = {{1, 2, 3}, {1, 3, 8}, {1, 4, -4}, {2, 4, 7}, {2, 5, 1}, {3, 2, 4}, {4, 3, 2}, {4, 5, 5}};
    // Source and destination vertices
    int src = 1, dest = 5;
    // Print the shortest distance from source to destination
    cout << bellmonFord(n, m, src, dest, edges);
    return 0;
}
