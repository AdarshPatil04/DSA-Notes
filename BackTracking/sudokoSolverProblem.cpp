// Time Complexity: O(9^m)
// Space Complexity: O(1) since the grid size is fixed
// This C++ program solves the Sudoku problem using backtracking.
// The Sudoku problem is a puzzle where you need to fill a 9x9 grid with digits so that each column, each row, and each of the nine 3x3 sub-grids that compose the grid contain all of the digits from 1 to 9.
// The solveSudoku function solves the Sudoku puzzle using backtracking. It starts by finding an unassigned cell in the Sudoku grid. It then tries all numbers from 1 to 9 in the cell and checks if the number is safe to be placed in the cell. If the number is safe, it places the number and recursively tries to solve the rest of the grid. If the grid cannot be solved, it undoes the number placement and tries the next number. If all numbers have been tried and none of them work, the function returns false to backtrack to the previous cell.
// The isSafe function checks if a number can be placed in a given cell. It checks the row, column, and 3x3 grid of the cell for the same number. If the number is found, it returns false; otherwise, it returns true.
// The main function initializes a Sudoku grid, calls the solveSudoku function to solve the grid, and then prints the solved grid.

#include <bits/stdc++.h>
using namespace std;

// Function to check if a number can be placed at the given position
bool isSafe(int row, int col, vector<vector<int>> &board, int val)
{
    // Iterate through each cell in the row, column and 3x3 matrix
    for (int i = 0; i < board.size(); i++)
    {
        // Check the row: if the number already exists in the row, return false
        if (board[row][i] == val)
            return false;

        // Check the column: if the number already exists in the column, return false
        if (board[i][col] == val)
            return false;

        // Check the 3x3 matrix: if the number already exists in the 3x3 matrix, return false
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
        {
            return false;
        }
    }
    // If the number does not exist in the row, column and 3x3 matrix, return true
    return true;
}

// Recursive function to solve the Sudoku problem
bool solve(vector<vector<int>> &board)
{
    // Get the size of the board
    int n = board[0].size();

    // Iterate through each cell in the board
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            // If the cell is empty
            if (board[row][col] == 0)
            {
                // Try placing numbers from 1 to 9 in the cell
                for (int val = 1; val <= 9; val++)
                {
                    // If it is safe to place the number
                    if (isSafe(row, col, board, val))
                    {
                        // Place the number
                        board[row][col] = val;

                        // Recursive call to solve the rest of the board
                        bool furtherSol = solve(board);
                        if (furtherSol)
                        {
                            // If the rest of the board can be solved, return true
                            return true;
                        }
                        else
                        {
                            // If the rest of the board cannot be solved, undo the number placement
                            board[row][col] = 0;
                        }
                    }
                }
                // If no number can be placed in the current cell, return false
                return false;
            }
        }
    }
    // If all cells are filled, return true
    return true;
}

// Function to solve the Sudoku problem
void solveSudoku(vector<vector<int>> &sudoku)
{
    // Call the solve function to solve the Sudoku
    solve(sudoku);
}

int main()
{
    // Initialize the Sudoku board
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};

    // Solve the Sudoku
    solveSudoku(board);

    // Print the solved Sudoku
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
