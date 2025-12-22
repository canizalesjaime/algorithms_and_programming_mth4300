# Lecture notes

## table of contents
1. Binary Search Trees
2. Breadth First Search
2. Practice Examples


## Binary Search Trees
BSTs (Binary Search Trees) are great data structures because they combine efficient data organization with fast search, insert, and delete operations—especially when the tree is balanced.

Here’s a breakdown of why BSTs are good:

### Fast Lookup, Insertion, and Deletion
* Time Complexity: O(log n)

#### Why?
Because each comparison eliminates half of the remaining tree, like binary search.
(This only holds if the tree is reasonably balanced.)

### Ordered Structure
* All nodes follow the rule:
    * Left subtree < current node < Right subtree

* This structure naturally keeps elements sorted, which is super useful for:
  * In-order traversal (gets elements in sorted order)
  * Range queries (e.g., “find all elements between 10 and 50”)
  * Finding min/max, floor/ceiling, successor/predecessor efficiently

A Binary Search Tree (BST) is a data structure that organizes elements (or nodes) in a hierarchical manner, making it efficient for operations like searching, insertion, and deletion. Here's a breakdown of how BSTs work in C++ and their basic concepts.

### Properties of a Binary Search Tree
* Each node has a key (or value).
* The left child of a node contains keys that are less than the node's key.
* The right child of a node contains keys that are greater than the node's key.
* No duplicate keys (optional, but common in BSTs).


### Insertion:
The insertion operation places a new node at the correct position in the tree. Here's an example of inserting a node into a binary search tree (BST), where the left child contains a smaller value and the right child contains a larger value.
Inserting a node into a Binary Search Tree (BST) involves placing a new value in the correct position according to the BST property:

* **Left subtree:** Nodes must have values smaller than the parent.
* **Right subtree:** Nodes must have values greater than the parent.


**Steps to Insert a Node**<br>
1. Start from the Root
   * Begin at the root of the tree.

2. Traverse to the Correct Position
   * If the new value is smaller than the current node, move to the left subtree.
   * If the new value is greater, move to the right subtree.
   * Repeat this process until a nullptr (empty spot) is reached.

3. Insert the Node
* Create a new node and attach it as a child where the nullptr was found.


```cpp
// Function to insert a new node in the binary search tree (BST)
Node* BinarySearchTree::insert(Node* start, int val)
{
     if (!root) 
    {
        root= new Node(val);
        return root;
    }

    if (!start) return new Node(val);  // found position to insert

    else if (val < start->data) start->left = insert(start->left, val);  

    else if (val > start->data) start->right = insert(start->right, val); 
    
    return start;
}
```


**Explanation of Code**<br>
1. Base Case
   * If the root is nullptr, create a new node with the given key, set root equal to it then return root. This handles the case where the tree is empty.
   * If ```start``` is the nullptr, create a new node with the given key and return it. This handles the case where a child needs to be added to a leaf.

2. Recursive Insertion
   * Depending on whether the key is smaller or larger than the current node's value, recursively call insertNode on the left or right subtree.

3. Update the Subtree
   * After inserting the new node, the parent's left or right pointer is updated with the result of the recursive call.

4. Return start
   * The function always returns the root of the current subtree to ensure proper linking of the tree.

#### Example Walkthrough
Insertions:
* Start with an empty tree: root = nullptr.
* Insert 5<
* Tree is empty, so 5 becomes the root.
```markdown
    5
```

* Insert 3
* 3 < 5, so insert 3 into the left subtree.
```markdown
    5
   /
  3
```

* Insert 8
* 8 > 5, so insert 8 into the right subtree.
```markdown
    5
   / \
  3   8
```

* Insert 2
* 2 < 5 (go left) and 2 < 3 (go left again), so insert 2 as the left child of 3.
```markdown

    5
   / \
  3   8
 /
2
```

* Insert 4
* 4 < 5 (go left) and 4 > 3 (go right), so insert 4 as the right child of 3.
```markdown
    5
   / \
  3   8
 / \
2   4
```
In-order Traversal After Inserts
The in-order traversal of a BST visits nodes in sorted order. For the example above, the output would be:
```
2 3 4 5 8
```
This confirms that the BST property is maintained after insertions.


### Search
Searching involves finding whether a specific value exists in the tree.

```cpp
// Function to search for a value in a BST
Node* BinarySearchTree::search(int val)
{
    Node* curr=root;
    while (curr)
    {
        if(val < curr->data) curr=curr->left;

        else if (val > curr->data) curr=curr->right;

        else return curr; // val==curr->data, so we found node
    }

    return nullptr;
}
```


### Deletion 
Below is an example of how to implement the deleteNode function in C++:

```cpp
// Function to delete a node by value
Node* BinarySearchTree::deleteNode(Node* start, int val)
{
    if(!start) return nullptr;

    else if(val < start->data) start->left=deleteNode(start->left,val);

    else if(val > start->data) start->right=deleteNode(start->right,val); 
    
    else
    {
        if(start->left && start->right)//two children
        {
            Node* min_node = findMin( start->right );
            start->data = min_node->data;
            start->right = deleteNode( start->right, start->data );
        }


       else //at most one children
       {
            Node* save_spot=start->left?start->left:start->right;
            delete start;
            return save_spot;
       } 

    }

    return start;
}
```


#### Explanation of Code
1. Base Case
   * If start is nullptr, the function returns nullptr, indicating the value doesn't exist in the tree.

2. Recursive Search
   * Depending on the comparison, traverse left or right(just like we did for insert).

3. Deletion Cases
   * Leaf nodes are simply deleted.
   * For nodes with one child, the child replaces the node.
   * For nodes with two children, the value of the node is replaced by its inorder successor, and the successor node is deleted recursively(the smallest node in the right subtree of the node to be deleted).

4. Inorder Traversal
   * Used to verify the tree structure remains valid after deletion.

#### Example Walkthrough
1. Input Tree:
```markdown
        5
       / \
      3   8
     / \
    2   4
```

2. Delete 3:
   * Node 3 has two children.
   * Replace 3 with its inorder successor (4).
   * Delete 4 from the right subtree.

3. Output Tree:
```markdown
        5
       / \
      4   8
     /
    2
```
This approach ensures the BST property is maintained throughout the operation.


#### Example Usage:
```cpp
int main() {
    Node* root = nullptr;

    // Insert nodes into the binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    // Display the in-order traversal
    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    // Search for a value in the tree
    int key = 40;
    if (search(root, key)) {
        cout << "Value " << key << " found in the tree." << endl;
    } else {
        cout << "Value " << key << " not found in the tree." << endl;
    }

    return 0;
}
```

### Complexity:
* Time Complexity:
  * Insertion, Deletion, Search: O(log n) for balanced trees (O(n) in the worst case for unbalanced trees).
* Space Complexity:
  * O(n), where n is the number of nodes in the tree.



## Breadth First Search on Binary Search Trees
Breadth-First Search (BFS) for a binary tree is a traversal method where nodes are visited level by level, starting from the root and proceeding to the next level. This approach is also known as level-order traversal. Here's an explanation of how BFS works for a binary tree:

### Steps to Perform BFS
1. **Start at the Root:** Begin with the root node of the binary tree.
2. **Use a Queue:** Use a queue data structure to keep track of nodes to visit. A queue ensures that nodes are visited in the order they are added (FIFO: First In, First Out).
3. **Visit Nodes Level by Level:**
   * Dequeue the node at the front of the queue.
   * Process the node (e.g., print its value).
   * Enqueue the left child of the node (if it exists).
   * Enqueue the right child of the node (if it exists).
4. **Repeat:** Continue this process until the queue is empty.

### Example
#### Given Binary Tree:
```markdown
       1
      / \
     2   3
    / \   \
   4   5   6
```

#### BFS Traversal:
1. Start with the root: ```1```.
2. Enqueue ```1```. Queue: ```[1]```.
3. Dequeue ```1```, process it, and enqueue its children (```2``` and ```3```). Queue: ```[2, 3]```.
4. Dequeue ```2```, process it, and enqueue its children (```4``` and ```5```). Queue: ```[3, 4, 5]```.
5. Dequeue ```3```, process it, and enqueue its right child (```6```). Queue: ```[4, 5, 6]```.
6. Dequeue ```4```, process it (no children to enqueue). Queue: ```[5, 6]```.
7. Dequeue ```5```, process it (no children to enqueue). Queue: ```[6]```.
8. Dequeue ```6```, process it (no children to enqueue). Queue: ```[]```.
**Result:** The BFS traversal is: ```1, 2, 3, 4, 5, 6```.

#### c++ code:
```c++
void BFS(BinarySearchTree& t)
{
    std::queue<Node*> q;

    if(t.getRoot())
    {
        std::cout<<t.getRoot()->data<<std::endl;
        q.push(t.getRoot());
    }
    
    int nodes_per_level = 1;
    while(!q.empty())
    {
        for(int i=0;i<nodes_per_level;i++)
        {
            Node* n = q.front();
            q.pop();
            if(n->left)
            {
                std::cout <<" -> "<< n->left->data;
                q.push(n->left);
            }
            if(n->right)
            {
                std::cout <<" -> "<< n->right->data;
                q.push(n->right);
            }
        }
        std::cout<<std::endl;
        nodes_per_level=q.size();
    }
}
```

### Key Points
* BFS is suitable for exploring all nodes level by level.
* It uses a queue to maintain the order of exploration.
* BFS is different from Depth-First Search (DFS)(used in pre-order,post-order, and in-order), which explores as far as possible along each branch before backtracking.


## Conclusion:
Binary trees are a powerful data structure that can be used for efficient searching, sorting, and hierarchical data organization. Implementing binary trees in C++ is straightforward with the use of pointers and recursive functions for operations like insertion, traversal, and search.

## Practice Examples
  1. Determine the lowest common ancestor of two given values in a tree. You can assume both values are present in the tree. The lowest common ancestor is the deepest node that has both values as descendants.