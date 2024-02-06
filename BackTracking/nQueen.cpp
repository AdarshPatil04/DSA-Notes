#include <bits/stdc++.h>
using namespace std;

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    // Check the row on left side
    int x = row;
    int y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    // Check lower diagonal on left side
    x = row;
    y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++;
        y--;
    }

    // Check upper diagonal on left side
    x = row;
    y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--;
        y--;
    }
    return true;
}

// Function to store the solution in the answers array
void addSolution(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    vector<int> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

// Recursive function to solve N-Queens problem
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
    // base case: If all queens are placed
    if (col == n)
    {
        addSolution(board, ans, n);
        return;
    }

    // Consider this column and try placing queen in all rows one by one
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board, n))
        {
            // Place this queen in board[row][col]
            board[row][col] = 1;

            // recur to place rest of the queens
            solve(col + 1, board, ans, n);

            // If placing queen in board[row][col] doesn't lead to a solution, then remove queen from board[row][col]
            board[row][col] = 0; // BACKTRACK
        }
    }
}

// This function solves the N Queen problem using Backtracking
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;
    int col = 0;
    solve(col, board, ans, n);

    return ans;
}

int main()
{
    int n = 4;
    vector<vector<int>> ans = solveNQueens(n);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
