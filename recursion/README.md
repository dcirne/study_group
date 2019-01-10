# Algorithms: Recursion

<img width="380" alt="recursion_activity_diagram" src="https://user-images.githubusercontent.com/204792/51038547-84884b80-1581-11e9-9c10-1b715e2442c8.png">

## Cases

We are taking a look at three cases where recursion can be applied.

### 1. Fibonacci

Given a term, what is the corresponding [Fibonacci number](https://en.wikipedia.org/wiki/Fibonacci_number)? The implementation was done with [functors](https://www.cprogramming.com/tutorial/functors-function-objects-in-c++.html), rather than a plain function. The purpose is to refresh our memories, not to add complexity.

### 2. Iteration via recursion

How about iterating using recursion? What use cases can is it applicable?

Asynchronous network communication. When uploading several packages, in a collection, advancing to the next package only occurs if the response to a given request returns successfully. Otherwise, the same package is tried again.

It is common to see, in literature, the comparison between Recursion vs Iteration. Little is spoken about iteration via recusrion.

### 3. Tower of Hanoi

_In the great temple at Benares4, beneath the dome which marks the centre of the world, rests a brass plate in which are fixed three diamond needles, each a cubit high and as thick as the body of a bee. On one of these needles, at the creation, God placed sixty-four discs of pure gold, the largest disc resting on the brass plate, and the others getting smaller and smaller up to the top one. This is the [Tower of Bramah](https://en.wikipedia.org/wiki/Tower_of_Hanoi). Day and night unceasingly the priests transfer the discs from one diamond needle to another according to the fixed and immutable laws of Bramah, which require that the priest on duty must not move more than one disc at a time and that he must place this disc on a needle so that there is no smaller disc below it. When the sixty-four discs shall have been thus transferred from the needle on which at the creation God placed them to one of the other needles, tower, temple, and Brahmins alike will crumble into dust, and with a thunderclap the world will vanish._

The algorithm uses recursion to move the discs from one needle/peg to another, according to the rules established above.

## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/recursion
```

```bash
./bin/recursion [Fibonacci term] [number of discs]
```

## References

[J. Erickson, _Algorithms_](http://jeffe.cs.illinois.edu/teaching/algorithms/)
