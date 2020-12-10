# Lab 6: Functions

## Synopsis
In this exercise, we are making a deep dive into functions and more specifically how to apply separation of concern, pass parameters by value or reference, output parameters and variable scope.

## Problem 1 - calc
Refactor the `calc` program from __Lab 5__ by moving the expression parsing into another function. 

## Problem 2 - change
Refactor the `change` program from __Lab 3__ by splitting it into multiple functions:
- Move input validation into its own function
- Prompt the user for input until a valid one is provided
- Move the program logic for returning the change into a function with a side effect, i.e. a procedure.