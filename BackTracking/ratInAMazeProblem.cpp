/**
 * This code solves the Rat in a Maze problem using backtracking.
 * Given a maze represented by a 2D grid, the goal is to find all possible paths
 * from the top left cell to the bottom right cell, considering that the rat can only move
 * in four directions: up, down, left, and right. The maze is represented by a grid where
 * 0 represents a blocked cell and 1 represents an open cell. The code uses a recursive
 * backtracking algorithm to explore all possible paths and stores them in a vector.
 * The time complexity of the algorithm is O(4^n*n), where n is the size of the maze,
 * and the space complexity is O(n*m), where n and m are the dimensions of the maze.
 */
// https://www.codingninjas.com/codestudio/problems/rat-in-a-maze_1215030

#include <bits/stdc++.h>
using namespace std;

// Function to check if a cell is safe to move to
bool isSafe(int newX, int newY, vector<vector<bool>> &visited,
            vector<vector<int>> &arr, int n)
{
    // Check if the cell is within the grid, unvisited, and open
    if ((newX >= 0 && newX < n) && (newY >= 0 && newY < n) &&
        (visited[newX][newY] == 0) && (arr[newX][newY] == 1))
    {
        return true;
    }
    else
        return false;
}

// Recursive function to solve the maze
void solve(int x, int y, vector<vector<int>> &arr, int n,
           vector<vector<bool>> &visited, string path, vector<string> &ans)
{
    // Base case: if we've reached the bottom right cell, add the path to the answer
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // Mark the current cell as visited
    visited[x][y] = 1;

    // Try moving in all four directions
    // Down
    if (isSafe(x + 1, y, visited, arr, n))
    {
        // Recursive call
        solve(x + 1, y, arr, n, visited, path + 'D', ans);
    }

    // Left
    if (isSafe(x, y - 1, visited, arr, n))
    {
        solve(x, y - 1, arr, n, visited, path + 'L', ans);
    }

    // Right
    if (isSafe(x, y + 1, visited, arr, n))
    {
        // Recursive call
        solve(x, y + 1, arr, n, visited, path + 'R', ans);
    }

    // Up
    if (isSafe(x - 1, y, visited, arr, n))
    {
        // Recursive call
        solve(x - 1, y, arr, n, visited, path + 'U', ans);
    }

    // Down, Left, Right, Up
    // vector<pair<int,int>> moves{{1,0}, {0,-1}, {0,1}, {-1,0}};
    // for (auto&i : moves) {
    //     int newX = x + i.first;
    //     int newY = y + i.second;

    //     if (isSafe(newX, newY, visited, arr, n)) {
    //         // recursive call
    //         solve(newX, newY, arr, n, visited, path +
    //         (i.first == 1 ? 'D' : i.first == -1 ? 'U' : i.second == -1 ? 'L' : 'R'), ans);
    //     }
    // }

    // Unmark the current cell so it can be used in other paths(backtracking)
    visited[x][y] = 0;
}

// Function to find all paths in the maze
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;                                  // Vector to store all paths
    string path = "";                                    // String to store the current path
    vector<vector<bool>> visited(n, vector<bool>(n, 0)); // Matrix to mark visited cells

    // If the start cell is blocked, return an empty vector
    if (arr[0][0] == 0)
        return ans;

    // Start the recursive function from the top left cell
    solve(0, 0, arr, n, visited, path, ans);
    sort(ans.begin(), ans.end()); // Sort the paths lexicographically (optional)
    return ans; // Return all paths
}

int main()
{
    int n = 4; // Size of the maze
    // The maze
    vector<vector<int>> arr = {{1, 0, 0, 0},
                               {1, 1, 0, 1},
                               {1, 1, 0, 0},
                               {0, 1, 1, 1}};
    // Find all paths in the maze
    vector<string> ans = searchMaze(arr, n);
    // Print all paths
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}
