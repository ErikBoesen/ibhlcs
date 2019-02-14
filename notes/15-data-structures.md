* Linked list: has a head element, and every element has a pointer to the location in memory where the next element is. Last element has pointer to null, thus we know we're done. Doubly linked list also has the previous item so you can walk the list backward. This differs from a conventional list/array, where each element is stored sequentially. Each item is an object.
    * Advantages: Can grow and shrink dynamically at runtime, limited only by the amount of physical memory available. Deletion/insertion is very fast.
    * Disadvantages: random access is slow because you must pass through each item, unlike in a conventional array where you can find an element in O(1) time given a pointer to the starting of the array.

* Compression
    * Lossless
        * Data can be restored exactly in its entirety.
        * Examples:
            * Keyword encoding: replacing common words in text with irregular symbols.
            * Run-length encoding: useful if you have a lot of repeating characters. Assigning a number for each character that repeats a lot, and compressing those by saying, for example, *H6 rather than HHHHHH
            * Huffman coding: using shorter binary sequences to compress text.
    * Lossy
        * Data changes after compression and the original copy can't be restored.
        * Used for audio and pictures.

* Binary trees
    * Middle number placed at root/in middle of sorted list
    * Right branch always has greater number than parent node, left always is lower
