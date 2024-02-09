/**
 * The time complexity of this algorithm is O(ElogV), where E is the number of edges and V is the number of vertices.
 * The space complexity is O(N+E), where N is the number of vertices and E is the number of edges.
 * @brief This code implements Dijkstra's algorithm to find the shortest path from a source node to all other nodes in a weighted graph.
 *
 * @param vec The adjacency matrix representation of the graph.
 * @param vertices The number of vertices in the graph.
 * @param edges The number of edges in the graph.
 * @param source The source node from which the shortest paths are calculated.
 * @return A vector containing the shortest distances from the source node to all other nodes.
 *
 */
// https://www.codingninjas.com/codestudio/problems/dijkstra-s-shortest-path_920469

#include <bits/stdc++.h>
using namespace std;

// Function to implement Dijkstra's algorithm
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    // Create an adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0]; // Start node of edge
        int v = vec[i][1]; // End node of edge
        int w = vec[i][2]; // Weight of edge

        // Add edge to adjacency list
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    // Create a distance array and initialize all distances to infinity
    vector<int> dist(vertices, INT_MAX);

    // Create a set to store nodes along with their current shortest distance
    set<pair<int, int>> st;

    // Initialize distance of source node to 0 and add it to the set
    dist[source] = 0;
    st.insert(make_pair(0, source));

    // Loop until all nodes are processed
    while (!st.empty())
    {
        // Get the node with the smallest distance
        auto top = *(st.begin());
        int nodeDistance = top.first;
        int topNode = top.second;

        // Remove this node from the set
        st.erase(st.begin());

        // Update distances of its neighboring nodes
        for (auto neighbour : adj[topNode])
        {
            // If the new distance is smaller, update the distance
            if (nodeDistance + neighbour.second < dist[neighbour.first])
            {
                // If the node is in the set, remove it
                auto record = st.find(make_pair(dist[neighbour.first], neighbour.first));
                if (record != st.end())
                {
                    st.erase(record);
                }

                // Update the distance
                dist[neighbour.first] = nodeDistance + neighbour.second;

                // Insert the updated distance into the set
                st.insert(make_pair(dist[neighbour.first], neighbour.first));
            }
        }
    }
    // Return the shortest distances from the source node
    return dist;
}

int main()
{
    int vertices = 9, edges = 14;
    vector<vector<int>> vec = {{0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11}, {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9}, {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1}, {6, 8, 6}, {7, 8, 7}};

    vector<int> ans = dijkstra(vec, vertices, edges, 0);
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " " << ans[i] << endl;
    }
    return 0;
}
