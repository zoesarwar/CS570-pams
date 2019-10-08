########################################################################
# Zoe Sarwar (cssc0802), Patrick Perrine (cssc0801)
# CS 570 Summer 2019
# Assignment #2, Pam
# Makefile
########################################################################

# Variables

CXX = gcc 

# Targets

pam: pam.o  
	$(CXX) -o pam pam.o

pam.o: pam.cpp pam.h
	$(CXX) -c pam.h pam.c
>>>>>>> patrick
        
clean:
	rm -rf pam
        
########################[ EOF: Makefile ]################################
