# JumpingJimPuzzle
A solution to the Jumping Jim puzzle using graph modeling and depth-first search.

## Problem Description
Quoted from “MAD MAZES: Intriguing Mind Twisters for Puzzle Buffs, Game Nuts and Other Smart People” by Robert Abbott:
> Jumping Jim is about to begin his grand performance at the circus, but his jealous enemy, Dastardly Dan, has restrung all the trampolines. The number on each trampoline indicates how tightly strung each one is; in other words, the number indicates how far Jim will have to move (horizontally or vertically, but NOT diagonally) when he bounces off the trampoline. Jim begins his routine by leaping onto the trampoline at the upper left. He must get to the goal at the lower right, where he will take his bow. How can he get there?

Suppose we have the following maze of trampolines:

| | | | |
|-|-|-|-|
|2|1|2|3|
|3|2|0|2|
|3|0|2|1|
|2|3|1|0|

The diagram above represents all of the trampolines as squares. Beginning on the square at the upper left, marked as 2, Jim can move two squares south to a square marked 3. From there, he may move three squares east to a square marked 1, and from there he can move one square south to the goal.

For the purpose of the program, the input should be read in a file where the first line contains two positive integers indicating the number of rows and columns of the maze, and the remaining lines contain the information of each "trampoline" in the maze. We always begin in the top left corner and the goal is always in the bottom right corner, represented by 0.

For example, for the original “Jumping Jim” maze, the input is:<br>
```
7 7
3 6 4 3 2 4 3
2 1 2 3 2 5 2
2 3 4 3 4 2 3
2 4 4 3 4 2 2
4 5 1 3 2 5 4
4 3 2 2 4 5 6
2 5 2 5 6 1 0
```
This is provided in _sample_input.txt_.

## Use
Ensure that _maze.cpp_, _func.h_, and both the input and output files are located in the same directory. Navigate to that directory, compile using _g++ maze.cpp func.h_, and execute using _a.exe_. The solution will be written to the output file, showing Jim's path in terms of direction (N, S, E, W).
