# Study Group

This repository contains sample code from the ongoing study group.

## Getting started

Clone this repository.

```
$ git clone git@github.com:dcirne/study_group.git
$ cd study_group
```

Before starting, create a `bin` directory. That is where all binaries should be build to.

```
$ mkdir bin
```

## std::optional

Build with:
```
$ clang++ -std=c++17 optional.cpp -o ./bin/optional
$ ./bin/optional Chris P. Bacon
```

## std::variant

Build with:
```
$ clang++ -std=c++17 variant.cpp -o ./bin/variant
$ ./bin/variant
```

## Virtual

Build with:
```
$ clang++ -std=c++17 virtual.cpp -o ./bin/virtual
$ ./bin/virtual
```

## Scoped enum, Delete, and Override

Build with:
```
$ clang++ -std=c++17 -Wall modern.cpp -o ./bin/modern
$ ./bin/modern
```

