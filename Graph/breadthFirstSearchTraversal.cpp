/**
 * Time Complexity : O(N+E)
 * This code implements the Breadth First Search (BFS) algorithm on a graph starting from vertex 0.
 * It performs BFS traversal on all components of the graph starting from a given node.
 * The code uses an adjacency list to represent the graph and a queue to store the nodes to visit.
 * The BFS algorithm visits all the nodes in the graph in a breadth-first manner, i.e., it visits all the nodes at the same level before moving to the next level.
 * The code returns the order in which the nodes are visited during the BFS traversal.
 * The answer is sorted in ascending order.
 */
// https://www.codingninjas.com/codestudio/problems/bfs-in-graph_973002

#include <bits/stdc++.h>
using namespace std;

// Function to perform BFS on a graph from a given node
void bfs(unordered_map<int, set<int>> &adjList, unordered_map<int, bool> &visited, vector<int> &ans, int node)
{
    queue<int> q;
    q.push(node);      // Push the starting node into the queue
    visited[node] = 1; // Mark the starting node as visited

    while (!q.empty()) // While there are nodes to visit
    {
        int frontNode = q.front(); // Get the next node to visit
        q.pop();

        ans.push_back(frontNode); // Add the visited node to the answer

        // Traverse all the neighbors of frontNode
        for (auto i : adjList[frontNode])
        {
            if (!visited[i]) // If the neighbour has not been visited
            {
                q.push(i);      // Add the neighbour to the queue
                visited[i] = 1; // Mark the neighbour as visited
            }
        }
    }
}

// Function to prepare the adjacency list from the edge list
void prepareAdj(unordered_map<int, set<int>> &adjList, vector<pair<int, int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;  // First vertex of the edge
        int v = edges[i].second; // Second vertex of the edge

        adjList[u].insert(v); // Add v to the adjacency list of u
        adjList[v].insert(u); // Add u to the adjacency list of v
    }
}

// Function to perform BFS on all components of a graph
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int>> adjList; // Adjacency list
    unordered_map<int, bool> visited;     // Visited nodes
    vector<int> ans;                      // Answer

    prepareAdj(adjList, edges); // Prepare the adjacency list

    // Traverse all the components of a graph
    for (int i = 0; i < vertex; i++)
    {
        if (!visited[i]) // If the node has not been visited
        {
            bfs(adjList, visited, ans, i); // Perform BFS from the node
        }
    }
    return ans; // Return the order of visited nodes
}

int main()
{
    int vertex = 6;                                                          // Number of vertices
    vector<pair<int, int>> edges = {{0, 1}, {1, 2}, {1, 3}, {1, 4}, {2, 5}}; // Edges
    vector<int> ans = BFS(vertex, edges);                                    // Perform BFS
    cout << "The order of visited nodes is in sorted order: ";
    for (auto i : ans) // Print the order of visited nodes
    {
        cout << i << " ";
    }
    return 0;
}
