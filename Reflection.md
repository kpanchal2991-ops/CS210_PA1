Reflection

1. Why does concat only need to work between two lists of the same representation?

Concat only works with the same type because ArrayList and LinkedList store data differently. ArrayList uses an array, while LinkedList uses nodes. The dynamic_cast checks that both lists are the same type before transferring the pointers. If they were different types, the program would have to copy the data instead.

2. Walk through reverse() on your linked list.

The three pointers are previous, current, and next. Current is the node being changed, previous is the node before it, and next saves the rest of the list. If I lose next, I could lose the rest of the list. If I lose previous or current, I cannot correctly reconnect the nodes.

3. What are the valid ranges for addAnywhere and deleteAnywhere?

For addAnywhere, the position can be from 0 to size. Adding at size puts the item at the end. For deleteAnywhere, the position can be from 0 to size - 1. Invalid positions print an error message and do nothing.

4. Why does LinkedList::concat need to walk to the end?

The linked list does not have a tail pointer, so it has to walk from the head to find the last node. Then it connects that node to the other list. A tail pointer would make concat faster, but it would need to be updated whenever the list changes.

5. Explain shifting in ArrayList.

When adding in the middle, the items after that position move one space to the right. I move them from the back to avoid overwriting the original values. Moving from the front could overwrite values before they are moved.

6. Where does the Reverse card change the direction of play?

The direction changes on this line:

table->reverse();

The list is printed before and after this line to show the players changing order. Without it, the players would stay in the same order.