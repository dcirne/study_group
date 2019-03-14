# gtkmm - Hello World

Simple "Hello World", cloned from [gtkmm-documentation](https://gitlab.gnome.org/GNOME/gtkmm-documentation/tree/gtkmm-3-24/examples/book/helloworld)


## Installation

```bash
sudo apt install libgtk-3-dev libgtkmm-3.0-dev
```


## Build and run

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

Compile the `helloworld` class into an object

```bash
g++ helloworld.cc -Wall `pkg-config --cflags --libs gtkmm-3.0` -c -o ./build/helloworld.o
```

Build the app

```bash
g++ ./build/helloworld.o main.cc -Wall `pkg-config --cflags --libs gtkmm-3.0` -o ./bin/hello_world
```

Run

```bash
./bin/hello_world
```


## References

[Programming with gtkmm 3](https://developer.gnome.org/gtkmm-tutorial/stable/)

[gtkmm](https://www.gtkmm.org/en/)
