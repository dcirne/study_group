# Design patterns: Command

The figure below illustrates the basic class diagram of the **Command** design pattern.

<img width="1024" alt="design_pattern_command" src="https://user-images.githubusercontent.com/204792/50649923-158d7000-0f4d-11e9-9a17-58e27f757a59.png">

## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -o ./bin/commands
```

```bash
./bin/commands
```

## Fun with the compiler, linker, and runtime

### One

Try builind the code with optimizations on and see the difference in file size

```bash
clang++ main.cpp -std=c++17 -O3 -o ./bin/commands
```

### Two

Try swapping the order the private member variable are declared in `UtilityBelt.hpp`, then build with warnings enabled

From
```cpp
private:
    Batclass *_batclass;
    Action _action;
```

To
```cpp
private:
    Action _action;
    Batclass *_batclass;
```

Then
```bash
clang++ main.cpp -std=c++17 -O3 -Wall -o ./bin/commands
```

### Three

Try using the non-standard, but more common, `\e` escape character, instead of the official `\x1B`, in `main.cpp`, with _pedantic_ warnings enabled

From
```cpp
printf("\x1B[0;%dm", static_cast<unsigned int>(color));
```

To
```cpp
printf("\e[0;%dm", static_cast<unsigned int>(color));
```

Then
```bash
clang++ main.cpp -std=c++17 -O3 -Wall -pedantic -o ./bin/commands
```


### Four

Try passing a null (`nullptr`) receiver to a concrete command. The assertion in the constructor should be able to catch it and abort the program's execution. But what happens when assertions are disabled?

In `main.cpp` add
```cpp
    AnswerBatphone answerBatphone2(nullptr);
```
then build, and run

Now, without changing the code, build and run disabling assertions
```bash
clang++ main.cpp -std=c++17 -O3 -Wall -pedantic -DNDEBUG -o ./bin/commands
```

See now how important it is to always check whether pointers are null?


## References

[Design Patterns: Elements of Reusable Object-Oriented Software](http://wiki.c2.com/?GangOfFour)

[Head First Design Patterns](http://shop.oreilly.com/product/9780596007126.do)
