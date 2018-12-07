# Design patterns: Proxy

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

## Build and run

```bash
clang++ Image.cpp -std=c++17 -c -o ./build/Image.o
```

```bash
clang++ ImageProxy.cpp -std=c++17 -c -o ./build/ImageProxy.o
```

```bash
clang++ main.cpp ./build/Image.o ./build/ImageProxy.o -std=c++17 -o ./bin/proxy
```

```bash
./bin/proxy
```

## References

[Design Patterns: Elements of Reusable Object-Oriented Software](http://wiki.c2.com/?GangOfFour)

[Head First Design Patterns](http://shop.oreilly.com/product/9780596007126.do)
