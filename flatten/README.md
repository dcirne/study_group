# Flatten a dictionary

Given an array of JSON objects, all of which contain nested dictionaries. How can we flatten those dictionaries, yet perserve the notion of nesting in the keys?

The solution we're looking for concatenates keys with a dot (".") to symbolize that that level was originally nested, and aggregate the values associated with that key in an array.

For example, the following JSON:

```js
{
    "a": 1, 
    "c": {
        "a": 2, 
        "b": {
            "x": 5, 
            "y": [10, 11]
        }
    }, 
    "d": [1, 2, 3]
}
```

Would be flattened into this dictionary:

```python
{
    "a": [1], 
    "c.a": [2],
    "c.b.x": [5],
    "c.b.y": [10, 11],
    "d": [1, 2, 3]
}
```

And when concatenated with this JSON:

```js
{
    "a": [3, 5], 
    "c": {
        "a": 2, 
        "b": {
            "x": [6], 
            "y": 12
        }
    }, 
    "d": [1, 2, 3]
}
```

Would produce this dictionary:

```python
{
    "a": [1, 3, 5], 
    "c.a": [2, 2],
    "c.b.x": [5, 6],
    "c.b.y": [10, 11, 12],
    "d": [1, 2, 3, 1, 2, 3]
}
```

## The solution

The implementaiton uses a recursive solution to flatten the dictionary. Every time the value (from the key:value pair) is a dictionary, the function calls itself to flatten the nested dictionary. Otherwise it appends the values to an array.

The code was implemented in Python 3.x. To run just type:

```bash
python main.py
```

