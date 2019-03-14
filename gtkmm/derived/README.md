# Glade + gtkmm - Derived Class from GTK

Simple GTK derived class using an interface built with Glade. Cloned from [gtkmm-documentation](https://gitlab.gnome.org/GNOME/gtkmm-documentation/tree/gtkmm-3-24/examples/book/builder/derived)

## Installation

```bash
sudo apt install glade libgtk-3-dev libgtkmm-3.0-dev
```


## Build and run

Create directories to host the build and binary files. This helps to keep the source control clean, as those directories are ignored in commits.

```bash
mkdir build bin
```

Compile the `deriveddialog` class into an object

```bash
g++ deriveddialog.cc -Wall `pkg-config --cflags --libs gtkmm-3.0` -c -o ./build/deriveddialog.o
```

Build the app

```bash
g++ ./build/deriveddialog.o main.cc -Wall `pkg-config --cflags --libs gtkmm-3.0` -o ./bin/dialog
```

Run

```bash
./bin/dialog [--glad | --sad]
```


## References

[Programming with gtkmm 3](https://developer.gnome.org/gtkmm-tutorial/stable/)

[gtkmm](https://www.gtkmm.org/en/)
