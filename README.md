Leetcode
========

My solutions to the leetcode problems

Compile
=======

A "Makefile" sample is in the root directory, it works with most of the code. 

Some code contains mulitple solutions, different solutions are between `#ifdef DEFINATION_NAME` and `#endif` pairs. Use command

    `make VAR="-D DEFINATION_NAME"`

to compile the code.

Test
====

All the code contain a main() function in which there is some simple test code, Use command

    `make test`

to run the excutive.
