# Design patterns: Observer

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

## Build and run

```bash
clang++ Subject.cpp -std=c++17 -c -o ./build/Subject.o
```

```bash
clang++ main.cpp ./build/Subject.o -std=c++17 -Wall -o ./bin/scores
```

```bash
./bin/scores
```

## References

[Design Patterns: Elements of Reusable Object-Oriented Software](http://wiki.c2.com/?GangOfFour)

[Head First Design Patterns](http://shop.oreilly.com/product/9780596007126.do)
