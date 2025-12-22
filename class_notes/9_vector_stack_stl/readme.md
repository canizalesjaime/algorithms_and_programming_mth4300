# Lecture notes

## table of contents
1. Vectors
2. Stacks
3. STL 
4. Practice Examples

## LINKS 
For more info on stl containers visit: https://en.cppreference.com/w/cpp/container.html

## Vector Class
A ```C++``` ```vector``` is a dynamic array that can grow or shrink in size. Let's break down how a ```vector``` works as a class and what its key components are.


#### Key Components of the Vector 
* Data Member (```string* data```):  
  * The vector stores a pointer to a dynamically allocated array where the elements are stored.
* Size and Capacity:  
  * The ```size``` keeps track of the number of elements that have been added to the vector, while ```capacity``` represents the amount of allocated memory. If more elements are added than the current capacity, the array is resized (usually doubled).

* Constructor and Destructor:  
  * The constructor initializes the vector with a default capacity of 1. The destructor releases the memory when the object goes out of scope to prevent memory leaks.

* insert:  
  * The ```insert``` function adds a new element at a specified position within the vector. To make space, all elements from that position to the end are shifted one place to the right.  
  * If the vector’s current size equals its capacity, the function first calls ```resize()``` to allocate more space before performing the shift.  
  * This operation has **O(n)** time complexity since it may involve shifting multiple elements.

* erase:  
  * The ```erase``` function removes an element at a given position and shifts all subsequent elements one position to the left to fill the gap.  
  * It decrements the ```size``` but does not reduce the ```capacity```, allowing efficient future insertions.  
  * This operation also has **O(n)** time complexity due to element shifting.

* operator[]:  
  * Overloading the ```[]``` operator allows access to elements by their index, just like an array. It also checks for out-of-bounds access.

* resize():  
  * This is a helper function that reallocates memory for the vector when the current capacity is reached, ensuring that the vector can continue to grow dynamically.

See interface: [vector](./vector.h)
See implementation: [vector](./vector.cpp) 

### Real-world Vector Example in STL
The ```std::vector``` class in the STL works similarly, but with many more features and optimizations (e.g., iterators, range-based access, etc.). Here's how you'd use ```std::vector```:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << " ";
    }

    return 0;
}
```

In this case, the ```std::vector<int>``` stores integers, dynamically grows, and manages its memory efficiently without the need for manual memory management.

### Why Use a Template for Vectors?
Using templates allows you to write generic code that works with any data type. This avoids code duplication and makes the ```vector``` class versatile, enabling you to store objects of any type:

```std::vector<int>``` for integers
```std::vector<std::string>``` for strings
```std::vector<MyClass>``` for user-defined types like ```MyClass```



## Stacks
A **stack** is a linear data structure that follows the **LIFO** (Last In, First Out) principle, meaning the last element added to the stack is the first one to be removed. It can be visualized as a collection of items stacked on top of each other, where only the topmost item can be accessed or removed.

### Key Operations of a Stack:
* **Push:** Adds an element to the top of the stack.
* **Pop:** Removes the element from the top of the stack.
* **Peek (or Top):** Retrieves the top element without removing it.
* **isEmpty:** Checks if the stack is empty.


### Advantages of a Stack:
* Simplicity: Ideal for solving problems like reversing a string or validating parentheses.
* Efficient: Push and pop operations are O(1).
* Useful in algorithms like depth-first search, function call stacks, etc.

### Applications of a Stack:
* **Expression Evaluation:** Parsing and evaluating expressions (e.g., postfix evaluation).
* **Undo Mechanism:** Used in text editors for undo operations.
* **Recursion:** Call stack in programming.
* **Depth-First Search (DFS):** Used in graph and tree traversal algorithms.


##  What Is the STL?
The **Standard Template Library (STL)** in C++ provides **generic, reusable data structures and algorithms**.  
It includes:
- **Containers** – store and organize data
- **Iterators** – provide a way to access elements in containers
- **Algorithms** – perform operations like sorting, searching, etc.
- **Functors/adapters** – modify or customize behavior

---

##  1. `std::vector`
A **vector** is a **dynamic array** that can change size at runtime.

### Key features:
- Elements stored **contiguously** in memory.
- Provides **random access** (constant time using `[]` or `.at()`).
- **Fast insertion/removal** at the end (`push_back`, `pop_back`).
- **Slower insertion/removal** in the middle or front (requires shifting elements).

### Main operations:
| Operation | Description |
|------------|--------------|
| `push_back(x)` | Adds an element to the end. |
| `pop_back()` | Removes the last element. |
| `insert(pos, x)` | Inserts an element **before** position `pos`. |
| `erase(pos)` | Removes the element **at** position `pos`. |
| `clear()` | Removes all elements. |
| `size()` / `empty()` | Returns number of elements / checks if empty. |

### Example:
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};
    v.push_back(4);             // [1, 2, 3, 4]
    v.insert(v.begin() + 1, 10); // [1, 10, 2, 3, 4]
    v.erase(v.begin() + 2);     // [1, 10, 3, 4]

    for (int x : v)
        cout << x << " "; // 1 10 3 4
}
```

---

##  2. `std::stack`
A **stack** is a **Last-In, First-Out (LIFO)** container adapter.

- Built on top of another container (usually a `deque` or `vector`).
- Only allows access to the **top** element.
- No iterators or random access.

### Main operations:
- `push(x)` — add to top  
- `pop()` — remove top element  
- `top()` — access top element  

### Example:
```cpp
#include <stack>
#include <iostream>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    cout << s.top() << endl; // 20
    s.pop();
    cout << s.top() << endl; // 10
}
```

---

##  3. `std::queue`
A **queue** is a **First-In, First-Out (FIFO)** container adapter.

- Built on top of a `deque` by default.
- Access only to **front** (oldest) and **back** (newest) elements.

### Main operations:
- `push(x)` — add at back  
- `pop()` — remove from front  
- `front()` — access oldest element  
- `back()` — access newest element  

### Example:
```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    cout << q.front() << endl; // 1
    q.pop();
    cout << q.front() << endl; // 2
}
```

---

## 4. Iterators
**Iterators** act like **pointers** that let you traverse containers.

They provide a **uniform way** to access elements, regardless of the container type.

### Example:
```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    vector<int>::iterator it;

    for (it = v.begin(); it != v.end(); ++it)
        cout << *it << " "; // 10 20 30
}
```

### Common iterator types:
- `begin()` / `end()` – start and one-past-end
- `rbegin()` / `rend()` – reverse iterators
- `cbegin()` / `cend()` – constant iterators (read-only)

Iterators make STL algorithms (like `sort`, `find`, etc.) work generically.

---

##  5. Other Containers (briefly)

### 🪣 `std::list`
- **Doubly linked list**
- Fast insertion/removal anywhere (no shifting)
- **No random access** (`[]` doesn’t work)
- Great when frequent insertions/removals are needed.

```cpp
list<int> lst = {1, 2, 3};
lst.push_front(0); // 0 1 2 3
```

---

###  `std::map`
- Stores **key–value pairs** in **sorted order (by key)**.
- Implemented as a **balanced binary search tree (usually Red-Black Tree)**.
- Keys are **unique**.
- Search, insertion, and deletion: **O(log n)**.

```cpp
map<string, int> ages;
ages["Alice"] = 25;
ages["Bob"] = 30;
cout << ages["Alice"]; // 25
```

---

###  `std::unordered_map`
- Stores **key–value pairs** in **hash table**.
- **No ordering** of keys.
- Search, insertion, deletion: **O(1)** average.
- Useful for fast lookups.

```cpp
unordered_map<string, int> score;
score["Tom"] = 90;
score["Jerry"] = 85;
```

---

## Summary Table

| Container         | Type               | Ordered | Duplicates | Access | Insert/Erase | Implementation |
|-------------------|--------------------|----------|-------------|---------|---------------|----------------|
| `vector`          | Sequence           | Yes      | Yes         | O(1) random | O(n) mid insert | Dynamic array  |
| `stack`           | Adapter (LIFO)     | N/A      | N/A         | Top only | O(1) top | Uses deque/vector |
| `queue`           | Adapter (FIFO)     | N/A      | N/A         | Front/back | O(1) ends | Uses deque/list |
| `list`            | Sequence (linked)  | Yes      | Yes         | O(n) random | O(1) insert/erase | Doubly linked list |
| `map`             | Associative        | Yes (by key) | No | O(log n) | O(log n) | Balanced BST |
| `unordered_map`   | Associative (hash) | No       | No | O(1) avg | O(1) avg | Hash table |


## auto keyword
In short:

auto tells the compiler to deduce the type automatically from the initializer.

Example:
```cpp
auto x = 10;        // x is an int
auto y = 3.14;      // y is a double
auto s = "hello";   // s is a const char*
```

So instead of explicitly writing the type, you let the compiler infer it for you.

### Why It Exists

auto was introduced to:

* Reduce repetition in verbose declarations.
* Avoid mistakes when the real type is long or complex.
* Make code more flexible (e.g., when changing return types or templates).

### Typical Uses
1. Simplify complex iterator declarations

Before auto:
```cpp
std::vector<int> v = {1, 2, 3};
std::vector<int>::iterator it = v.begin();
```

With auto:
```cpp
auto it = v.begin()
```

## Practice Examples
1. Given a queue of strings and an integer k, reverse the order of the first k elements of the queue, leaving the rest of the elements in the same order. You must use:

* A stack to help reverse the first k elements.
* A queue to represent the original data.
* A vector to return or display the final result.

2. Notice that our three classes share a lot of code for managing dynamic arrays. To eliminate this redundancy, create a new class called ResourceArray that encapsulates all the common logic, including the Big Five (constructor, destructor, copy/move constructors, and copy/move assignment operators).
Then, instead of directly managing arrays with new in each of your classes, use ResourceArray as a member to handle the array storage. This way, Queue, Stack, Vector and any other class can reuse the same array management code safely and efficiently.
3. Write a program to implement a stack in C++ that checks if a given string of parentheses is balanced. A string is considered balanced if:
   * Every opening parenthesis ```(,{,[``` has a corresponding and correctly placed closing parenthesis ```), }, ]```.
   * Closing parentheses match the most recently opened parentheses.

   You need to:
   * Implement the stack manually using arrays or STL stack.
   * Write a function bool isBalanced(string str) to check if a string is balanced.
   * Test the function with sample inputs.
4. Solve the for the nth fibonacci number using a stack instead of recursion.
5. Redo question one with STL.