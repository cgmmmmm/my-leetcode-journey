# What is a Tree Data Structure?
A **Tree** Data Structure is defined by hierarchy, instead of a linear data structure like Arrays, Stack, etc.
Hierarchical data structures consists of:
  1. Root: The topmost node with no parent.
  2. Leaf: A node with zero children.
  3. Height: The number of edges from the root to the deepest leaf.
  4. Depth: The number of edges from a node to the root.

<br>

# What is a Binary Tree?
A **Binary Tree** is a type of tree that consists of at most TWO(2) child nodes.
This means that a Binary Tree can consists of:
  1. *ZERO* child node (No Left AND no Right node)
  2. *ONE* child node (Has Left OR Right node only)
  3. *TWO* child nodes (Has both Left AND Right node)

A binary tree allows for efficient searching, sorting, and hierchical representation.
By restricting each node to having TWO children, we can implement specific data structures like Binary Search Trees (BSTs), when Balanced BSTs are implemented, lookup time can shrink from O(N) to O(log N), where N is the number of nodes.

<br>

---

## Recursive Approach
NOTE: Every recursion function consists of a base case.

***Inorder traversal*** is a **binary tree** traversal technique that uses (Left-Parent-Right) order, where the start of an inorder traversal is at the leftmost leaf of a sub-tree.
Inorder Traversal (fn: recurse_func) Steps:
  1. If [current node] is a NULLPTR, meaning that [current node] is the leftmost leaf of a sub-tree, go back up to [Parent] node. (base case)
  2. Go to [Left] node, and recursively call recurse_func(...){}.
  3. Process [Parent].
  4. Go to [Right] node, and recursively call recurse_func(...){}.

#### Pseudocode
```cpp
void inorderRecursion(current_node)
{
  // Step 1: Base case
  IF (current_node IS NULLPTR) { Go back to parent };

  // Step 2: Traverse left
  inorderRecursion(current_node->left);

  // Step 3: Process node
  process(current_node);

  // Step 4: Traverse right
  inorderRecursion(current_node->right);
}
```

The recursive call will end once ALL root node and nodes in root's sub-tree are processed.
