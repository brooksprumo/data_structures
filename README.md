A simple implementation of various data structures
==================================================

Initialization
--------------

To get started, run:

```
meson build && ninja -C build
```

To create multiple builds do:

```
meson setup --buildtype release --werror build_release
```

or

```
meson setup --buildtype debug --warnlevel 3 build_debug
```

Running and Testing
-------------------

After initializing, to build, test, and execute, run `ninja` by itself. I.e.:

```
ninja -C build test
```
