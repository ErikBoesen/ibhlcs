* Linked list: has a head element, and every element has a pointer to the location in memory where the next element is. Last element has pointer to null, thus we know we're done. Doubly linked list also has the previous item so you can walk the list backward. This differs from a conventional list/array, where each element is stored sequentially. Each item is an object.
    * Advantages: Can grow and shrink dynamically at runtime, limited only by the amount of physical memory available. Deletion/insertion is very fast.
    * Disadvantages: random access is slow because you must pass through each item, unlike in a conventional array where you can find an element in O(1) time given a pointer to the starting of the array.

* Binary trees
    * Middle number placed at root/in middle of sorted list
    * Right branch always has greater number than parent node, left always is lower
        * 57, 12, 19, 68, 45

      57
     /  \
   12    68
    \    | \       Ways to represent a binary tree:
    19   62 75     "Infix Notation" - put a dot underneath each number, start circling around it, and go through the dots.
   /\                               Add whatever number you pass through. Creates an ordered list.
  17  45           "Prefix Notation" - put dot to the left/before number instead. Creates a slightly different result; not ordered.
      |            "Postfix notation" - dot on right side of number. Basically reverse Polish notation because binary trees can represent equations.
     22            IB will ask us to make a tree and then write down in one of these notations.

* Compression
    * Lossy
        * Data changes after compression and the original copy can't be restored.
        * Used for audio and pictures.
    * Lossless
        * Data can be restored exactly in its entirety.
        * Examples:
            * Keyword encoding: replacing common words in text with irregular symbols.
            * Run-length encoding: useful if you have a lot of repeating characters. Assigning a number for each character that repeats a lot, and compressing those by saying, for example, *H6 rather than HHHHHH
            * Huffman coding: using shorter binary sequences to compress text.
                * Example: string with values ABCDEF. Frequency 5 25 7 15 4 12
                * You take the two smallest and put them into a binary tree. Then, you do the same again, and put the former binary tree under the new one. Then you put 0/1 on left/right branches and traverse that binary tree to figure out what the binary code for each letter should be; they will thus never overlap.
                * There can be "fixed-length" encoding as well. For example each letter could have a 6 bit identifier. You don't use a binary tree for this, allegedly.
                * Practice doing this manually!
