# Find the anagrams

Two words are consider to be anagrams if they have the same number of letters, and those letters are the same, but arranged in a different order, to form a new word.

Examples of anagrams:

* dog, god
* act, cat
* add, dad
* rats, arts

Examples of non-anagrams:

* art, rats
* ada, add
* dog, dog

In the solution presented here we implemented two functions to find the anagrams in a list of words. The first function was implemented using dictionaries. It keeps sets of anagrams with the same letters. This implementation runs faster, but uses more memory.

The second function uses nested loops, comparing the current word in the iteration with all subsequent words. It runs slower, but uses less memory.


## Run the program

The code was implemented targeting Python 3.4 or above. To run just type:

```bash
python main.py
```
