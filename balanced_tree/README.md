# Balanced Trees or Binary Search Trees

Binary search trees are used, among other things, to implement `std::map` and `std::set`. It is also an efficient way of maintaning records of data without requiring much space.

## A definition of balanced

A working definition of balanced tree is: _"The heights of the two child subtrees of any node differ by at most one."_

### Balanced tree with odd numbers

<img width="177" alt="BBT-odds" src="https://user-images.githubusercontent.com/204792/56400874-27590180-6224-11e9-9fcd-abefe1e52f22.png">

### Balanced tree with even and odd numbers

<img width="272" alt="BBT-numbers" src="https://user-images.githubusercontent.com/204792/56400873-27590180-6224-11e9-9522-60f10ed43abe.png">


## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/bst
```

```bash
./bin/bst
```


## References

[Data Structure Visualizations - Balanced binary search trees](https://www.cs.usfca.edu/~galles/visualization/AVLtree.html)

[Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree)
