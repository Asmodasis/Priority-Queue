


		/*===============================================================================
		FILE:              LinkSortedList.cpp

		DESCRIPTION:       The class implementation for Linked Sorted List

		COMPILER:          GNU g++ 5.4 compiled through linux make 

		MODIFICATION HISTORY:

		Author                  Date               Version
		================================================================================
		Shawn Ray       	    2018-10-06          Version 1.0 started Assignment
		Shawn Ray       	    2018-10-13          Version 1.1 Removed Auto keywords
														reason: the compiler 
														flagged it as an error

		================================================================================*/

		#include "../headers/LinkedSortedList.h"
		#include "../src/Node.cpp"														// MAKEFILE PROBLEM


		/*=============================================================================
		FUNCTION:          getNodeBefore(const dataType& anEntry) const
		DESCRIPTION:       Gets the Node before the current one
		PRECONDITION:	   A Linked List to act on and passed an item inside the Node to 
		                      test from the one before.
		POSTCONDITION:	   A location in memory for a pointer to the new chain
		===============================================================================*/
	
		template<typename dataType>
		std::shared_ptr<Node<dataType> >  LinkedSortedList<dataType>::getNodeBefore(const dataType& anEntry) const{
		//auto LinkedSortedList<dataType>::getNodeBefore(const dataType& anEntry) const{

			std::shared_ptr<Node<dataType> > curPtr = headPtr;
			std::shared_ptr<Node<dataType> > prevPtr;

			while( (curPtr != NULL) && (anEntry > curPtr->getItem())){

				prevPtr = curPtr;
				curPtr = curPtr->getNext();
			} // end while
			return prevPtr;
		} // end getNodeBefore

		/*=============================================================================
		FUNCTION:          getNodeAt(int position) const
		DESCRIPTION:       gets the Node at the specified location
		PRECONDITION:	   A position to test
		POSTCONDITION:	   A location in memory for a pointer to the Node
		===============================================================================*/

		template<typename dataType>
		std::shared_ptr<Node<dataType> > LinkedSortedList<dataType>::getNodeAt(int position) const{
		//auto LinkedSortedList<dataType>::getNodeAt(int position) const{

			// debugging check of precondition
			if (!((position >= 1) && (position <= itemCount)))
				throw PrecondViolatedExcept("\n\tThis Node List is empty, can not get the Node.\n");

			// count from the beginning of the chain

			std::shared_ptr<Node<dataType> > curPtr = headPtr;

			for(int skip = 1; skip < position; skip++)
				curPtr = curPtr->getNext();

			return curPtr;

		} // end getNodeAt

		/*=============================================================================
		FUNCTION:          copyChain(const std::shared_ptr<Node<dataType> >& origChainPtr)
		DESCRIPTION:       makes a new linked chain from an existing one
		PRECONDITION:	   A Linked List to act on and passed an original pointer
		POSTCONDITION:	   A location in memory for a pointer to the new chain
		===============================================================================*/

		template<typename dataType>
		std::shared_ptr<Node<dataType> >  LinkedSortedList<dataType>::copyChain(const std::shared_ptr<Node<dataType> >& origChainPtr){
		//auto LinkedSortedList<dataType>::copyChain(const std::shared_ptr<Node<dataType> >& origChainPtr){

			std::shared_ptr<Node<dataType> > copiedChainPtr;

			if(origChainPtr != NULL){

				// Build new chain from given one
				// Create new node with the current item
				copiedChainPtr = std::make_shared<Node<dataType> >(origChainPtr->getItem());
				// Make the node point to the rest of the chain
				copiedChainPtr->setNext(copyChain(origChainPtr->getNext()));
			} //end if

			return copiedChainPtr;
		}// end copyChain


		/*=============================================================================
		FUNCTION:          LinkedSortedList()
		DESCRIPTION:       Default Constructor for the Linked Sorted List
		PRECONDITION:	   None.
		POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
		===============================================================================*/

		template<typename dataType>
		LinkedSortedList<dataType>::LinkedSortedList() : headPtr(NULL), itemCount(0){



		}

		/*=============================================================================
		FUNCTION:          LinkedSortedList(const LinkedSortedList<dataType>& aList)
		DESCRIPTION:       Copy Constructor for the Linked Sorted List
		PRECONDITION:	   a Linked Sorted List to be copied from
		POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
		===============================================================================*/

		template<typename dataType>
		LinkedSortedList<dataType>::LinkedSortedList(const LinkedSortedList<dataType>& aList){
			headPtr = copyChain(aList.headPtr);
			itemCount = aList.itemCount;

		}
		
		/*=============================================================================
		FUNCTION:          ~LinkedSortedList()
		DESCRIPTION:       Destructor for the Linked Sorted List
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		LinkedSortedList<dataType>::~LinkedSortedList(){
			clear();
		}

		/*=============================================================================
		FUNCTION:          insertSorted(const dataType& newEntry)
		DESCRIPTION:       add a new item into the list but in a Sorted manner
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		bool LinkedSortedList<dataType>::insertSorted(const dataType& newEntry){

			std::shared_ptr<Node<dataType> > newNodePtr(std::make_shared<Node<dataType> >(newEntry));
			std::shared_ptr<Node<dataType> > prevPtr = getNodeBefore(newEntry);

			if(isEmpty() || (prevPtr == NULL)){

				newNodePtr->setNext(headPtr);
				headPtr = newNodePtr;

			}else{
				std::shared_ptr<Node<dataType> > aftPtr = prevPtr->getNext();
				newNodePtr->setNext(aftPtr);
				prevPtr->setNext(newNodePtr);

			} // end if
			itemCount++;
			return true;
		} // end insertSorted
		
		/*=============================================================================
		FUNCTION:          removeSorted(const dataType& enEntry)
		DESCRIPTION:       Removes an item from the list, but keeps it sorted 
		PRECONDITION:	   Needs an entry passed as an argument to remove
		POSTCONDITION:	   Boolean return value for testing.
		===============================================================================*/

		template<typename dataType>
		bool LinkedSortedList<dataType>::removeSorted(const dataType& enEntry){
			
			int position = getPosition(enEntry);
			bool ableToRemove = position > 0;

			if(ableToRemove)
				ableToRemove = remove(position);
			return ableToRemove;
		}
		
		/*=============================================================================
		FUNCTION:          getPosition(const dataType& anEntry)
		DESCRIPTION:       Tests the entire list for a match to anEntry
		PRECONDITION:	   Needs an entry passed as an argument to test
		POSTCONDITION:	   Returns the position where the value is found
		===============================================================================*/

		template<typename dataType>
		int LinkedSortedList<dataType>::getPosition(const dataType& anEntry) const{
			
			int position = 1;
			int length = getLength();

			while( (position <= length) && (anEntry > getEntry(position)) ){
				position++;
			} // end while

			if ( (position > length) || (anEntry != getEntry(position)) ){
				position = -position;
			} // end if

			return position;

		}	// end getPosition

		/*=============================================================================
		FUNCTION:          isEmpty() const
		DESCRIPTION:       Checks if the List is empty or not
		PRECONDITION:	   None.
		POSTCONDITION:	   Boolean return based on test, true if empty
		===============================================================================*/

		template<typename dataType>
		bool LinkedSortedList<dataType>::isEmpty() const{
			return (headPtr == NULL);
		}

		/*=============================================================================
		FUNCTION:          getLength() const
		DESCRIPTION:       Gets the length of the list
		PRECONDITION:	   None.
		POSTCONDITION:	   Integer return value, size of the list
		===============================================================================*/

		template<typename dataType>
		int LinkedSortedList<dataType>::getLength() const{
			return itemCount;

		}


		/*=============================================================================
		FUNCTION:          remove(int position)
		DESCRIPTION:       Removes a node and it's entry from a linked chain
		PRECONDITION:	   A linked list to act on, and a passed positional value
		POSTCONDITION:	   Boolean return if able to remove or not
		===============================================================================*/
		template<typename dataType>
		bool LinkedSortedList<dataType>::remove(int position){
			
				bool ableToRemove = (position >= 1) && (position <= itemCount);

				if(ableToRemove){

					std::shared_ptr<Node<dataType> > curPtr;

					if(position ==1){

						// remove the first node in the chain
						curPtr = headPtr;				// save pointer to node 
						headPtr = headPtr->getNext();	// save pointer to next node

					}else{

						// Find node that is before the one to remove
						std::shared_ptr<Node<dataType> > prevPtr = getNodeAt(position - 1);
						// point to the node to remove
						curPtr = prevPtr->getNext();
						// Disconnect indicated node from chain by connecting the prior node with the one after
						prevPtr->setNext(curPtr->getNext());
					} // end if

					// shared pointer deallocates memory, otherwise deallocate here

					itemCount--;						// decrease count of entries
				} // end if

				return ableToRemove;
		}


		/*=============================================================================
		FUNCTION:          clear()
		DESCRIPTION:       clears all the Nodes in the Linked List
		PRECONDITION:	   A linked list to act on
		POSTCONDITION:	   None.
		===============================================================================*/
		template<typename dataType>
		void LinkedSortedList<dataType>::clear(){

			while(!isEmpty())
				remove(1);

		} // end clear

		/*=============================================================================
		FUNCTION:          getEntry(int position) const
		DESCRIPTION:       gets the item at the node specified by the position
		PRECONDITION:	   A linked list to act on, with a position as an argument 
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		dataType LinkedSortedList<dataType>::getEntry(int position) const{ //throw(PrecondViolatedExcept)

			// Enforce precondition

			bool ableToGet = ( (position >= 1) && (position <= itemCount) );

			if(ableToGet){
				std::shared_ptr<Node<dataType> > nodePtr = getNodeAt(position);
				return nodePtr->getItem();
			}else{
				std::string message = "\n\tEither an empty list  or an invalid position\n";
				throw PrecondViolatedExcept(message);

			} // end if

		} // end getEntry

		/*=============================================================================
		FUNCTION:          showList() const 
		DESCRIPTION:       Shows the linked list to the console
		PRECONDITION:	   None.
		POSTCONDITION:	   None.
		===============================================================================*/

		template<typename dataType>
		void LinkedSortedList<dataType>::showList() const {

		    if( isEmpty() )
		    {
					std::cout << "Empty stack" << std::endl;
		    }
		    else
		    {
		        	std::cout << "Back\t";
			for (std::shared_ptr<Node<dataType> > temp = this->headPtr; temp != nullptr; temp = temp->getNext()) {
			    if( temp == this->headPtr ) {
					std::cout << '[' << temp->getItem() << "]\t";
			    }
			    else {
					std::cout << temp->getItem() << "\t";
			    }
			}
		        	std::cout << "Front" << std::endl;
		    }


		}



		