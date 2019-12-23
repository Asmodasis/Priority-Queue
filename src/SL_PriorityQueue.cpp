		
		/*===============================================================================
		FILE:              SL_PriorityQueue.cpp
	
		DESCRIPTION:      The Implimentation file for Sorted Linked Priority queue's

		COMPILER:          GNU g++ 5.4 compiled through linux make 

		MODIFICATION HISTORY:

		Author                  Date               Version
		================================================================================
		Shawn Ray       	    2018-10-06          Version 1.0 Made stubs
		Shawn Ray       	    2018-10-13          Version 1.1 made constructors/desctructor
		Shawn Ray       	    2018-10-14          Version 1.0 made enqueue
		================================================================================*/

		#include "../headers/SL_PriorityQueue.h"

		/*=============================================================================
		FUNCTION:          SL_PriorityQueue()
		DESCRIPTION:       Default constructor
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		SL_PriorityQueue<dataType>::SL_PriorityQueue() : sListPtr(new LinkedSortedList<dataType>()){


		}

		/*=============================================================================
		FUNCTION:          SL_PriorityQueue(const SL_PriorityQueue& pq)
		DESCRIPTION:       Copy Constructor : Copies one queue to another.
		PRECONDITION:	   a queue passed as an argument.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		SL_PriorityQueue<dataType>::SL_PriorityQueue(const SL_PriorityQueue& pq){
			this->sListPtr = copyChain(pq->sListPtr);

		}
		
		/*=============================================================================
		FUNCTION:          ~SL_PriorityQueue()
		DESCRIPTION:       Class destructor 
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		SL_PriorityQueue<dataType>::~SL_PriorityQueue(){
			this->sListPtr->clear();

		}

		/*=============================================================================
		FUNCTION:          isEmpty() const
		DESCRIPTION:       tests if the queue is empty or not
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		bool SL_PriorityQueue<dataType>::isEmpty() const{
		
			if(sListPtr == nullptr)
				return true;
			else 
				return false;
		}


		/*=============================================================================
		FUNCTION:          enqueue(const dataType& newEntry)
		DESCRIPTION:       enters a new item into the queue
		PRECONDITION:	   A linked list to act on, with a new entry to add 
		POSTCONDITION:	   Boolean return value based on whether it can enqueue or not
		===============================================================================*/

		template<typename dataType>
		bool SL_PriorityQueue<dataType>::enqueue(const dataType& newEntry){
			
			return this->sListPtr->insertSorted(newEntry);
		}

		/*=============================================================================
		FUNCTION:          dequeue()
		DESCRIPTION:       Removes the item from the front of the queue
		PRECONDITION:	   A linked list to act on
		POSTCONDITION:	   Boolean return value based on whether it can dequeue or not
		===============================================================================*/

		template<typename dataType>
		bool SL_PriorityQueue<dataType>::dequeue(){

			return this->sListPtr->removeSorted(this->peekFront());
		}
		
		/*=============================================================================
		FUNCTION:          peekFront() const
		DESCRIPTION:       gets the item at the front of the queue, without removing it
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		dataType SL_PriorityQueue<dataType>::peekFront() const { // throw(PrecondViolatedExcept)
			return this->sListPtr->getEntry(this->sListPtr->getLength());
		}


		/*=============================================================================
		FUNCTION:          showQueue() const 
		DESCRIPTION:       Shows the linked list to the console
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		void SL_PriorityQueue<dataType>::showQueue() const{

			 this->sListPtr->showList();

		}

