/**
 * @brief This code finds all the paths from the source cell to the destination cell in a maze.
 *
 * The maze is represented as a 2D grid where 1 represents a valid path and 0 represents a blocked path.
 * The code uses recursion to explore all possible paths from the source cell to the destination cell.
 * It backtracks when all directions have been explored from a particular cell.
 * The code returns a vector of strings, where each string represents a valid path from the source to the destination.
 * The paths are sorted in lexicographical order before being returned.
 */

#include <bits/stdc++.h>
using namespace std;

// Given a maze of size n*n, we have to find all the paths from the source cell to the destination cell
void solve(vector<vector<int>> &m, int n, int srcX, int srcY, vector<vector<int>> &visited, string path, vector<string> &answer)
{

    // Base Case
    // If we reach the destination
    if (srcX == n - 1 && srcY == n - 1)
    {
        answer.push_back(path);
        return;
    }

    // If we go out of the maze or we encounter a 0 or we encounter a visited cell
    if (srcX < 0 || srcY < 0 || srcX >= n || srcY >= n || m[srcX][srcY] == 0 || visited[srcX][srcY] == 1)
    {
        return;
    }

    // Recursive Case
    // Mark the current cell as visited since m srcX srcY is a valid cell that is srcX>0 && srcY>0 && srcX<n && srcY<n && m[srcX][srcY] == 1 && visited[srcX][srcY] == 0
    visited[srcX][srcY] = 1;

    // Explore all the directions
    // For Down 'D' we increment the row number that is srcX+1
    solve(m, n, srcX + 1, srcY, visited, path + "D", answer);

    // For Left 'L' we decrement the column number that is srcY-1
    solve(m, n, srcX, srcY - 1, visited, path + "L", answer);

    // For Right 'R' we increment the column number that is srcY+1
    solve(m, n, srcX, srcY + 1, visited, path + "R", answer);

    // For Up 'U' we decrement the row number that is srcX-1
    solve(m, n, srcX - 1, srcY, visited, path + "U", answer);

    // Backtrack because we have explored all the directions from the current cell
    visited[srcX][srcY] = 0;
}

// Function to find all the paths from the source cell to the destination cell
vector<string> findPath(vector<vector<int>> &m, int n)
{
    vector<string> answer;

    // srcX is the row number and srcY is the column number
    int srcX = 0, srcY = 0;
    string path = "";

    // If the first cell is 0 then we cannot reach the destination
    if (m[0][0] == 0)
    {
        return answer;
    }

    // visited is a 2D vector to keep track of the visited cells which is initially 0
    vector<vector<int>> visited(n, vector<int>(n, 0));

    // Call the solve function
    solve(m, n, srcX, srcY, visited, path, answer);

    // Sort the paths in lexicographical order that is alphabetical order
    sort(answer.begin(), answer.end());

    // Return the answer
    return answer;
}

int main()
{
    int n = 4;
    vector<vector<int>> m = {{1, 0, 0, 0},
                             {1, 1, 0, 1},
                             {1, 1, 0, 0},
                             {0, 1, 1, 1}};

    // Call the findPath function
    vector<string> answer = findPath(m, n);

    // Print the paths
    for (auto i : answer)
    {
        cout << i << " ";
    }
    return 0;
}