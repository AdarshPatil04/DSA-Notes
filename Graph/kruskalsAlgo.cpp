/**
 * This code implements Kruskal's algorithm to find the minimum spanning tree (MST) of a graph.
 * The time complexity of this algorithm is O(MlogN), where M is the number of edges and N is the number of vertices.
 * The space complexity is O(N), where N is the number of vertices.
 *
 * The algorithm works by sorting the edges of the graph in ascending order of their weights.
 * It then iterates through the sorted edges and adds them to the MST if they do not create a cycle.
 * The algorithm uses disjoint sets to keep track of the connected components of the graph.
 *
 * The main function in this code initializes the graph, calculates the MST using Kruskal's algorithm,
 * and prints the weight of the MST.
 */

#include <bits/stdc++.h>
using namespace std;

// Comparator function for sorting edges by weight
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}

// Function to initialize disjoint sets
void makeSet(vector<int> &parent, vector<int> &rank, int n)
{
    for (int i = 0; i < n; i++)
    {
        parent[i] = i; // Each node is its own parent initially
        rank[i] = 0;   // Rank of each node is 0 initially
    }
}

// Function to find the representative of a set
int findParent(vector<int> &parent, int node)
{
    // If the node is its own parent, return it
    if (parent[node] == node)
    {
        return node;
    }

    // Otherwise, find the parent of the parent (path compression)
    return parent[node] = findParent(parent, parent[node]);
}

// Function to merge two sets
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);

    // Merge smaller rank tree into larger rank tree
    if (rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if (rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}

// Function to calculate the weight of the minimum spanning tree
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n + 1); // Parent of each node
    vector<int> rank(n + 1);   // Rank of each node
    makeSet(parent, rank, n + 1);

    // Sort edges by weight
    sort(edges.begin(), edges.end(), cmp);

    int wtCount = 0; // Total weight of MST

    for (int i = 0; i < edges.size(); i++)
    {
        int edgeWt = edges[i][2]; // Weight of edge

        int u = findParent(parent, edges[i][0]); // Parent of start node
        int v = findParent(parent, edges[i][1]); // Parent of end node

        // If start and end nodes are not in the same set, merge them and add the weight to the total
        if (u != v)
        {
            wtCount += edgeWt;
            unionSet(u, v, parent, rank);
        }
    }
    return wtCount; // Return total weight of MST
}

int main()
{
    // Number of nodes and edges
    int n = 4, m = 5;

    // Edge list: each edge is a pair of nodes and a weight
    vector<vector<int>> g = {{1, 2, 1}, {1, 3, 2}, {1, 4, 3}, {2, 3, 4}, {3, 4, 5}};

    // Calculate the MST
    int result = minimumSpanningTree(g, n);

    // Print the MST
    cout << "The weight of the minimum spanning tree is: " << result << endl;

    return 0;
}
