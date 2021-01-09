# Lab 11: Vectors II

## Synopsis
In this exercise, we will introduce the concept of arrays, see how arrays compare with vectors and use two-dimentional arrays to form a matrix.

## Problem 1 - sumn
Write a program that reads N and then N numbers from the standard input and then outputs their sum. Use a separate function for calculating the sum. Read the numbers into an array.

## Problem 2 - sumall
Change the `sumn` program to read numbers until the end of the input stream. The numbers will be no more than 100.

## Problem 2 - friends
Write a program that reads commands from the input stream until EOF. There are two types of commands:
* `f x y` - mark `x` and `y` as friends.
* `c x y` - check if `x` and `y` are friends. Print `yes` or `no`. Note that if `x` is a friend of `y`, then `y` is also a friend of `x`.

Use a two-dimentional array for representing friendships as a matrix. Use separate functions to mark friends or check for friendship. The number of people will be no more than 100 (i.e. 100 is the largest person ID).

Example input:
```
f 1 2
f 1 3
c 1 2
c 3 1
c 2 3
```