# Lab 9: Vectors

## Synopsis
In this exercise, we will introduce vectors from the standard library and use them to solve simple problems that require a collection of elements.

## Problem 1 - sum
Write a program that reads a fixed number of numbers from the standard input stream and outputs their sum.
 * Extract the calculation of the sum into a function. Write tests for it using `assert`
 * Extract the reading of the input and the writing of the output to separate functions.
 * Use `std::vector` to represent the collection of numbers.

 ## Problem 2 - avg
 Copy the program for problem 1 and change it to calculate the average, not the sum.
 * Reuse the `sum` function without modifying it. Keep the tests as well.
 * Introduce a new function `avg`, reusing the `sum`, and write tests for it using `assert`
 
