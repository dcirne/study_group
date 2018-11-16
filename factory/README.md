# Design patterns: Factory and Builder

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

## Build and run

```bash
clang++ Drone.cpp -std=c++17 -c -o ./build/Drone.o
```

```bash
clang++ main.cpp ./build/Drone.o -std=c++17 -o ./bin/drone
```

```bash
./bin/drone
```

## References

[Design Patterns: Elements of Reusable Object-Oriented Software](http://wiki.c2.com/?GangOfFour)

[Head First Design Patterns](http://shop.oreilly.com/product/9780596007126.do)

[Voldemort Types](http://videocortex.io/2017/Bestiary/#-voldemort-types)
