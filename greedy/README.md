# Greedy Algorithms

_"The point is, ladies and gentleman, greed is good."_ <br />
&nbsp;&nbsp;&nbsp;&nbsp;– Gordon Gekko, [Wall Street (1987)](https://www.imdb.com/title/tt0094291/?ref_=nv_sr_2)

Greedy algorithms are a problem solving approach where the algorithm choses a local optimal choice at each step, with the intent of finding the global optimal solution. A greedy algorithm does not always produce _the_ best optimal solution, but it at least approximates to it within a reasonable amount of time.

**Assorted distrubution of tasks**

<img width="1024" alt="gantt" src="https://user-images.githubusercontent.com/204792/52724429-4f568b00-2f7d-11e9-98ca-073f2e60d24c.jpg">


**Tasks sorted by end point**

<img width="600" alt="sorted gantt" src="https://user-images.githubusercontent.com/204792/52724436-52ea1200-2f7d-11e9-8fe5-5a61520ff2d8.png">


## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/greedy
```

```bash
./bin/greedy [ 1 | 2 | 3 | 4 ]
```


## References

[J. Erickson, _Algorithms_](http://jeffe.cs.illinois.edu/teaching/algorithms/)

[Greedy Algorithm](https://en.wikipedia.org/wiki/Greedy_algorithm) (Wikipedia)
