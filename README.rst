========================================
No Free Malloc
========================================

This is a simple malloc implementation, and it doesn't consider to free the memory (for fun) :P

Features
========================================

* compact : no extra memory in the heap will be used
* no free : once you allocate the memory, it leaks

Build
========================================

.. code-block:: sh

    $ clang nofree-malloc.c -shared -fPIC -o nofree-malloc.so

Use
========================================

.. code-block:: sh

    $ clang test-malloc.c -o test-malloc
    $ LD_PRELOAD=./nofree-malloc ./test-malloc  # use nofree-malloc

Result
========================================

you may see something like this

.. code-block:: sh

    $ ./test-malloc

    char address : 0x16c4010

    char address : 0x16c4030

    char address : 0x16c4050

    char address : 0x16c4070

    $ LD_PRELOAD=./nofree-malloc ./test-malloc

    my malloc :P
    my sbrk :P
    char address : 0x1521001

    my malloc :P
    my sbrk :P
    char address : 0x1521002

    my malloc :P
    my sbrk :P
    char address : 0x1521003

    my malloc :P
    my sbrk :P
    char address : 0x1521004
