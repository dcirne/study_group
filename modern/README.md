# Modern C++ (17)

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

## std::optional

Build and run:
```bash
clang++ -std=c++17 optional.cpp -o ./bin/optional

./bin/optional Chris P. Bacon
```

## std::variant

Build and run:
```bash
clang++ -std=c++17 variant.cpp -o ./bin/variant

./bin/variant
```

## Virtual

Build and run:
```bash
clang++ -std=c++17 virtual.cpp -o ./bin/virtual
./bin/virtual
```

## Scoped enum, Delete, and Override

Build and run:
```bash
clang++ -std=c++17 -Wall modern.cpp -o ./bin/modern
./bin/modern
```

