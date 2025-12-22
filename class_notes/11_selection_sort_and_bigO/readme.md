# Lecture notes

## table of contents
1. Big O Notation
2. Selection Sort


## Big O Notaion
Big O Notation is a mathematical notation used in computer science to describe the time complexity (how fast:the number of steps the algorithm takes to complete) or space complexity (how much memory:the number of additional memory cells the algorithm needs to complete) an algorithm uses as the input size grows. It focuses on the worst-case scenario, helping to estimate how the performance of an algorithm scales with larger inputs.


### Big O Notation Simplification

**Big O notation** describes the upper bound of the time or space complexity of an algorithm, showing how its performance scales as the input size increases. To simplify Big O expressions, follow these key principles:

### Simplification Rules:

1. **Ignore constants**: 
   - Constants don’t matter in Big O because we're only concerned with how the algorithm grows as the input size grows. 
   - Examples:
     - $O(2n)$ simplifies to $O(n)$.
     - $O(100n + 5)$ simplifies to $O(n)$.

2. **Drop non-dominant terms**: 
   - When an algorithm has multiple terms, keep only the term that grows the fastest as $n$ increases. 
   - Examples:
     - $O(n^2 + n)$ simplifies to $O(n^2)$ because $n^2$ grows faster than $n$ as $n$ increases.
     - $O(n^3 + n^2 + n)$ simplifies to $O(n^3)$.

3. **Focus on worst-case behavior**: 
   - Big O notation typically represents the worst-case scenario of an algorithm, i.e., the most time or space it will use as input grows.

### Common Big O Complexities (in increasing order of growth):

- $O(1)$ – Constant time
- $O(\log n)$ – Logarithmic time
- $O(n)$ – Linear time
- $O(n \log n)$ – Linearithmic time
- $O(n^2)$ – Quadratic time
- $O(2^n)$ – Exponential time
- $O(n!)$ – Factorial time

As the input size $n$ grows, the dominant term becomes the most significant. That's why lower-order terms and constants are ignored.

### Summary:
Big O notation abstracts away constants and lower-order terms to focus on growth trends.
It helps compare algorithms and predict how they will scale as inputs increase.

## Selection Sort

### Steps for Selection Sort:
* Start with the first element: Assume that the first element of the unsorted portion is the largest.
* Compare with the rest of the elements: Compare this element with every other element in the unsorted portion. If any element is larger, update the largest element's position.
* Swap: After finding the largest element in the unsorted portion, swap it with the last element of the unsorted portion.
* Move to the next element: Repeat the process for the next element (excluding the already sorted part at the end).
* Repeat until the entire array is sorted.

### C++ Implementation of Selection Sort (Finding Maximum Element)
```cpp
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
```

### Explanation:
1. Outer Loop ```for (int i = n - 1; i >= 0; i--)```:
   * Each iteration places the maximum element in the unsorted portion at the correct position at the end of the array.

2. Inner Loop ```for (int j = 0; j <= i; j++)```:
   * This loop looks for the maximum element in the unsorted portion (from 0 to i).
   * It updates maxIndex whenever it finds an element larger than the current maximum.

3. Swapping:
* The largest element found in the unsorted portion is swapped with the last element of that portion ```arr[i]```.


#### Example Output:
```c
Original array: 64 25 12 22 11 
Sorted array: 11 12 22 25 64
```

### Complexity Analysis

### Time Complexity

Selection Sort always performs the same number of comparisons regardless of the input order. Because of this, its best, average, and worst case time complexities are the same.

1. Outer Loop:
   Runs from i = n-1 down to 0 → executes n times.

2. Inner Loop:
   For each iteration of the outer loop, the inner loop scans from j = 0 to i.
   So the number of comparisons is:
   (n) + (n-1) + (n-2) + ... + 1
   = n(n + 1)/2
   = O(n²)

3. Swaps:
   Selection Sort performs at most one swap per outer-loop iteration, so it performs n swaps.

### Best-Case Time Complexity: O(n²)
Even if the array is already sorted, Selection Sort still runs all comparisons.

### Average-Case Time Complexity: O(n²)
The algorithm must still search the entire unsorted portion each time.

### Worst-Case Time Complexity: O(n²)
Even in the worst ordering, Selection Sort performs the same number of comparisons.

### Space Complexity: O(1)

Selection Sort is an in-place sorting algorithm:
It uses only a constant amount of extra memory (temporary variables).

### Stability

Selection Sort is not stable.
Swapping the maximum element with arr[i] can change the relative order of equal elements.

