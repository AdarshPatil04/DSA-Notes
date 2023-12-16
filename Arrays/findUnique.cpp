/**
 * This program finds the unique element in an array using the XOR operation.
 * The XOR operation is used to cancel out the duplicate elements, leaving only the unique element.
 * The unique element is then printed to the console.
 */

#include <iostream>
using namespace std;

void findUnique(int arr[], int size)
{
    int unique = 0;
    for (int i = 0; i < size; i++)
    {
        unique = unique ^ arr[i];
    }
    cout << unique << endl;
}

int main()
{
    int arr[7] = {1, 2, 3, 4, 1, 2, 3};
    findUnique(arr, 7);
}