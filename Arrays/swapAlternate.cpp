 /**
 * The swapAlternate function takes an array and its size as parameters and swaps the alternate elements of the array.
 * For example, if the input array is [1, 2, 3, 4, 5, 6], the function will swap the elements at indices 0 and 1, 2 and 3, and 4 and 5.
 * The printArray function is used to print the modified array.
 */

#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{
    int arr[6] = {1, 2, 3, 4, 5, 6};
    swapAlternate(arr, 6);
    printArray(arr, 6);
    return 0;
}