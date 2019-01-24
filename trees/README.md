# Algorithms and Data Structures: Trees

**Binary tree**

<img width="800" alt="binary_tree" src="https://user-images.githubusercontent.com/204792/51714276-b75f2480-2002-11e9-9c8b-e016b24366c0.JPG">

**Traverse a tree depth first**

<img width="800" alt="depth_first" src="https://user-images.githubusercontent.com/204792/51714277-b75f2480-2002-11e9-85d4-adc86b653ba0.JPG">

**Traverse a tree breadth first**

<img width="800" alt="breadth_first" src="https://user-images.githubusercontent.com/204792/51714278-b75f2480-2002-11e9-83b1-61a7f66bc78d.JPG">

We are taking a look at trees as a data structure and algorithms to traverse them, measure the height of a node, and compute its size.

## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/trees
```

```bash
./bin/trees [avengers]
```

## References

[P. Morin, _Open Data Structures_](http://opendatastructures.org)
