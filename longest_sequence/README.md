# Find the longest contiguous common sequence

Here are lists of preferred sports from a sample gathered from a few sports fans.

Write a function that takes the preferences of two sports fans and returns the contiguous sequence of matching sports that appears in both.

Sample input:

```cpp
sportsList0 = {"Football", "Baseball", "Ice Hockey", "Golf", "Skiing", "F1"}
sportsList1 = {"Football", "IndyCar", "Lacrosse", "Baseball", "Ice Hockey", "Golf", "Basketball"}
sportsList2 = {"F1", "Softball", "Curling"}
sportsList3 = {"Skiing", "Golf", "Soccer", "IndyCar", "Lacrosse", "Rugby", "Swimming",
         "Tennis", "Badminton", "Handball"}
sportsList4 = {"Skiing", "Golf", "Tennis", "Volleyball", "IndyCar", "Lacrosse", "Rugby",
         "Swimming", "Cricket", "Badminton", "Handball"}
sportsList5 = {"F1"}
```

Sample output:

```cpp
findLongestSequence(sportsList0, sportsList1)
   Baseball
   Ice Hockey
   Golf

findLongestSequence(sportsList1, sportsList2)
   (empty)

findLongestSequence(sportsList2, sportsList0)
   F1

findLongestSequence(sportsList5, sportsList2)
   F1

findLongestSequence(sportsList3, sportsList4)
   IndyCar
   Lacrosse
   Rugby
   Swimming

findLongestSequence(sportsList4, sportsList3)
   IndyCar
   Lacrosse
   Rugby
   Swimming
```

## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```

This is a header only project. There is only need to build the main file. The headers, with their implementations, will be built in just one step.

```bash
clang++ main.cpp -std=c++17 -O3 -W -Wall -Wextra -pedantic -o ./bin/longest_sequence
```

```bash
./bin/longest_sequence
```
