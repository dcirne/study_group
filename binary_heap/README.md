# Binary Heap

A binary heap can be used as a priority queue. This implementation is based on the Eytzinger’s method, which stores a binary tree in an array. The root is stored at position 0, the root’s left child is stored at position 1, the root’s right child at position 2, the left child of the left child of the root is stored at position 3, and so on.

The general formulas to get the index of an item's (node) left child, right child, or parent are given by:

**Left child index**

&nbsp;&nbsp;&nbsp;&nbsp;<img width="100" alt="Left index" src="https://user-images.githubusercontent.com/204792/56046583-8e048980-5d11-11e9-8d14-7209873ce36c.png">

**Right child index**

&nbsp;&nbsp;&nbsp;&nbsp;<img width="100" alt="Right index" src="https://user-images.githubusercontent.com/204792/56046582-8e048980-5d11-11e9-98c4-7635a2f44821.png">

**Parent index**

&nbsp;&nbsp;&nbsp;&nbsp;<img width="100" alt="Parent index" src="https://user-images.githubusercontent.com/204792/56046581-8e048980-5d11-11e9-90f9-10d6846ac362.png">


### Representing a binary tree as an array

<img width="600" alt="Eytzinger’s method" src="https://user-images.githubusercontent.com/204792/56004878-8efad400-5c9b-11e9-9417-7d255e37967e.png">

### Adding an item

<img width="600" alt="Adding an item" src="https://user-images.githubusercontent.com/204792/56005010-527ba800-5c9c-11e9-9a18-a1145450b7bd.png">

### Removing an item

<img width="600" alt="Removing an item" src="https://user-images.githubusercontent.com/204792/56005011-527ba800-5c9c-11e9-8196-215f216a3538.png">


## The Twelve Labors of Hercules

In Greek mythology the divine hero Heracles (later romanisized as Hercules) was tasked to a penance of 12 tasks, known as [The Twelve Labors of Hercules](https://en.wikipedia.org/wiki/Labours_of_Hercules). Had he been educated in algorithms and data structures, he could have prioritized those tasks and executed them in order of priority.


## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/binary_heap
```

```bash
./bin/binary_heap
```


## References

[P. Morin, _Open Data Structures_](http://opendatastructures.org)
