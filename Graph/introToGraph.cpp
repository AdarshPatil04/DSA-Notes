/**
 * @brief This code demonstrates the implementation of a graph using an adjacency list.
 *        A graph is a data structure that consists of nodes and edges.
 *        The direction of edges determines whether the graph is directed or undirected.
 *        This code allows the user to input the number of nodes and edges, and then add edges to the graph.
 *        Finally, it prints the adjacency list representation of the graph.
 *
 *        The graph is implemented using a template class 'graph' with an unordered map to store the adjacency list.
 *        The 'addEdges' function is used to add edges to the graph, considering whether the graph is directed or undirected.
 *        The 'printAdjList' function is used to print the adjacency list.
 * Inputs:
 * Enter the number of nodes => 10
 * Enter the number of edges => 9
 * Enter nodes and their respective connected edges (space separated)
 * 1 2
 * 2 3
 * 3 4
 * 4 5
 * 5 6
 * 6 7
 * 7 8
 * 8 9
 * 9 10 
 * Outputs:
 *  Printing Nodes and their respective Edges
 * 1 -> 2
 * 2 -> 1 3
 * 3 -> 2 4
 * 4 -> 3 5
 * 5 -> 4 6
 * 6 -> 5 7
 * 7 -> 6 8
 * 8 -> 7 9
 * 9 -> 8 10
 * 10 -> 9
 * 
 */
// Graph is a DS which is a combination of nodes and edges
// Edges direction determines the DIRECTED or UNDIRECTED graph

// NODE ->  Entity to store data
// EDGE -> Conecting nodes
// Degree -> No. of edges (directed or undirected) determines the Degree of that respective node
//-> Indegree
//-> Outdegree

// Weighted Graph
// Path
// Cyclic Graph
// Acyclic Graph

// Graph implementation can be done by
// 1. Adjacency Matrix
// 2. Adjacency List

// Implementing graph by using 2.Adjacency List
#include <bits/stdc++.h>
using namespace std;

// Template class for a graph
template <typename T>
class graph
{
public:
    // Adjacency list to store the graph
    unordered_map<T, list<T>> adj;

    // Function to add an edge to the graph
    void addEdges(T u, T v, bool direction)
    {
        // If direction is 0, the graph is undirected
        // If direction is 1, the graph is directed

        // Create an edge from u to v
        adj[u].push_back(v);
        if (direction == 0)
        {
            // If the graph is undirected, create an edge from v to u
            adj[v].push_back(u);
        }
    }

    // Function to print the adjacency list
    void printAdjList()
    {
        cout << "\nPrinting Nodes and their respective Edges " << endl;
        for (auto i : adj)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout << "\nEnter the number of nodes => ";
    cin >> n;

    int m;
    cout << "\nEnter the number of edges => ";
    cin >> m;

    // Create a graph object
    graph<int> g;

    cout << "\nEnter nodes and their respective connected edges (space separated)" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Add edges to the graph to create an undirected graph
        g.addEdges(u, v, 0);
    }
    // Print the graph
    g.printAdjList();

    cout << endl;
    return 0;
}