#ifndef __PRIORITY_QUEUE_INTERFACE_H__
#define __PRIORITY_QUEUE_INTERFACE_H__

/*===============================================================================
FILE:              PriorityQueueInterface.h

DESCRIPTION:       The virtual interface for Priority Queues 

COMPILER:          GNU g++ 5.4 compiled through linux make 

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment

================================================================================*/

//#include "../src/LinkedSortedList.cpp"

/*===============================================================================
CLASS:             PriorityQueueInterface{};
DESCRIPTION:	   Priority Queue interfacs, inheriting it requires redeclariations
===============================================================================*/

template<typename dataType>
class PriorityQueueInterface{

	public:


		virtual bool isEmpty() const = 0;
		virtual bool enqueue(const dataType& newEntry) = 0;
		virtual bool dequeue() = 0;

		// @throw PrecondViolatedExcept if priority queue is empty
		virtual dataType peekFront() const = 0;

		~PriorityQueueInterface(){}

};


#endif /*__PRIORITY_QUEUE_INTERFACE_H__*/