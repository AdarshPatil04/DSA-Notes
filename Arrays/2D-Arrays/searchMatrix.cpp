/**
 * @brief This code demonstrates how to search for an element in a matrix where each row is sorted and each column is sorted.
 * 
 * The searchMatrix function takes a 2D vector representing the matrix and an integer target as input.
 * It starts from the top right corner of the matrix and compares the target with the current element.
 * If the target is found, the function returns true. 
 * If the target is greater than the current element, it moves to the next row.
 * If the target is smaller than the current element, it moves to the previous column.
 * The function continues this process until the target is found or all elements have been checked.
 * If the target is not found, the function returns false.
 * 
 * @param matrix A 2D vector representing the matrix where each row is sorted and each column is sorted.
 * @param target The element to be searched in the matrix.
 * @return true if the target element is found in the matrix, false otherwise.
 */

#include<bits/stdc++.h>
using namespace std;

/// This function searches for an element in a matrix in which each row is sorted and also each column is sorted.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int rowIndex = 0;

    // colIndex is initialized to m-1 because the last element of the first row is the largest element in the matrix.
    int colIndex = m-1;

    // We start from the top right corner of the matrix.
    while(rowIndex < n && colIndex >= 0){
        int element = matrix[rowIndex][colIndex];

        // If the target element is found, the function returns true; otherwise, it returns false.
        if(element == target){
            return true;
        }

        // If the target element is greater than the current element, we move to the next row because the current element is the l          largest element in the current row.
        else if(target > element){
            rowIndex++;
        }

        // If the target element is smaller than the current element, we move to the previous column because the current element is          the smallest element in the current column.
        else{
            colIndex--;
        }
    }
    return false;
}

int main(){

    // matrix is a 2D vector that stores the elements of the matrix where each row is sorted and also each column is sorted.
    vector<vector<int>> matrix = {{1, 3, 5, 7},
                                  {10, 11, 16, 20},
                                  {23, 30, 34, 60}};

    // target is the element to be searched in the matrix.
    int target = 3;

    // Printing whether the target element is present in the matrix or not.
    cout<<searchMatrix(matrix, target);
    return 0;
}