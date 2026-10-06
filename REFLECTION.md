> 1. In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
     Name exactly what each one frees, and name the two new calls back in the program responsible
     for putting them on the heap in the first place.
* In LinkedList::deleteFront(), it takes two separate delete calls rather than one because
every 'new' creates one heap allocation and there are two new calls: one in main.cpp
and the other in LinkedList.h in addFront(), that are responsible. The new in main.cpp creates the data in the node.
The second new in LinkedList.h creates the node. The delete statement "delete doomed->data" deletes the data 
inside the node, while "delete doomed" deletes the pointer Node<T>.
> 2. ArrayList never had a destructor before today. Explain, in your own words, why switching
   from T data[CAPACITY] to T* data_[CAPACITY] is what made a destructor necessary, and what
   would happen if you forgot to write one. Would you get a compiler error? Why or why not?
* T data[CAPACITY] stores the actual object, while T* data_[CAPACITY] creates a pointer for that object in heap memory.
That's why the destructor is necessary to delete the object. If I forgot the destructor, the program would still compile
without any compiler errors, but it's going to leak memory. For instance, if I deleted using T*, then the pointer would get deleted,
but the memory stays there.
> 3. search() and addFront() both take a T*, but they treat that pointer completely differently.
   Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
   and which one is never allowed to?
* Search never changes a value inside a linked list. It just reads a value and borrows the pointer; therefore, it has no ownership.
On the other hand, addFront() takes in the value and a memory pointer that I've handed, and therefore, it owns the value in the
LinkedList. Because of that, addFront() is allowed to delete the values that search is never allowed to.
> 4. You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
   changing a single line there. What two mechanisms, by name, made that possible?
* Abstraction and polymorphism are the two mechanisms. Abstraction made that possible because the implementation 
of the list is abstracted onto other files. Polymorphism made that possible too because this allows the "switching"
of list implementation methods.
> 5. Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
   thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
   your own words and without copying the guide’s wording, the smallest example you can think
   of where leaving it out would cause a real problem.
* Const -> this keyword forces the program to declare values are immutable, or not changeable. For example, the number
pi needs a const to lock in the value 3.14. If the const keyword weren't declared, then the program might
find other options for the pi value, and once it compiles, it might generate an invalid output and the program
will break.

>1. Why does concat only need to work between two lists of the same representation? What would
    you have to do differently, or what would go wrong, if you tried to make it work between a
    LinkedList and an ArrayList?
> 2. Walk through reverse() on your linked list: name the three pointers you need alive at once,
   and explain why losing track of any one of them mid-loop corrupts the list.
> 3. addAnywhere and deleteAnywhere both need a bounds check. What’s the valid range for
   position in each, and what does your implementation do if a caller passes a position outside
   it?
> 4. In LinkedList::concat, why did you need to walk to the end of the list first, when addFront
   and deleteFront never needed to? What would change about concat’s performance if
   LinkedList still tracked a tail pointer, and what would you have to keep updated elsewhere
   if you added one back?
> 5. Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what
   has to shift and in which direction, and why shifting in the wrong direction would overwrite
   data you still need.
> 6. Point to the exact line in your main.cpp where a Reverse card actually changes the direction of
   play, and explain what would visibly break in the game if that call were missin