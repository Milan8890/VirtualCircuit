# User documentation

## Project descripiton
Simulation of a virtual circuit board.
The board contains 4 types of logic gates and 2 "gates" used for transmitting/storing data.
Every gate has 2 inputs (except for NOT and OUTPUT), however there are no restrictions on how many other gates can have any given gate as an input.

Gates:
- AND
- OR
- XOR
- NOT
- INPUT
- OUTPUT

The goal is to simulate a system with 5 inputs that only outputs true when the input combination is exactly 11 (01011)

## Simulation and usage
When the right input file is given, the board sets up the circuit
After the circuit has been built the user has 3 choices
1. calc
    - given input values the board calculates the value of all gates and prints the OUTPUT gates value
2. print
    - after calc has been called at least once, prints all data from every gate to a given file
3. exit
    - exits the program

### Input file syntax
1. The first line of the file should list the name of the gates and amount that is needed for the circuit, and should always end with the OUPUT gate type
    - ex.: INPUT 2 AND 1 OR 3 OUTPUT 2
2. After the first line each line should have 2 or 3 gates, which will indicated the connections betwwen them
    - ex.: AND 0 OR 1 OR 2
    - meaning the AND gate with ID of 0 recives it's inputs from OR ID 1 and OR ID 2
    - INPUT gates don't recive inputs here
3. After the connections have been made the files last line should be: END

There are 6 included test files, test3/4/5 are set up incorrectly for testing, but test1/2 and 5-11.txt are usable


### Error handling
The program can detect:
- if the input file doesn't exist
- if the input file has a gate type which doesn't exist
- if the user attepts to connect a gate which doesn't exist
- if not all gates are connected (floating gate)
- if calc is called with too few or too many input values

if any of these errors occure the program won't exit, instead it will display the error and ask for new inputs

### Compiling
A makefile is included, it can be run 2 ways either use or test
- use: will run as described
- test: will run a test enviroment with gtest (for jporta)