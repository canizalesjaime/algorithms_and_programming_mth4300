# Lecture Notes

## table of contents
1. Arrays Continued
2. Recursion
3. Function Call Stack
4. Practice Examples


## Arrays Continued
In C++, an array is a data structure that can hold a fixed-size sequence of elements of the same type. Arrays are useful for storing multiple values in a single variable and can be accessed using an index.


#### Array Size
The size of an array is fixed when it is declared. However, you can use the sizeof operator to determine the number of elements in an array:

#### Example:

```cpp
#include <iostream>
using namespace std;

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Array size: " << size; // Outputs 5
    return 0;
}
```

### Creating a 2D Array

A 2D array can be thought of as a table containing rows and columns.

```cpp
int arr[3][4] = {
    {1,  2,  3,  4},
    {5, 20,  7,  8},
    {9, 10, 11, 12}
};
```

This array has 3 rows and 4 columns:

```text
1   2   3   4
5  20   7   8
9  10  11  12
```

Elements are accessed using:

```cpp
arr[row][column]
```

For example:

```cpp
cout << arr[0][0];  // 1
cout << arr[1][1];  // 20
cout << arr[2][3];  // 12
```

C++ array indexes start at 0.

---

### Printing a 2D Array

Because a 2D array has rows and columns, we can use two nested loops.

```cpp
#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] = {
        {1,  2,  3,  4},
        {5, 20,  7,  8},
        {9, 10, 11, 12}
    };

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }

        cout << endl;
    }

    return 0;
}
```

Output:

```text
1 2 3 4
5 20 7 8
9 10 11 12
```

The outer loop moves through the rows:

```cpp
for (int row = 0; row < 3; row++)
```

The inner loop moves through the columns:

```cpp
for (int col = 0; col < 4; col++)
```

Therefore, the array is accessed in this order:

```text
arr[0][0]
arr[0][1]
arr[0][2]
arr[0][3]

arr[1][0]
arr[1][1]
arr[1][2]
arr[1][3]

arr[2][0]
arr[2][1]
arr[2][2]
arr[2][3]
```

The `endl` is placed after the inner loop:

```cpp
cout << endl;
```

This causes C++ to move to a new line after printing each complete row.

---

### Finding the Maximum Value

We can find the maximum value while traversing the 2D array.

First, assume that the first element is the maximum:

```cpp
int max = arr[0][0];
```

Then compare every element against `max`.

```cpp
if (arr[row][col] > max)
{
    max = arr[row][col];
}
```

If the current element is larger than `max`, we update `max`.

---

### Printing the Array and Finding the Maximum

```cpp
#include <iostream>
using namespace std;

int main()
{
    int arr[3][4] = {
        {1,  2,  3,  4},
        {5, 20,  7,  8},
        {9, 10, 11, 12}
    };

    int max = arr[0][0];

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";

            if (arr[row][col] > max)
            {
                max = arr[row][col];
            }
        }

        cout << endl;
    }

    cout << "Maximum = " << max << endl;

    return 0;
}
```

Output:

```text
1 2 3 4
5 20 7 8
9 10 11 12

Maximum = 20
```

---

### How the Maximum Search Works

Think of `max` as storing the largest number that we have seen so far.

For example:

```text
Start:

max = 1

Check 1:
1 > 1? No
max = 1

Check 2:
2 > 1? Yes
max = 2

Check 3:
3 > 2? Yes
max = 3

Check 4:
4 > 3? Yes
max = 4

Check 5:
5 > 4? Yes
max = 5

Check 20:
20 > 5? Yes
max = 20

Check 7:
7 > 20? No
max = 20

Check 8:
8 > 20? No
max = 20

...
```

The final result is:

```text
max = 20
```

---

### Why Initialize `max` With `arr[0][0]`?

It is better to write:

```cpp
int max = arr[0][0];
```

instead of:

```cpp
int max = 0;
```

Suppose the array contains only negative numbers:

```cpp
int arr[2][3] = {
    {-10, -4, -20},
    {-8, -2, -15}
};
```

If we use:

```cpp
int max = 0;
```

none of the numbers are greater than 0, so the program would incorrectly say:

```text
Maximum = 0
```

But `0` isn't even in the array.

Starting with:

```cpp
int max = arr[0][0];
```

guarantees that `max` begins as an actual value from the array.

---

### General Pattern

The general pattern for traversing a 2D array is:

```cpp
for (int row = 0; row < ROWS; row++)
{
    for (int col = 0; col < COLS; col++)
    {
        // Work with:
        arr[row][col]
    }
}
```

This nested-loop pattern is commonly used for:

- Printing matrices
- Finding maximum/minimum values
- Summing elements
- Searching for values
- Processing images
- Working with grids
- Matrix operations


## Recursion
In C++, recursion is a process in which a function calls itself, either directly or indirectly, to solve a problem. This approach divides a larger problem into smaller sub-problems, solving each one by breaking it down until reaching a base case, which is the simplest form of the problem that can be solved directly.

### Key components of recursion:
* Base Case: The condition that stops the recursive calls to prevent infinite recursion. It directly returns a result without making further recursive calls.
* Recursive Case: The part of the function where the problem is broken down into smaller sub-problems, and the function calls itself with a modified argument.
 

### Example of Recursion in C++
Let's consider a simple example where we calculate the factorial of a number using recursion:

```cpp
#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int factorial(int n) {
    if (n == 0) {
        // Base case: factorial of 0 is 1
        return 1;
    } else {
        // Recursive case: n * factorial of (n-1)
        return n * factorial(n - 1);
    }
}

int main() {
    int number = 5;
    cout << "Factorial of " << number << " is " << factorial(number) << endl;
    return 0;
}
```

#### How it works:
* Base Case: if (n == 0) stops the recursion and returns 1.
* Recursive Case: For values greater than 0, the function calls itself with n-1.
In this example:

* factorial(5) calls factorial(4), which calls factorial(3), and so on until factorial(0), which returns 1.
* Then, the calls unwind and the results are multiplied to give the final result.

### Advantages of Recursion:
* Simpler and more intuitive code for problems that can naturally be broken into sub-problems (e.g., factorial, Fibonacci, tree traversal).

### Disadvantages of Recursion:
* Can be inefficient in terms of both time and space due to repeated function calls and stack memory usage.
* Risk of stack overflow if recursion depth becomes too large.
Recursion is a powerful tool but should be used with care, especially for problems that can have a large depth of recursive calls.


## Function Call Stack
In C++, when a function is called recursively, the compiler uses a **call stack** to manage function calls and local variables. This is a crucial part of how recursion works.

---

### **1. What is the Function Call Stack?**
The **function call stack** is a **LIFO (Last In, First Out)** data structure used by the compiler to store:
1. **Function return addresses**
2. **Local variables**
3. **Parameters passed to functions**
4. **Saved registers (context switching between functions)**

Each function call creates a **stack frame** that holds the above information. When a function returns, its frame is popped from the stack.

---

### **2. How the Call Stack Works in Recursion**
Let's consider a recursive function to compute factorial:

### **Example: Factorial Function**
```cpp
#include <iostream>
using namespace std;

int factorial(int n) {
    if (n == 0) return 1;  // Base case
    return n * factorial(n - 1);  // Recursive call
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;
    return 0;
}
```

#### Execution Steps (Stack Frames)
| Call          | Function         | Return Address            | Local Variables |
|--------------|----------------|--------------------------|----------------|
| `main()`      | Calls `factorial(5)` | --                       | `n = 5`        |
| `factorial(5)` | Calls `factorial(4)` | `return 5 * factorial(4)` | `n = 5`        |
| `factorial(4)` | Calls `factorial(3)` | `return 4 * factorial(3)` | `n = 4`        |
| `factorial(3)` | Calls `factorial(2)` | `return 3 * factorial(2)` | `n = 3`        |
| `factorial(2)` | Calls `factorial(1)` | `return 2 * factorial(1)` | `n = 2`        |
| `factorial(1)` | Calls `factorial(0)` | `return 1 * factorial(0)` | `n = 1`        |
| `factorial(0)` | Returns `1` (Base Case) | --                     | `n = 0`        |


Once `factorial(0)` returns `1`, the stack starts popping:

- `factorial(1) → return 1 * 1 = 1`
- `factorial(2) → return 2 * 1 = 2`
- `factorial(3) → return 3 * 2 = 6`
- `factorial(4) → return 4 * 6 = 24`
- `factorial(5) → return 5 * 24 = 120`

Finally, `main()` receives the result `120` and the program ends.

### 3. Stack Overflow in Recursion
If recursion depth is too large, the stack runs out of space, causing a stack overflow error.

#### Example of Infinite Recursion (Stack Overflow)
```cpp
void infiniteRecursion() {
    infiniteRecursion();  // No base case
}

int main() {
    infiniteRecursion();  // Stack overflow!
    return 0;
}
```
Since there's no base case, the function never terminates, and the call stack fills up until the program crashes.

### 4. Tail Recursion Optimization
#### Problem with Regular Recursion
Each recursive call creates a new stack frame, increasing memory usage. Tail recursion is a technique where the recursive call is the last operation in the function, allowing the compiler to optimize memory usage.

#### Example of Tail Recursion (Optimized)
```cpp
#include <iostream>
using namespace std;

int tailFactorial(int n, int result = 1) {
    if (n == 0) return result;  // Base case
    return tailFactorial(n - 1, n * result);  // Tail recursive call
}

int main() {
    cout << "Factorial of 5: " << tailFactorial(5) << endl;
    return 0;
}
```
💡 In tail recursion, the compiler can replace recursive calls with a loop internally (tail call optimization). However, C++ does not guarantee tail call optimization.

### 5. Function Call Stack vs. Explicit Stack
Instead of recursion, we can use an explicit stack (like ```std::stack```) to manage function calls manually.

#### Example: Iterative Factorial Using a Stack
```cpp
#include <iostream>
#include <stack>

int factorial(int n) {
    std::stack<int> s;
    int result = 1;

    for (int i = 1; i <= n; i++)
        s.push(i);

    while (!s.empty()) {
        result *= s.top();
        s.pop();
    }

    return result;
}

int main() {
    std::cout << "Factorial of 5: " << factorial(5) << std::endl;
    return 0;
}
```

Advantages of an explicit stack: ✔ Avoids recursion overhead.
✔ Prevents stack overflow for deep recursion cases.

### Conclusion
* The function call stack is used to manage recursion.
* Each recursive function call creates a stack frame that stores local variables and return addresses.
* Stack overflow occurs when too many recursive calls fill up the memory.
* Tail recursion can optimize memory usage in some compilers.
* Explicit stacks (```std::stack```) can be used instead of recursion for better control.

## Practice Examples
1. Write a C++ program, that prompts the user for the number of rows and 
columns in a 2-dimensional array. For each cell in the 2d array, if the column
is even compute row raised to column(r^c) and store in that cell, otherwise 
store 0. For row 0 and col 0(arr[0][0]), you can just store 0(since indeterminate).
Print the computed 2d array. 

**Example:** let the input be 4 for row and 5 for column, then the output will be:<br>
```math
\begin{bmatrix}
 0 & 0 & 0 & 0 & 0 \\
 1 & 0 & 1 & 0 & 1 \\
 1 & 0 & 4 & 0 & 16 \\
 1 & 0 & 9 & 0 & 81 
\end{bmatrix}
```

2. In C++, write a function that computes the nth fibonacci number from the 
fibonacci sequence. Make sure to use recursion in your function.
