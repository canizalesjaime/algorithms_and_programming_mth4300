# Lecture Notes

## table of contents
1. Arrays Continued
2. Recursion
3. Function Call Stack
4. Recursion Examples:
5. Practice Examples


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

### **What is the Function Call Stack?**
The **function call stack** is a **LIFO (Last In, First Out)** data structure used by the compiler to store:
1. **Function return addresses**
2. **Local variables**
3. **Parameters passed to functions**
4. **Saved registers (context switching between functions)**

Each function call creates a **stack frame** that holds the above information. When a function returns, its frame is popped from the stack.

---

### **How the Call Stack Works in Recursion**
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

### Stack Overflow in Recursion
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


## Recursion Examples: Sum of an Array, Find Minimum, and Fibonacci

### Sum of an Array Recursively

Suppose we have:

```cpp
int arr[] = {1, 2, 3, 4, 5};
```

We want to calculate:

\[
1 + 2 + 3 + 4 + 5 = 15
\]

Normally, we could use a loop.

With recursion, however, we want to reduce the problem into smaller versions of itself.

---

### Recursive Idea

Suppose our function is:

```cpp
recursive_sum(arr, size, pos)
```

where:

- `arr` is the array.
- `size` is the number of elements.
- `pos` is our current position in the array.

At each position, we can say:

$\text{sum from position } pos=arr[pos] + \text{sum from position } pos+1$

For example:

```text
arr = {1, 2, 3, 4, 5}
```

Starting at position `0`:

```text
1 + sum of everything after 1
```

Then:

```text
1 + (2 + sum of everything after 2)
```

Then:

```text
1 + (2 + (3 + sum of everything after 3))
```

and so on.

---

### Base Case

Eventually:

```text
pos == size
```

For an array of size 5, the valid positions are:

```text
0 1 2 3 4
```

So when:

```text
pos == 5
```

there are no elements left to add.

The sum of no elements is:

$0$

Therefore our base case is:

```cpp
if (pos == size)
    return 0;
```

---

### Complete Function

```cpp
int recursive_sum(int arr[], int size, int pos)
{
    if (pos == size)
        return 0;

    return arr[pos] + recursive_sum(arr, size, pos + 1);
}
```

We can call it with:

```cpp
int main()
{
    int arr[] = {1, 2, 3, 4, 5};

    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << recursive_sum(arr, size, 0) << std::endl;

    return 0;
}
```

The output is:

```text
15
```

---

### Tracing the Recursive Sum

Let's look at:

```cpp
recursive_sum(arr, 5, 0)
```

The first call returns:

```text
arr[0] + recursive_sum(arr, 5, 1)
```

which becomes:

```text
1 + recursive_sum(arr, 5, 1)
```

The next call gives:

```text
1 + (2 + recursive_sum(arr, 5, 2))
```

Then:

```text
1 + (2 + (3 + recursive_sum(arr, 5, 3)))
```

Then:

```text
1 + (2 + (3 + (4 + recursive_sum(arr, 5, 4))))
```

Then:

```text
1 + (2 + (3 + (4 + (5 + recursive_sum(arr, 5, 5)))))
```

Now:

```text
pos == size
```

so:

```cpp
recursive_sum(arr, 5, 5)
```

returns:

```text
0
```

Therefore:

```text
1 + 2 + 3 + 4 + 5 + 0
```

The recursion begins returning:

```text
recursive_sum(arr, 5, 5) = 0

recursive_sum(arr, 5, 4) = 5 + 0
                           = 5

recursive_sum(arr, 5, 3) = 4 + 5
                           = 9

recursive_sum(arr, 5, 2) = 3 + 9
                           = 12

recursive_sum(arr, 5, 1) = 2 + 12
                           = 14

recursive_sum(arr, 5, 0) = 1 + 14
                           = 15
```

So:

$\boxed{15}$

---

### Why the Base Case Matters

Imagine that we didn't have:

```cpp
if (pos == size)
    return 0;
```

Then the calls would continue:

```text
recursive_sum(arr, 5, 0)
recursive_sum(arr, 5, 1)
recursive_sum(arr, 5, 2)
recursive_sum(arr, 5, 3)
recursive_sum(arr, 5, 4)
recursive_sum(arr, 5, 5)
recursive_sum(arr, 5, 6)
recursive_sum(arr, 5, 7)
...
```

The recursion would never intentionally stop.

We would also start accessing positions outside of our array.

Eventually, we could get a stack overflow or other undefined behavior.

Therefore, always ask yourself:

```text
1. What is my base case?

2. How does each recursive call move closer to the base case?
```

For our array:

```cpp
pos + 1
```

moves us closer to:

```cpp
pos == size
```

---

### Recursive Find Minimum 
```cpp
find_min(arr, size)
```

The idea is:

> Find the minimum of the first `size - 1` elements, then compare that result with the last element.

---

# 1. The Problem

Suppose we have:

```cpp
int arr[] = {8, 3, 17, 2, 12};
```

We want our recursive function to return:

```text
2
```

Our function will look like:

```cpp
int find_min(int arr[], int size)
```

where:

- `arr` is the array.
- `size` tells us how many elements we are currently considering.

---

# 2. Recursive Idea

Suppose we want to find the minimum of:

```text
{8, 3, 17, 2, 12}
```

Instead of solving the entire problem ourselves, we can ask recursion:

> What is the minimum of the first 4 elements?

Those elements are:

```text
{8, 3, 17, 2}
```

Once recursion gives us that answer, all we need to do is compare it with:

```text
12
```

So conceptually:


$\text{minimum of first 5 elements}=\min(\text{minimum of first 4 elements},\text{5th element})$

More generally:

$\boxed{\text{min}(n)=\min(\text{min}(n-1),arr[n-1])}$

---

### Base Case

Eventually, recursion will reduce the problem to an array containing only one element.

For example:

```text
{8}
```

What is the minimum of an array containing only `8`?

Obviously:

```text
8
```

Therefore:

```cpp
if (size == 1)
    return arr[0];
```

This is our base case.

---

### Complete Function

```cpp
int find_min(int arr[], int size)
{
    if (size == 1)
        return arr[0];

    int previous_min = find_min(arr, size - 1);

    if (arr[size - 1] < previous_min)
        return arr[size - 1];

    return previous_min;
}
```

We can use it like this:

```cpp
#include <iostream>
using namespace std;

int find_min(int arr[], int size)
{
    if (size == 1)
        return arr[0];

    int previous_min = find_min(arr, size - 1);

    if (arr[size - 1] < previous_min)
        return arr[size - 1];

    return previous_min;
}

int main()
{
    int arr[] = {8, 3, 17, 2, 12};

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << find_min(arr, size) << endl;

    return 0;
}
```

Output:

```text
2
```

---

### Tracing the Recursion

We begin with:

```cpp
find_min(arr, 5)
```

Our array is:

```text
index:     0    1    2    3    4
          -----------------------
value:     8    3   17    2   12
```

The function cannot determine the answer yet because it first executes:

```cpp
int previous_min = find_min(arr, size - 1);
```

So:

```cpp
find_min(arr, 5)
```

calls:

```cpp
find_min(arr, 4)
```

That calls:

```cpp
find_min(arr, 3)
```

That calls:

```cpp
find_min(arr, 2)
```

That calls:

```cpp
find_min(arr, 1)
```

So the calls look like:

```text
find_min(arr, 5)
        |
        v
find_min(arr, 4)
        |
        v
find_min(arr, 3)
        |
        v
find_min(arr, 2)
        |
        v
find_min(arr, 1)
```

---

### Reaching the Base Case

Eventually:

```cpp
find_min(arr, 1)
```

executes:

```cpp
if (size == 1)
    return arr[0];
```

Since:

```text
arr[0] = 8
```

we return:

```text
8
```

Now recursion starts going back upward.

---

### Coming Back Up

We return to:

```cpp
find_min(arr, 2)
```

The recursive call gave us:

```text
previous_min = 8
```

Now we compare:

```cpp
arr[size - 1]
```

Since:

```text
size = 2
```

we have:

```cpp
arr[2 - 1]
```

which is:

```cpp
arr[1]
```

and:

```text
arr[1] = 3
```

So we compare:

```text
3 < 8
```

This is true.

Therefore:

```text
return 3
```

---

Now we return to:

```cpp
find_min(arr, 3)
```

The recursive call returned:

```text
previous_min = 3
```

The current element is:

```cpp
arr[3 - 1]
```

which is:

```cpp
arr[2] = 17
```

Compare:

```text
17 < 3
```

False.

Therefore:

```text
return 3
```

---

Now we return to:

```cpp
find_min(arr, 4)
```

The recursive call returned:

```text
previous_min = 3
```

The current element is:

```cpp
arr[4 - 1]
```

which is:

```cpp
arr[3] = 2
```

Compare:

```text
2 < 3
```

True.

Therefore:

```text
return 2
```

---

Finally, we return to:

```cpp
find_min(arr, 5)
```

The recursive call returned:

```text
previous_min = 2
```

The current element is:

```cpp
arr[5 - 1]
```

which is:

```cpp
arr[4] = 12
```

Compare:

```text
12 < 2
```

False.

Therefore:

```text
return 2
```

Our final answer is:

```text
2
```

---

### Visualizing the Entire Process

First, recursion goes down:

```text
find_min(arr, 5)
        |
        v
find_min(arr, 4)
        |
        v
find_min(arr, 3)
        |
        v
find_min(arr, 2)
        |
        v
find_min(arr, 1)
        |
        v
   BASE CASE
        |
        v
        8
```

Then the answers come back up:

```text
find_min(arr, 1) = 8
        |
        v
min(8, 3) = 3
        |
        v
min(3, 17) = 3
        |
        v
min(3, 2) = 2
        |
        v
min(2, 12) = 2
```

Therefore:

```text
find_min(arr, 5) = 2
```
---


### Fibonacci Recursion

Another classic example of recursion is the Fibonacci sequence.

The Fibonacci sequence begins:

```text
0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
```

Each number is the sum of the previous two numbers.

Mathematically:

$\boxed{F(n) = F(n-1) + F(n-2)}$

For example:

$F(6) = F(5) + F(4)$

Since:

$F(5)=5$

and:

$F(4)=3$

we get:

$F(6)=5+3=8$

---

### Fibonacci Base Cases

We need somewhere for the recursion to stop.

The first two Fibonacci numbers are defined as:

$F(0)=0$

and:

$F(1)=1$

These are our base cases.

We can write:

```cpp
int fibonacci(int n)
{
    if (n == 0)
        return 0;

    if (n == 1)
        return 1;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

Since:

```text
F(0) = 0
F(1) = 1
```

we can also combine the two base cases:

```cpp
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

---

### Complete Fibonacci Program

```cpp
#include <iostream>

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    std::cout << fibonacci(6) << std::endl;

    return 0;
}
```

Output:

```text
8
```

---

### Tracing Fibonacci

Suppose we call:

```cpp
fibonacci(4)
```

According to the formula:

$F(4)=F(3)+F(2)$

But the computer doesn't know `F(3)` or `F(2)` yet.

Therefore, both become recursive calls.

We get:

```text
                    F(4)
                  /      \
               F(3)      F(2)
              /   \      /   \
           F(2)   F(1) F(1)  F(0)
          /   \
       F(1)   F(0)
```

Eventually, every branch reaches one of our base cases:

```text
F(0) = 0
F(1) = 1
```

Now the answers can travel back up.

Start with:

```text
F(2) = F(1) + F(0)
     = 1 + 0
     = 1
```

Then:

```text
F(3) = F(2) + F(1)
     = 1 + 1
     = 2
```

Finally:

```text
F(4) = F(3) + F(2)
     = 2 + 1
     = 3
```

Therefore:

\[
\boxed{F(4)=3}
\]

---

### Fibonacci Introduces a New Idea

Our previous functions only made one recursive call.

For example, `find_min`:

```cpp
return find_min(arr, size, pos + 1, min);
```

creates something resembling a chain:

```text
find_min(...)
      |
      v
find_min(...)
      |
      v
find_min(...)
      |
      v
find_min(...)
```

Fibonacci is different.

It makes **two recursive calls**:

```cpp
return fibonacci(n - 1) + fibonacci(n - 2);
```

Therefore, the calls branch:

```text
                 F(n)
                /    \
           F(n-1)    F(n-2)
            /  \      /  \
           ... ...   ... ...
```

This is called a **recursion tree**.

Recursion does not mean that a function can only call itself once.

A recursive function can make multiple recursive calls.

---

### A Problem With Recursive Fibonacci

Look again at:

```text
                    F(4)
                  /      \
               F(3)      F(2)
              /   \      /   \
           F(2)   F(1) F(1)  F(0)
          /   \
       F(1)   F(0)
```

Notice something interesting.

We calculate:

```text
F(2)
```

more than once.

For larger Fibonacci numbers, this problem becomes much worse.

For example, calculating:

```cpp
fibonacci(40)
```

causes the program to repeatedly calculate many of the same Fibonacci numbers.

So this version:

```cpp
int fibonacci(int n)
{
    if (n <= 1)
        return n;

    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

is excellent for **learning recursion**, but it is not an efficient way to calculate large Fibonacci numbers.

Later, this problem can introduce an important concept called **memoization**, where we save previously calculated answers instead of calculating them repeatedly.

---



## The Most Important Recursion Questions

Whenever you are trying to create a recursive solution, ask yourself:

```text
1. What is the smaller version of this problem?

2. What is my base case?

3. How does each recursive call move toward the base case?

4. What does the recursive call return?

5. What do I do with the value returned by the recursive call?
```

For the array sum:

```text
Base case:
pos == size

Smaller problem:
sum the array starting at pos + 1

Recursive relationship:
arr[pos] + recursive_sum(..., pos + 1)
```

For find minimum:

```text
Base case:
pos == size

Smaller problem:
search the remaining elements starting at pos + 1

Information carried forward:
current minimum

Recursive relationship:
find_min(..., pos + 1, min)
```

For Fibonacci:

```text
Base cases:
F(0) = 0
F(1) = 1

Smaller problems:
F(n - 1)
F(n - 2)

Recursive relationship:
F(n) = F(n - 1) + F(n - 2)
```

These three examples demonstrate three very useful ways to start thinking recursively.

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

2. Given the following array:

```cpp
int arr[] = {2, 5, 2, 8, 2, 7};
```

Write a recursive function:

```cpp
int count_occurrences(int arr[], int size, int target)
```

that returns the number of times `target` appears in the array.

For example:

```cpp
int main()
{
    int arr[] = {2, 5, 2, 8, 2, 7};
    int size = 6;

    cout << count_occurrences(arr, size, 2) << endl;

    return 0;
}
```

The expected output is:

```text
3
```

- You may **not** use a `for` loop or `while` loop.
- Your solution must use recursion.
- Each recursive call should reduce the size of the problem.
- Your function must contain a base case.