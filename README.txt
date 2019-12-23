

Hello, and thank you for reading this Readme file 


The file directories are set up as follows

src -- where the source files go, class implementations and exercises are found here. 
			LinkedSortedList.cpp 
			Node.cpp 
			PrecondViolatedExcept.cpp 
			SL_PriorityQueue.cpp
			implementation.cpp 
			main.cpp

headers -- headers for the abstractions, class declarations are here.
			LinkedSortedList.h 
			Node.h 
			PrecondViolatedExcept.h 
			SL_PriorityQueue.h 
			PriorityQueueInterface.h
			SortedListInterface.h


build -- object files, executables, makefile and shells.

Documenation -- has a specific document file for each part
			Exercise_1.docx			-- the description for exercise 1
			Exercise_2.docx			-- the description for exercise 2
			Exercise_3.docx			-- the description for exercise 3
			A_Star_Algorithm.docx	-- the description for for the A* Algorithm

LinkedSortedList and related headers and interfaces was acquired from either the slides or the textbook, credit is given in the headers of the files, modify notes given when appropriate.

main.cpp is the driver for this program and implemenations, I attempted to do a pool simulation prior to knowing that Dr. Alexis just wanted us to describe the idea behind it, which is found in the documentation file; I left the code in there as I thought it was valid enough to leave. The function call to poolSimulation is commented out. All it does is parse a 2d array and treat it like a pool table to sort into a queue.

I also attempted to implement my own A* algorithm over the weekend and left remnants of it in the code before hearing that Dr. Alexis just wanted us to read about and include the implementation from 
	https://www.redblobgames.com/pathfinding/a-star/implementation.html#cplusplus 
All credit for implementation.cpp and the section of my main goes to Red Blob Games for the excellent implementation of such.


Makefile will be found in build directory, and I believe it may be fixed from previous submission. Was unable to duplicate the known bug on the makefile building.
Will attempt to find time to come to office hours the the Teaching assistants for help with this if appropriate.

	CLASS: 		Cs302
	Professor	Dr. Kostas Alexis
    DATE: 		2018-10-18
    AUTHOR: 	Shawn Ray
     
