#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        // Find the maximum element in the unsorted portion
        int maxIndex = i;
        for (int j =0; j <= i; j++)
        {
            if (arr[j] > arr[maxIndex]) 
                maxIndex = j;  // Update maxIndex if a smaller element is found           
        }
        // Swap the found maximum element with the first element of the unsorted portion
        swap(arr[maxIndex], arr[i]);
    }
}

void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
    cout << endl;
}


int main() 
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}