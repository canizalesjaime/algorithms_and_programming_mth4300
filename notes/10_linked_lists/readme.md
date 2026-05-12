# Lecture notes

## table of contents
1. Linked Lists
2. Practice Examples


## Linked Lists
A **linked list** is a linear data structure where elements, called nodes, are stored in sequence, but unlike arrays, they are not stored in contiguous memory locations. Each node contains two parts:

* **Data:** The actual value the node holds.
* **Pointer (next):** A pointer/reference to the next node in the sequence.

The main advantage of linked lists over arrays is that they can grow and shrink dynamically, without needing to know their size in advance. However, they don't allow random access to elements, meaning you must traverse the list from the head to access a specific element.

### Basic Structure of a Node
In a **singly linked list**, each node points to the next node, and the last node points to ```nullptr``` (signifying the end of the list). Here's how a node is typically represented:

```cpp
struct Node {
    int data;        // Data part of the node
    Node* next;      // Pointer to the next node
};
```


### Key Linked List Operations
* **Insertion:**
  * To insert a new node, we can add it to the head (beginning), tail (end), or any position in between.
  * In our example, we added nodes at the end (tail insertion).

* **Traversal:**
  * Since linked lists don't provide random access (like arrays), we have to start from the ```head``` and follow the ```next``` pointers until we reach the desired node or the end of the list.

* **Deletion:**
  * Deleting a node involves adjusting the ```next``` pointer of the previous node to point to the node after the one being deleted, and then freeing the memory of the deleted node.

* **Search:**
  * To search for a node, we traverse the list from the ```head```, checking each node's data.


## Search and traversal
### 🧩 What “search by position” means

If you have a linked list like:

```
Head → [10] → [20] → [30] → [40] → nullptr
```

Each node has a **position** (or index), typically starting at **0** (or 1, depending on convention):

| Position | Value |
|-----------|--------|
| 0 | 10 |
| 1 | 20 |
| 2 | 30 |
| 3 | 40 |

Searching **by position** means:  
> Find the node *at* a given position — for example, “give me the 2nd element”.

---

## 2. How it works conceptually

Unlike arrays, a linked list does **not** support direct indexing (`list[2]` won’t work).  
So, to find the node at a specific position, you must **traverse** from the head and count as you go.

### Steps:

1. Start at the **head** node.  
2. Keep a **counter** (starting at 0).  
3. Move through the list one node at a time (`current = current->next`),  
   increasing the counter each time.  
4. When the counter equals the target position → you’ve found your node.  
5. If you reach the end (`nullptr`) before the counter matches → position is out of range.

---

## 3. Visual example

Find the node at **position 2**:

```
Head → [10] → [20] → [30] → [40] → nullptr
          0       1       2
```

Steps:
- Start: current = 10 (pos 0)
- Move: current = 20 (pos 1)
- Move: current = 30 (pos 2) → found!

---


### 4. Time complexity

You might need to traverse up to *n* nodes in the worst case →  
 **O(n)** time complexity.




## Inserting a node at a specific position
So you can visualize it like this:

```
[10 | ●] → [20 | ●] → [30 | ●] → [40 | /]
```

Each arrow (●) represents the “next” pointer to the following node.  
The first node is the **head**, and the last one points to **nullptr** (or null), marking the end.

---


Let’s say we want to insert a new node at position `pos`.

### Conceptually, this means:
We want the new node to appear *between* two existing nodes.

For example, if we have:
```
head → A → B → C → D
```
and we insert a new node `X` at position 2 (0-based), the result should be:
```
head → A → B → X → C → D
```

### So what has to happen?

1. **Find the place to insert.**
   - You walk through the list one node at a time until you reach the node that comes *just before* the position you want.
   - In this example, we stop at node `B` (position 1).

2. **Create the new node.**
   - It will store its data and will eventually point to the next node (`C` in our example).

3. **Adjust the links.**
   - The new node should point to what used to be `B`’s next node (`C`).
   - Then `B`’s “next” pointer must be changed to point to the new node.

So the pointer updates look like this:

```
Before:
   B → C
After:
   B → X → C
```

Everything else stays the same.

### Special case — inserting at the head
If you insert at position 0:
- The new node should point to the *current head*.
- Then it becomes the new head.

Visually:
```
Before:  head → A → B → C
After:   head → X → A → B → C
```

---

## Erasing (deleting) a node at a specific position

Now imagine we want to remove a node at position `pos`.

Let’s say we have:
```
head → A → B → C → D
```
and we want to **erase** the node at position 2 (`C`).

### Conceptually, this means:
We want to remove `C` from the chain, so that the list becomes:
```
head → A → B → D
```

### Steps that must happen:

1. **Find the node *before* the one to delete.**
   - Again, we walk through until we reach the node that links to the one we want to remove.
   - In this case, that’s `B`.

2. **Change its “next” pointer.**
   - `B` currently points to `C`.  
     We want it to skip `C` and point to `C`’s next node (`D`).

   ```
   Before: B → C → D
   After:  B → D
   ```

3. **Dispose of the removed node.**
   - Once we’ve adjusted the links, `C` is no longer part of the list.
   - We can delete it (in memory-managed terms, we release that node).

### Special case — deleting the head
If you erase position 0:
- The head simply moves to point to the next node.
  
  ```
  Before: head → A → B → C
  After:  head → B → C
  ```

---

## The key idea

Both insertion and deletion are about **link manipulation**:
- In insertion, you **add** a node and **reconnect pointers** so it fits in.
- In deletion, you **remove** a node and **reconnect pointers** so the chain stays unbroken.

You always need to keep track of the **node before** the point of change — because that’s the one whose link must be updated.

---

## Time complexity (conceptually)

Since linked lists don’t have random access (you can’t jump directly to position `pos`), you must **walk** through nodes one by one to find the right spot.

So:
- Finding the right position takes **O(pos)** steps.
- Updating the pointers takes **O(1)** (just a couple of link changes).

Total = **O(n)** in general (because of the traversal).


### Types of Linked Lists
* **Singly Linked List:** Each node points to the next node, and the last node points to ```nullptr```.
* **Doubly Linked List:** Each node has two pointers: one pointing to the next node and another pointing to the previous node. This allows traversal in both directions.
* **Circular Linked List:** The last node points back to the ```head```, forming a circle. This can be either singly or doubly linked.


### Example of a Doubly Linked List Node
```cpp
struct Node {
    int data;
    Node* next;  // Pointer to the next node
    Node* prev;  // Pointer to the previous node
};
```


#### Advantages of Linked Lists
* **Dynamic Size:** Linked lists can grow or shrink as needed, unlike arrays which require a fixed size.
* **Efficient Insertion/Deletion:** Inserting or deleting elements at the beginning or middle of the list is more efficient than arrays, as there’s no need to shift elements.

#### Disadvantages of Linked Lists
* **No Random Access:** Accessing elements requires linear traversal, unlike arrays where you can access any element in constant time.
* **Extra Memory:** Each node requires additional memory for the pointer(s), which can lead to increased memory usage compared to arrays.


### Conclusion
Linked lists are a fundamental data structure in computer science, used when dynamic size and efficient insertion/deletion are needed. The singly linked list is the simplest form, while more complex types like doubly and circular linked lists provide additional flexibility in traversal and manipulation.


## Practice Examples
1. Modify deletion to delete by value instead of position. 
2. Write a method that reverse the order of the linked list. Example: l1= 5->3->7->1 then the output should be l1_r= 1->7->3->5
3. rewrite the search method using recursion
4. Implement a queue class, using the linked list data structure
5. Use stl list and solve the problem from last time for reversing a linked list. What is the time complexity (big O notation) for reversed linked list with stl and without?

  