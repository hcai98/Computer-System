# Project 3

__Due date: Friday, November 13 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**



## Makefile and Testing

The `Makefile` provided with this project compiles and builds all of the required programs. __Your code will be compiled using this `Makefile` by the graders and it is your responsibility to make sure that your code can be compiled successfully on `crackle1`!__

To compile and build all of the programs run:

    make all

To compile and build individual problems run:

    make problem1
    make problem2

To run simple tests  on each program you can execute

    make run_problem1
    make run_problem2

(You should test your code much more extensively than these simple test cases provided with the assignment do.)

To remove all previously compiled and built files, run

    make clean

(It is a good idea to run `make clean` before you commit and push the files to the remote repository so that you are
  not copying binaries from one platform to the other.)

## Programming requirements:

- __The programs should be leak-free: any memory that is allocated should be freed before the program terminates.__
- The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.
- The code has to build correctly using the provided `Makefile`.
- The code has to follow C programming conventions.
- The code has to be formatted properly.  


## Problem 1 (10 points)

You are given two object files `given/problem1.o` and `given/foo_given.o` as well as an executable binary file called `given/problem1_given`. The first one contains the `main` function, the second contains a function called `foo` and the third one is the program build from the two object files. Your task is to write C code for the function `foo` in `foo_given.o`. Your code may not end up being identical to the one in the given file, but it should be equivalent (i.e., given the same inputs, it should produce the same output).

The `main()` function executes a few tests of the function `foo` in `foo_given.o`. These are not exhaustive tests and passing them does not guarantee correctness, but it should be a pretty good indicator that your code is on the right track (unless, of course, you will try to circumvent the process and design your `foo` function so that it ONLY works with the tests present in `main`).


__Your own function should be implemented in the file `foo.c`.__ In order to build the object file, run :

```
make foo.o
```

In order to build and run your code:

```
make problem1
make run_problem1
```

The output from the program will give you an idea if your function `foo` performs
the task equivalent to the given version.

__Deliverables:__
Implementation of the function `foo` in file `foo.c`.





## Problem 2 (10 points)

You are given two object files `given/problem2.o` and `given/bar_given.o` as well as an executable binary
file called `given/problem2_given`. The first one
contains the `main` function, the second contains a function called `bar` and the third
one is the program build from the two object files. Your task is to write C code for
the function `bar` in `bar_given.o`. Your code may not end up being identical to
the one in the given file, but it should be equivalent (i.e., given the same
inputs, it should produce the same output).

The `main()` function executes a few tests of the function `bar` in `bar_given.o`. These are not exhaustive tests and passing them does not
guarantee correctness, but it should be a pretty good indicator that your code is on the right track
(unless, of course, you will try to circumvent the process and design your `bar` function so that it ONLY works
  with the tests present in `main`).


__Your own function should be implemented in the file `bar.c`.__ In order to build the object file, run :

```
make bar.o
```

In order to build and run your code:

```
make problem2
make run_problem2
```

The output from the program will give you an idea if your function `bar` performs
the task equivalent to the given version.

__Deliverables:__
Implementation of the function `bar` in file `bar.c`.
