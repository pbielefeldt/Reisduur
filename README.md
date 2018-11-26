Reisduur
========

A small tool to calculate expected sailing time in regattas

About
-----

Right now, we can gauge the time for sailing from one bouy to another, given a wind speed and direction. 
It is possible to add up multiple legs.
In future, a graphical representation is planned.

Install
-------

This tool uses the [QT framework](https://doc.qt.io/) for all it does. 
Check your operating system's dependencies to build QT applications first. 
On openSUSE,you need `sudo zypper in libqt4-devel` – it might be pretty similar on most OS.

I recommend you use QT Creator and QT Designer for development, but feel free to use whatever you like.

Installation should work with
```bash
mkdir build
cd build
qmake # that's the qt magic, now you should have a Makefile
make
```
Afaik, no further options should be required.

You should now have a `./Reisduur` executable.

TODO
----

* Write a TODO

Licence
-------

This software is licensed with GNU GPL 3.0+.
You can find more information in the LICENCE file.
