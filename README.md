# Binary Search Tree (BST) Implementation in C++

This repository contains a C++ implementation of a Binary Search Tree (BST). The code demonstrates how to create, insert, remove, and traverse nodes in a BST. The project is a great resource for understanding basic tree data structures and their operations.

## Overview

The Binary Search Tree (BST) is a tree data structure where each node has at most two children. For any node, all values in the left subtree are less than the node's value, and all values in the right subtree are greater.

## Features

- **Insertion**: Adds nodes to the BST while maintaining its properties.
- **Removal**: Deletes nodes from the BST and adjusts the tree to preserve its properties.
- **Inorder Traversal**: Traverses the tree in-order (left subtree, root, right subtree) and prints node values.
- **Finding Minimum**: Retrieves the minimum value node in the BST.

## Code Explanation

### Node Structure

Each node in the BST has:
- `key`: The value stored in the node.
- `left`: Pointer to the left child node.
- `right`: Pointer to the right child node.

### Insert Function

The `insert` function adds a new node to the BST. It recursively finds the correct position for the new node based on its value.

```cpp
Node *insert(Node *root, int key) {
    if (!root) {
        return new Node(key);
    }
    else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    else if (key < root->key) {
        root->left = insert(root->left, key);
    }
    return root;
}
```

### Remove Function

The `remove` function deletes a node with a given key. It handles three cases:
1. **Node with no children**: Simply deletes the node.
2. **Node with one child**: Replaces the node with its child.
3. **Node with two children**: Finds the inorder successor (minimum value node in the right subtree), replaces the node's key with the successor's key, and then removes the successor.

```cpp
Node *remove(Node *root, int key) {
    // Handling removal cases...
}
```

### Inorder Traversal

The `inorder` function performs an in-order traversal of the BST, printing node values in ascending order.

```cpp
void inorder(Node *root) {
    if (!root) {
        return;
    }
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}
```

## Usage

1. **Compile the Code**: Use a C++ compiler to compile the code.
   ```bash
   g++ -o bst bst.cpp
   ```
2. **Run the Program**: Execute the compiled binary.
   ```bash
   ./bst
   ```

## Example

Before removing a node:
```
Tree Before Removing 34 is: 2 4 23 34 42824
```

After removing node `34`:
```
Tree after removing 34 is: 2 4 23 42824
```

## Diagrams

Here are some diagrams to help visualize the BST operations:

### Initial Tree

```
       4
        \
        34
         \
        42824
        /
       23
```

### Tree After Insertion

```
       4
        \
        34
         \
        42824
        /
       23
```

### Tree After Removal of 34

```
       4
        \
        42824
        /
       23
```

## Contributing

Feel free to fork the repository and submit pull requests with improvements or additional features!

## License

This project is licensed under the MIT License.

## Contact

If you have any questions or suggestions, please contact me on [LinkedIn](https://www.linkedin.com/in/shivam-chaturvedi-77629321a).
