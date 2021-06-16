# Final-Project-Depth-First-Search
* Depth First Search, also known as DFS, is a common and useful searching algorithm, which is appied to traversal all the verteices of an entire graph.
* The depth is defined by their number of steps.
  * For example, if there're nodes 1->2->3, then the depth of each node are 0, 1 and 2 respectively.
  * I did not record the depth in my work.
* When a node is reached, we add it to the stack.
  * From top to bottom are 3, 2 and 1 in the above example.
  * When a node is put into stack, we record it as visited.
  * Suppose the node 3 is connected to 4 and 5. The route may be 1->2->3->4->3->5. 
  * The stack works like 1 + 2 + 3 + 4 - 4 + 5.
  * Thus the order is 1,2,3,4,5.


* Here are the implementing steps:
  * Create a graph with 2D array
  * Create an array to record whether nodes are visited.
  * create a stack, whose first-in-last-out attribute will be used.
  * Implement DFS function
