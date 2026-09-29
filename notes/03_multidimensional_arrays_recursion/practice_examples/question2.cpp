#include<iostream>

using namespace std;

int count_occurrences(int arr[], int size, int target)
{
    if(size==0) return 0;
    
    if(arr[size-1] == target) return 1+count_occurrences(arr,size-1,target);

    else return 0+count_occurrences(arr,size-1,target);
}

int main()
{
    int arr[] = {2, 5, 2, 8, 2, 7};
    int size = 6;

    cout << count_occurrences(arr, size, 2) << endl;
    return 0;
}
