>1. Why does concat only need to work between two lists of the same representation? What would
    you have to do differently, or what would go wrong, if you tried to make it work between a
    LinkedList and an ArrayList?
* ArrayLists and LinkedLists are different data structures and have different mechanisms for adding and removing data points. 
* One stores T* values and uses indices, the other stores T* nodes and uses pointers. What would go wrong is that since ArrayList
* and LinkedList stores elements differently, dynamic_cast would reject the other list type. Therefore, during concatenation, 
* I have to have a different strategy to transfer elements from one to the other. In order to concatenate elements from one to 
* the other, I also have to combine both mechanisms I use for ArrayList and LinkedList. 
> 2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.
* The pointers I need are current, previous, and saved. Current tracks the node being reversed, and losing track of it would cause
* the program to also lose track of the next node that the program would process. Similarly, previous tracks the reversed nodes, and the
* linkedlist would link each node backwards; losing track of it would cause the program to lose the current node to link to the
* recently reversed nodes. The saved pointer stores the next node that's unvisited, and losing track of that pointer would cause the program to
* lose access to the rest of the linked list.
> 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?
* The valid range for the insertion is from 0 to size, while the valid range for delete is from 0 to size-1. The implementation checks the bounds, so if a 
* caller passes a position outside it, the program would detect an invalid position, which would print "Position out of range" and return.
> 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?
* Traversing to the end of the list first is necessary because the LinkedList runs without a tail pointer. addFront() and deleteFront() never needed to 
* because both operations work with head only. Concat would've used up more time to run, which would create the worst-case time complexity, O(n). If 
* LinkedList still tracked a tail pointer, the program can access the last node immediately without traversal. What I still need to update is that I 
* need to keep track of where the head and tail pointer points, so initially, head and tail has to point to the first node while adding to an empty list, and 
* both has to point to nullptr during deletion of the remaining node, and when reversing, the old head must become the new tail.
> 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.
* When adding any element in any position, all the other elements at or after the insertion position have to shift right. If they were to be processed in the 
* wrong direction, from left to right, the program would overwrite these existing elements by having the loop process the elements in that 
* direction before they're moved to different positions.
> 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missing?
* The exact line is table->reverse(). If that call were missing, then the order would not reverse, even when
* someone in the table plays a reverse card. 