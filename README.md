# KD-Tree

A C++ implementation of the KD-Tree (k-dimensional tree) data structure, commonly used for organizing points in a k-dimensional space. KD-Trees are widely used in applications such as nearest neighbor search, range queries, and spatial indexing.

## Features

- Build a KD-Tree from a set of points in k-dimensional space
- Efficient nearest neighbor search
- Range search queries
- Customizable for any number of dimensions

## Algorithm Control Flow

### 1. Building the KD-Tree

- **Input:** A list of points, each with k dimensions.
- **Process:**
  1. Start with the entire list of points.
  2. Select the axis based on the current tree depth (`axis = depth % k`).
  3. Sort points by the selected axis.
  4. Choose the median point as the root for the current subtree.
  5. Recursively build the left subtree with points before the median.
  6. Recursively build the right subtree with points after the median.
- **Output:** A balanced KD-Tree.

### 2. Nearest Neighbor Search

- **Input:** A target point and the KD-Tree.
- **Process:**
  1. Start at the root node.
  2. Compare the target point with the current node along the current axis.
  3. Recursively search the subtree that could contain the closest point.
  4. Update the best distance found so far.
  5. If the hypersphere crosses the splitting plane, search the other subtree.
  6. Continue until all relevant nodes are checked.
- **Output:** The nearest neighbor point and its distance.

### 3. Range Search

- **Input:** A query range and the KD-Tree.
- **Process:**
  1. Traverse the tree recursively.
  2. At each node, check if the point lies within the query range.
  3. If yes, add it to the result set.
  4. Decide which subtrees to search based on the range and splitting axis.
- **Output:** All points within the specified range.

## Usage

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/KD-Tree.git
   cd KD-Tree
   ```

2. **Compile the code:**

   ```bash
   g++ main.cpp -o kd_tree
   ```

3. **Run the program:**
   ```bash
   ./kd_tree
   ```

## Example

Suppose you have a set of 2D points and want to find the nearest neighbor to a query point. The KD-Tree efficiently organizes the points and performs the search in logarithmic time.

## File Structure

- `main.cpp` — Contains the KD-Tree implementation and example usage.
- `README.md` — Project documentation.

## References

- [Wikipedia: k-d tree](https://en.wikipedia.org/wiki/K-d_tree)
- [GeeksforGeeks: KD Tree](https://www.geeksforgeeks.org/k-dimensional-tree/)

## License

This project is licensed under the MIT License.

---

Feel free to customize the example and usage sections to match your actual code
