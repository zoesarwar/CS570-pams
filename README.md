# cs570-pams
* Names: Zoe Sarwar, Patrick Perrine
* Red IDs: 820523074, 820496635
* Class Accounts: cssc0802, cssc0801
* CS 570, Summer 2019
* Assignment #2, Pam
* Filename: README.md

## File Manifest
pam.h / pam.c

## Compile Instructions
After importing all necessary files, the assignment will compile with "gcc pam.h pam.c" 

## Operating Instructions
Use the command "./a.out"
Output will print in the terminal in which the program is compiled and ran. 

## List/Description of novel/significant design decisions
* Using dup2 and close while piping.
* Exercising multiple fork() processes.
* Using the appropriate variant of exec: execlp. 

## List/Description of all known deficiencies
* You have to hard code the commands into the program. 
* Right now, "ls | sort" is hard coded in, just like your example.

## Lessons learned
* Coding with pipe().
* Piping with more than two processes.
* Creating a shell-like interface.
* How and where exactly to use execlp. 
