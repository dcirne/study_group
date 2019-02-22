# Glade - User Interface Designer

This project implements a very simple program using Glade to build its interface.

> [Clarent](http://theswordlibrary.blogspot.com/2014/02/clarent.html) is the twin blade to [Excalibur](https://en.wikipedia.org/wiki/Excalibur#Arthur's_other_weapons). It is said to be a sword of peace meant for knighting and ceremonies as opposed to battle.


## Build and run

Create a directory to host the binary executable. This helps to keep the source control clean, as the `bin` directory is ignored in commits.

```bash
mkdir bin
```


```bash
gcc main.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -o ./bin/clarent
```

```bash
./bin/clarent
```


## References

[Glade](https://glade.gnome.org/)

[GTK+ 3 C Program using Glade 3](https://prognotes.net/2015/06/gtk-3-c-program-using-glade-3/)

[gtkmm](https://www.gtkmm.org/en/)

[Dynamic user interface using glade and gtk](https://www.youtube.com/watch?v=ORcAUeTxuTY)

[Create a minimally useful GTK3 application in C](https://www.youtube.com/watch?v=ajNvsv1ka4I)
