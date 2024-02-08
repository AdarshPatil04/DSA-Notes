/**
 * Time Complexity : O(V+E)
 * Space Complexity : O(V+E)
 * This code implements cycle detection in a directed graph using DFS traversal.
 * It takes a set of edges as input and constructs an adjacency list representation of the graph.
 * Then, it traverses each component of the graph and checks if a cycle exists starting from each node.
 * If a cycle is found in any component, it returns true, otherwise it returns false.
 */
// https://www.codingninjas.com/codestudio/problems/detect-cycle-in-a-directed-graph_920545

#include <bits/stdc++.h>
using namespace std;

// Function to prepare adjacency list from the given edges
void prepareAdj(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList)
{
    // Loop through all the edges
    for (int i = 0; i < edges.size(); i++)
    {
        // Extract the nodes connected by the edge
        int u = edges[i][0];
        int v = edges[i][1];

        // Add the edge to the adjacency list
        adjList[u].push_back(v);
    }
}

// Function to detect cycle in a graph using DFS traversal
bool isCyclicDetect(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adjList)
{
    // Mark the node as visited and add it to the DFS visited map
    visited[node] = true;
    dfsVisited[node] = true;

    // Check all the adjacent nodes of the current node
    for (auto neighbour : adjList[node])
    {
        // If the adjacent node is not visited, then check if a cycle exists from that node
        if (!visited[neighbour])
        {
            bool detected = isCyclicDetect(neighbour, visited, dfsVisited, adjList);
            if (detected)
                return true;
        }
        // If the adjacent node is visited and is in the DFS visited map, then a cycle exists
        else if (dfsVisited[neighbour])
        {
            return true;
        }
    }

    // After visiting all the adjacent nodes, remove the node from the DFS visited map
    dfsVisited[node] = false;
    return false;
}

// Function to detect cycle in a graph
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    // Create an adjacency list and visited maps
    unordered_map<int, list<int>> adjList;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;

    // Prepare the adjacency list
    prepareAdj(edges, adjList);

    // Traverse each component of the graph
    for (int i = 0; i < v; i++)
    {
        // If the node is not visited, then check if a cycle exists from that node
        if (!visited[i])
        {
            bool ans = isCyclicDetect(i, visited, dfsVisited, adjList);
            if (ans)
                return true;
        }
    }
    // If no cycle is found in any component, return false
    return false;
}

int main()
{
    // Number of nodes and edges
    int v = 4, e = 4;
    // Edges of the graph
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 1}};
    // Print the result of cycle detection
    cout << isCyclic(edges, v, e);
    return 0;
}
