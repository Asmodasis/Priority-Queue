#===============================================================================
#
#FILE:              Makefile
#
#DESCRIPTION:       This is the Makefile for the Priority Queue files
#
#COMPILER:          Linux make 

#NOTES:             Put other information here ...
#
#MODIFICATION HISTORY:
#
#Author                  Date               Version
#================================================================================
#Shawn Ray       	    2018-10-06          Version 1.0 started Assignment
#
#================================================================================

SHELL = /bin/sh                           # global variable for shell

CC = g++                                  # Compiler
CXXFLAGS = -pedantic -std=c++14 -Wall -g  # Compiler flags

OUTPUT = main                            # executable
LIBS =                                    # libaries-I 

#Building will be done from the build file
SRCXXDIR = ../src/
HEADXXDIR = ../headers/
BUILDXXDIR = ../build/



OBJXXFILES = main.o LinkedSortedList.o SL_PriorityQueue.o PrecondViolatedExcept.o Node.o


#.PHONY: all
all: $(OUTPUT)	
$(OUTPUT): $(OBJXXFILES)
	$(CC) $(CXXFLAGS) -o $(OUTPUT) $(OBJXXFILES)

#
#
#


main.o: $(addprefix $(SRCXXDIR), main.cpp)  
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), main.cpp) -o main.o

LinkedSortedList.o: $(addprefix $(SRCXXDIR), LinkedSortedList.cpp) #$(addprefix $(HEADXXDIR), LinkedSortedList.h) $(addprefix $(HEADXXDIR), Node.h)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), LinkedSortedList.cpp) -o LinkedSortedList.o

SL_PriorityQueue.o: $(addprefix $(SRCXXDIR), SL_PriorityQueue.cpp) #$(addprefix $(HEADXXDIR), SL_PriorityQueue.h)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), SL_PriorityQueue.cpp) -o SL_PriorityQueue.o

PrecondViolatedExcept.o: $(addprefix $(SRCXXDIR), PrecondViolatedExcept.cpp) #$(addprefix $(HEADXXDIR), PrecondViolatedExcept.h)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), PrecondViolatedExcept.cpp) -o PrecondViolatedExcept.o

Node.o: $(addprefix $(SRCXXDIR), Node.cpp) #$(addprefix $(HEADXXDIR), Node.h)
	$(CC) $(CXXFLAGS) -c $(addprefix $(SRCXXDIR), Node.cpp) -o Node.o


#
#
#
#
#
#.PHONY: clean
clean:
	
	rm -f $(OUTPUT)
	rm -f *.o

	reset
	@echo
	@echo
	@echo

	@echo Make clean, removed object and executable files ...
	@echo Contents in this Directory ...
	ls -lt

	@echo
	@echo
	@echo
#
#
#
#

