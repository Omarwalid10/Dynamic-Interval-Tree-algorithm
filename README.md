## The Dynamic Interval Tree
* Write a C++ code that does the following:
* You are not allowed to use any built-in functions except: <cstdlib>, <cstdio>, <cstring>, <iostream>.
* You are not allowed to use string class, vector, or anything from STL libraries.
* Implement a dynamic interval tree data structure as described in our lecture. An interval is two integers.
* For simplicity, the underlying binary search tree structure must be your implementation of an unbalanced binary search tree.
* The dynamic interval tree must support InsertInterval(), DeleteInterval(), SearchInterval().
* SearchInterval() must return all intervals overlapping with the parameter interval, by first getting one overlapping interval, then deleting it, and so on. Then, all such intervals must be inserted again in the tree to restore its status.
* Other methods are NOT allowed.
* Use your implementation of everything.
* Use only standard C++.
* You are not allowed to include any files or built-in libraries, except for output.
* Write the main() in your submission after adding at least 30 test cases.
* Half the mark is dedicatd to comments explaining the code before each code line, test cases, and following the CodingStyle.pdf file.

