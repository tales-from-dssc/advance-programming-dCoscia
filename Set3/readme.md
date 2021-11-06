# Exercises - session 03

## Matrix transpose

Program = `transpose_io.cpp`

- Program that computes the transpose of a matrix. The matrix is represented by a simple `std::vector<double>` where the number of rows and the number of columns are read from command line argument. 

## The Dutch national flag problem

Program = `dutch.cpp`

- Edsger Dijkstra proposed the famous Dutch national flag problem. The same algorithm can be applied in the partition step of quicksort. Given an array (or vector) of integers, select a pivot element. Then, the array elements can be divided into three groups (the flag's three colors): less than, equal to, and greater than the pivot element. Sort the array elements such that elements "of the same color" are together, and their collective color groups are in the correct order. Do not sort elements within each group.

For example, given this array `3 1 4 1 5 9 2 6 5 3`, if we choose 3 as the pivot value, the program could give the following output  `1 1 2 3 3 9 6 5 5 4`. If we choose 4, the outcome could be `3 1 1 3 2 4 6 5 9 5`. The code presented solves it without extra memory (i.e., without allocating a new vector) and in a single pass (i.e. loop over the elements once).

## Mean and Median

Program = `mean_median.cpp`

- Code that store the numbers contained in file `temperatures.txt` into a `std::vector<double>` and compute:
  - the mean
  - the median
  
To run it, given the executable `a.out`, type `./a.out < temperatures.txt`

## Avoid repeated words

Program = `repeated.cpp`

- Code that reads from `stdin` some words and then print the words without repetitions.

## Little women

- Read the `LittleWomen.txt` and then print all the read words (without repetitions) followed by the number of repetitions of that word. Try to ompile with the flag `-O3` (is a capital O, not a zero) to improve performance. Walltime of the algorithm is printed. To run it, given the executable `a.out`, type `./a.out < LittleWomen.txt`