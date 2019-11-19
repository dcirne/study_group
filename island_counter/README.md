# Proposed problem: Count the number of islands

Given a two dimensional grid with each cell representing either water or land. Count the number of islands in the grid (contiguous piece of land).

The grid below represents an example:

```
WWWLLW
WWWWLW
WWWLLW
WWWWWW
LLLWWW
```

The expected result is for the program to find 2 islands: the cluster on the upper-right, and the cluster on the lower-left.

In the implemented solution (`IslandCounter.hpp`), the algorithm keeps track of the cells already visited, and uses recursion to visit the next contiguous piece of land (if it exists and is within the boundaries of the grid), from the coordinates of the current cell.

## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/island_counter
```

```bash
./bin/island_counter
```
