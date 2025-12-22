# Lecture notes

## table of contents
1. Hash table
2. Maps
3. Practice Examples


## Hash table 
A hash table is a data structure that maps keys to values for efficient lookup. It uses a hashing function to convert keys into indices (or hash codes) within an array, where the values are stored.
Hash tables are widely used for their average-case time complexity of $O(1)$ for lookup, insertion, and deletion.

## Key Concepts of Hash Tables
* Hash Function:
  * A function that takes a key and computes an integer value (hash code), which is used as the index in the hash table.
  * A good hash function minimizes collisions (different keys mapping to the same index).
    Example: For a hash table of size 10:
    ```cpp
    hashCode = key % 10;
    ```

* Buckets:
  * Each index in the hash table array is called a bucket.
  * A bucket may store one or more key-value pairs if collisions occur.

* Collisions:
  * Occurs when multiple keys produce the same hash code.
  * Collision resolution techniques are required to handle these.

* Load Factor:
  * Ratio of the number of elements in the hash table to its size.
  * When the load factor exceeds a threshold, the table is resized (rehashed).

### Operations in a Hash Table
1. **Insertion**
   * Apply the hash function to compute the index for the key.
   * Store the key-value pair at the computed index.
2. **Search**
   * Use the hash function to compute the index.
   * Check the bucket for the key.
3. **Deletion**
   * Compute the index using the hash function.
   * Locate and remove the key-value pair from the bucket.


## Separate Chaining (Collision Resolution Technqiue #1)
Separate chaining resolves collisions by maintaining a list (or chain) of entries at each index (or "bucket") of the hash table.

Instead of storing a single key-value pair at each index, you store a linked list (or other dynamic structure like a list or a tree) of all key-value pairs that hash to that index.

### Example
### Hash Table with Separate Chaining (10 Buckets)

Hash function: hash(key) = key % 10  
Keys inserted: 1, 5, 11, 15, 21, 25, 33, 42, 37, 40

| Key | key % 10 | Bucket |
|-----|----------|--------|
| 1   | 1        | 1      |
| 5   | 5        | 5      |
| 11  | 1        | 1      |
| 15  | 5        | 5      |
| 21  | 1        | 1      |
| 25  | 5        | 5      |
| 33  | 3        | 3      |
| 42  | 2        | 2      |
| 37  | 7        | 7      |
| 40  | 0        | 0      |

Final Hash Table (Buckets with Chaining):

Bucket 0 → [ (40, val40) ]  
Bucket 1 → [ (1, val1), (11, val11), (21, val21) ]  
Bucket 2 → [ (42, val42) ]  
Bucket 3 → [ (33, val33) ]  
Bucket 4 → [ ]  
Bucket 5 → [ (5, val5), (15, val15), (25, val25) ]  
Bucket 6 → [ ]  
Bucket 7 → [ (37, val37) ]  
Bucket 8 → [ ]  
Bucket 9 → [ ]


### Pros and Cons
#### Pros:
* Simple to implement.
* Handles a large number of collisions well (especially if load factor is high).
* Each bucket can grow independently.

#### Cons:
* Can have performance degradation if too many keys hash to the same bucket (long lists).
* Extra memory for pointers in the chains.


## Open Addressing(Collision Resoulution technique #2)
Open addressing is another way to handle collisions in hash tables, but unlike separate chaining, it does not use lists or other structures at each bucket.

Instead, all key-value pairs are stored directly within the array, and when a collision happens, the algorithm looks for another empty slot using a probing sequence.

### How It Works
1. Compute the hash: index = hash(key)
2. If the bucket at index is empty, insert the key there.
3. If the bucket is occupied, probe (search) other slots using a defined probing strategy until an empty one is found.

### Probing Strategies
Here are some common ones:

* Linear probing:
Try ```index + 1```, ```index + 2```, ..., wrapping around the table.
Formula: ```index = (hash(key) + i) % table_size```

* Quadratic probing:
Try ```index + 1^2```, ```index + 2^2```, ..., to reduce clustering.
Formula: 

* Double hashing:
Use a second hash function to determine the step size:
index = (hash1(key) + i * hash2(key)) % table_size

### Example 
In practice, depending on your application, you would select one of the following probing techniques to implement your hash map.

### Hash Function:
`index = key % 10`  
Table size = 10  
Keys to insert: 1, 11, 21, 5

---

### Linear Probing

Probing sequence:  
`index = (hash(key) + i) % table_size`, where `i = 0, 1, 2, ...`

### Insert Steps:

- 1 → `1 % 10 = 1` → Bucket 1 → empty → insert 1  
- 11 → `11 % 10 = 1` → Bucket 1 full → try 2 → insert 11  
- 21 → `21 % 10 = 1` → Buckets 1,2 full → try 3 → insert 21  
- 5 → `5 % 10 = 5` → Bucket 5 → empty → insert 5

### Final Table (Linear Probing):

Index 0: -  
Index 1: 1  
Index 2: 11  
Index 3: 21  
Index 4: -  
Index 5: 5  
Index 6: -  
Index 7: -  
Index 8: -  
Index 9: -

---

## 2. Quadratic Probing

Probing sequence:  
`index = (hash(key) + i^2) % table_size`, where `i = 0, 1, 2, ...`

### Insert Steps:

- 1 → `1 % 10 = 1` → Bucket 1 → empty → insert 1  
- 11 → `11 % 10 = 1`  
  - i=1 → `1 + 1^2 = 2` → Bucket 2 → insert 11  
- 21 → `21 % 10 = 1`  
  - i=1 → 2 (full)  
  - i=2 → `1 + 4 = 5` → Bucket 5 → insert 21  
- 5 → `5 % 10 = 5`  
  - i=0 → 5 (full)  
  - i=1 → `5 + 1 = 6` → insert 5

### Final Table (Quadratic Probing):

Index 0: -  
Index 1: 1  
Index 2: 11  
Index 3: -  
Index 4: -  
Index 5: 21  
Index 6: 5  
Index 7: -  
Index 8: -  
Index 9: -

---

## 3. Double Hashing

Two hash functions:
- `h1(key) = key % 10`
- `h2(key) = 7 - (key % 7)` (secondary hash must be non-zero)

Probing sequence:  
`index = (h1(key) + i * h2(key)) % table_size`

### Insert Steps:

- 1 → h1 = 1, h2 = 6 → `1 + 0*6 = 1` → insert 1  
- 11 → h1 = 1, h2 = 3  
  - i=0 → 1 (full)  
  - i=1 → `1 + 3 = 4` → insert 11  
- 21 → h1 = 1, h2 = 1  
  - i=0 → 1 (full)  
  - i=1 → 2  
  - i=2 → 3 → insert 21  
- 5 → h1 = 5, h2 = 2  
  - i=0 → 5 → insert 5

### Final Table (Double Hashing):

Index 0: -  
Index 1: 1  
Index 2: -  
Index 3: 21  
Index 4: 11  
Index 5: 5  
Index 6: -  
Index 7: -  
Index 8: -  
Index 9: -

---

### Summary of Open Addressing Types

| Method            | Probing Strategy                            | Pros                              | Cons                             |
|-------------------|---------------------------------------------|-----------------------------------|----------------------------------|
| Linear Probing    | +1, +2, +3, ...                              | Simple                            | Clustering can occur             |
| Quadratic Probing | +1^2, +2^2, +3^2, ...                        | Reduces clustering                | Can skip available slots         |
| Double Hashing    | h1(key) + i * h2(key)                       | Best distribution, fewer clusters | Slightly more complex to implement |


### Pros and Cons
#### Pros:
* No pointers or extra structures needed
* Everything stays in one array

#### Cons:
* Clustering: consecutive filled slots can slow down operations
* Deletion is tricky (need special "deleted" markers)
* Table must not be too full (performance drops at high load factor)


## Optimizing a hash map to enusre avcerage time O(1) insertion, deletion and search
| Optimization                  | Description                                                | Benefit                          |
|------------------------------|------------------------------------------------------------|----------------------------------|
| Good hash function           | Uniformly distributes keys, fast to compute               | Fewer collisions                 |
| Low load factor (< 0.7)      | Resize when table gets too full                           | Keeps lookup O(1) on average     |
| Prime-sized table            | Avoids clustering from poor modulus math                  | Better key spread                |
| Double/quadratic probing     | Avoids primary clustering in open addressing              | Faster lookups                   |
| Balanced trees in chaining   | Convert long chains to trees (e.g., Java HashMap)         | Keeps worst-case O(log n)        |
| Cache-friendly layout        | Use arrays instead of scattered pointers                  | Faster access                    |
| Smart deletion (tombstones)  | Avoid breaking probe chains in open addressing            | Correctness and performance      |
| Dynamic resizing             | Rehash table when threshold reached                       | Maintains performance over time  |
| Avoid patterned keys         | Use strong hashes for common key types (e.g., strings)    | Prevents hotspots                |
| Use of specialized hashing   | E.g., Robin Hood, Cuckoo, Hopscotch for better bounds     | More predictable performance     |


### Conclusion
### Applications of Hash Tables
* **Databases:** Indexing for fast query results.
* **Caching:** Efficient storage and retrieval of frequently accessed data.
* **Symbol Tables:** Compilers and interpreters use hash tables to store identifiers and their attributes.
* **Sets:** Implementing data structures like sets.

### Advantages of Hash Tables
* **Fast Access:** Average-case time complexity for lookup, insertion, and deletion is $O(1)$.
* **Simple Implementation:** Easier to implement than other associative data structures like trees.

### Disadvantages of Hash Tables
* **Worst-Case Performance:** If many collisions occur, performance can degrade to $O(n)$.
* **Memory Overhead:** Requires extra memory for hash codes and potential chaining.
* **Hash Function Dependency:** Poor hash functions can lead to more collisions.


## Strings as keys
To use strings as keys in a hash table with open addressing (like in your C++ code), you need to:

### 1. Convert Strings to Integers
You need a string hash function that maps a string to an integer index.

### 2. Example: Hash Function for Strings
A simple and commonly used hash function for strings in C++:

```cpp
int hashFunction(const std::string &key) const {
    unsigned long hash = 0;
    for (char ch : key) {
        hash = 31 * hash + ch; // Prime number multiplier (e.g., 31)
    }
    return hash % numBuckets;
}
```

### 3. Update Table to Store std::string Keys
Change the key type from int to std::string:

```cpp
std::vector<std::pair<std::string, std::string>> table;
std::vector<bool> isOccupied;
```

### 4. Updated Insert/Search/Remove
Now you're working with string keys, so functions like insert(key, value) and search(key) will use the string-based hash function and string comparisons.


## Maps
In C++, std::unordered_map is a container from the Standard Template Library (STL) that stores key-value pairs in an unordered manner. Unlike std::map, which maintains elements in a sorted order, std::unordered_map uses a hash table to achieve faster lookups.

### Key Features
* **Unordered Storage:** Elements are not stored in any specific order.
* **Fast Operations:** Lookup, insertion, and deletion have average-case time complexity of $O(1)$. However, in the worst case (hash collisions), the complexity can degrade to $O(n)$.
* **Unique Keys:** Each key must be unique. If you attempt to insert a duplicate key, it will overwrite the existing value.

### Syntax and Declaration
```cpp
#include <unordered_map>
std::unordered_map<KeyType, ValueType> mapName;
```
* **KeyType:** The type of the key.
* **ValueType:** The type of the value.

Example:
```cpp
std::unordered_map<std::string, int> myUnorderedMap;
```

### Inserting Elements
```cpp
std::unordered_map<std::string, int> myUnorderedMap;

// Using insert() with pair
myUnorderedMap.insert(std::make_pair("Apple", 10));

// Using the subscript operator
myUnorderedMap["Banana"] = 20;
myUnorderedMap["Cherry"] = 30;
```

### Accessing Elements
```cpp
std::cout << myUnorderedMap["Banana"];  // Output: 20
```
Note: Accessing a non-existent key with ```[]``` will insert it with a default value for the value type.

### Checking Existence
```cpp
if (myUnorderedMap.find("Apple") != myUnorderedMap.end()) {
    std::cout << "Apple exists!\n";
} else {
    std::cout << "Apple does not exist.\n";
}
```

### Iterating Through the Map
```cpp
for (const auto &pair : myUnorderedMap) {
    std::cout << pair.first << ": " << pair.second << "\n";
}
```

### Erasing Elements
```cpp
myUnorderedMap.erase("Banana");  // Removes the key "Banana"
```

### Size and Empty Check
```cpp
std::cout << "Size: " << myUnorderedMap.size() << "\n";
std::cout << "Is Empty: " << (myUnorderedMap.empty() ? "Yes" : "No") << "\n";
```

Example Code
```cpp
#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, int> myUnorderedMap;

    // Insert elements
    myUnorderedMap["Apple"] = 10;
    myUnorderedMap["Banana"] = 20;
    myUnorderedMap["Cherry"] = 30;

    // Access elements
    std::cout << "Value for Banana: " << myUnorderedMap["Banana"] << "\n";

    // Iterate over elements
    for (const auto &pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << "\n";
    }

    // Check existence
    if (myUnorderedMap.find("Apple") != myUnorderedMap.end()) {
        std::cout << "Apple is in the map.\n";
    } else {
        std::cout << "Apple is not in the map.\n";
    }

    // Erase an element
    myUnorderedMap.erase("Banana");
    std::cout << "Size after erase: " << myUnorderedMap.size() << "\n";

    return 0;
}
```

### Key Differences Between ```std::map``` and ```std::unordered_map```
| Feature              | std::map           | std::unordered_map   |
|----------------------|--------------------|----------------------|
| Ordering             | Sorted by key      | Unordered            |
| Implementation       | Balanced BST       | Hash Table           |
| Lookup Complexity    | $O(logn)$          | $O(1)$(average case) |
| Insertion Complexity | $O(logn)$          | $O(1)$(average case) |
| Key Requirements     | Requires operator< | Requires std::hash   |

### When to Use std::unordered_map
* **Fast Lookup:** Use when you need fast access and don't care about the order of elements.
* **Memory Usage:** It may use more memory than ```std::map``` because of the hash table.
* **Custom Hash Functions:** You can define a custom hash function for complex key types.


## Practice Examples
1. Use a map to solve the following problem: Given an integer array ```nums```, return true if any value appears more than once in the array, otherwise return false.
2. Based on the open addressing hash table example, implement a hash table using quadratic probing. Do the same for double hashing.
 
