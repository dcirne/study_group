# Knapsack problem

The knapsack problem is a maximization problem where we can use Dynamic Programming to find the solution.

Given a set of Weights, Values, and knapsack Capacity, find which combination of items, fitting in the knapsack, would yield the highest value.

A matrix _M_, of size (`number of items` + 1, `capacity` + 1), is needed to store the results of the computations. Elements are initialized to 0, then cell values are computed according to the formula:

<a href="https://www.codecogs.com/eqnedit.php?latex=M_{i,&space;j}&space;=&space;max\left((W_{(i-1)}&space;\leq&space;j)&space;\times&space;(&space;V_{(i-1)}&space;&plus;&space;M_{(i-1),&space;(j&space;-&space;W_{(i-1)})}&space;),&space;M_{(i&space;-&space;1),&space;j}\right)" target="_blank"><img src="https://latex.codecogs.com/gif.latex?M_{i,&space;j}&space;=&space;max\left((W_{(i-1)}&space;\leq&space;j)&space;\times&space;(&space;V_{(i-1)}&space;&plus;&space;M_{(i-1),&space;(j&space;-&space;W_{(i-1)})}&space;),&space;M_{(i&space;-&space;1),&space;j}\right)" title="M_{i, j} = max\left((W_{(i-1)} \leq j) \times ( V_{(i-1)} + M_{(i-1), (j - W_{(i-1)})} ), M_{(i - 1), j}\right)" /></a>

Where:

<a href="https://www.codecogs.com/eqnedit.php?latex=M:&space;\text{Matrix&space;structure&space;to&space;store&space;the&space;algorithm&space;results}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?M:&space;\text{Matrix&space;structure&space;to&space;store&space;the&space;algorithm&space;results}" title="M: \text{Matrix structure to store the algorithm results}" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=W:&space;\text{Weights}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?W:&space;\text{Weights}" title="W: \text{Weights}" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=V:&space;\text{Values}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?V:&space;\text{Values}" title="V: \text{Values}" /></a>

After the value of each cell has been computed, we have the maximum value by accessing the cell at (`last row`, `last column`) of the matrix.

<a href="https://www.codecogs.com/eqnedit.php?latex=MaxVal&space;=&space;M_{(\text{last&space;row}),&space;\text{(last&space;column)}}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?MaxVal&space;=&space;M_{(\text{last&space;row}),&space;\text{(last&space;column)}}" title="MaxVal = M_{(\text{last row}), \text{(last column)}}" /></a>

Last, in order to obtain which items sould go in the knapsack (positional relative to the Weights and Values arrays), we traverse the matrix in reverse order, adding the elements whose cell values are different from the cell value of the previous item with the same capacity and not zero, and decrementing the indexes as per the formulas below: 

<a href="https://www.codecogs.com/eqnedit.php?latex=\\&space;M_{i,&space;j}&space;\neq&space;M_{(i-1),&space;j}&space;\\&space;i&space;=&space;i&space;-&space;1&space;\\&space;j&space;=&space;j&space;-&space;W_{i}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\\&space;M_{i,&space;j}&space;\neq&space;M_{(i-1),&space;j}&space;\\&space;i&space;=&space;i&space;-&space;1&space;\\&space;j&space;=&space;j&space;-&space;W_{i}" title="\\ M_{i, j} \neq M_{(i-1), j} \\ i = i - 1 \\ j = j - W_{i}" /></a>


## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/knapsack
```

```bash
./bin/knapsack 
```


## References

[J. Erickson, _Algorithms_](http://jeffe.cs.illinois.edu/teaching/algorithms/)
