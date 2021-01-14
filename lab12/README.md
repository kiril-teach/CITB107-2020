# Lab 12: Everything So Far

## Synopsis
In this exercise, we will combine everything we've learned during the semester to create an interactive program that would be similar to the one you need for the final homework and the final exam. The problem will cover input/output, loops, conditional statements, functions & parameters and vectors.

## Problem - bank
Write a program that keeps track of accounts and can transfer money between accounts The program should read commands from the standard input stream (to the end) and execute each command accordingly:
 * `open ABC 1000` - opens a new account with starting balance of 10 euro (in cent value). Print an error if the account already exists (accounts should be unique).
 * `close ABC` - closes an existing account. Print an error if the account doesn't exist.
 * `transfer ABC XYZ 5000` - transfer 50 euro from account ABC to account XYZ. Print an error if either of the accounts doesn't exist or if there is no enough funds in the source account.

 In addition:
 * Use parallel vectors to represent the account numbers and balances.
 * Implement command logic in separate functions, leaving only input/output and command parsing in main. The individual function for opening, closing or transfering should be pure, i.e. no side effect and you should be able to write unit tests for them.
 * Make the program efficient - do not copy strings or vectors.
 * You can print debug information in the standard error stream - this way this information can be separated from the standard program output during operation or grading.