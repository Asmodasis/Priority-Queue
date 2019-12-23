#ifndef __SL_PRIORITY_QUEUE_H__
#define __SL_PRIORITY_QUEUE_H__

/*===============================================================================
FILE:              SL_PriorityQueue.h

DESCRIPTION:       The declarations for the Sorted Linked Priority Queue

COMPILER:          GNU g++ 5.4 compiled through linux make 

NOTES:             Retried from homework assignement 3 from Dr. Kostas Alexis for CS302

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis 		Retrieval date 2018-10-06 
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment

================================================================================*/


#include "../headers/PriorityQueueInterface.h"
#include "../headers/LinkedSortedList.h"
#include "../headers/PrecondViolatedExcept.h"
#include <memory>

/*===============================================================================
CLASS:             SL_PriorityQueue{};
DESCRIPTION:	   Virtual definitions for sorted lists
NOTES:             Inheriting this class requires definitions for functions.
===============================================================================*/

template<typename dataType>
class SL_PriorityQueue : public PriorityQueueInterface<dataType>, public LinkedSortedList<dataType>{
	
	private:
		// Ptr to sorted list of items
		std::unique_ptr<LinkedSortedList<dataType> > sListPtr;

	public:
		SL_PriorityQueue();
		SL_PriorityQueue(const SL_PriorityQueue& pq);
		~SL_PriorityQueue();

		bool isEmpty() const;
		bool enqueue(const dataType& newEntry);
		bool dequeue();

		// @throw PrecondViolatedExcept if priority queue is empty
		dataType peekFront() const; // throw(PrecondViolatedExcept);
		void showQueue() const;

}; // end SL_PriorityQueue

//#include "../src/SL_PriorityQueue.cpp"

#endif /*__SL_PRIORITY_QUEUE_H__*/