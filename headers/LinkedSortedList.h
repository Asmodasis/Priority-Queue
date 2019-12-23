#ifndef __LINKED_SORTED_LIST_H__
#define __LINKED_SORTED_LIST_H__

/*===============================================================================
FILE:              LinkSortedList.h

DESCRIPTION:       The class declarations for Linked Sorted List

COMPILER:          GNU g++ 5.4 compiled through linux make 

NOTES:             Retried from lecture slides from Dr. Kostas Alexis for CS302

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis 		Retrieval date 2018-10-06 
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment
Shawn Ray       	    2018-10-13          Version 1.1 Removed Auto keywords
														reason: the compiler 
														flagged it as an error

================================================================================*/


#include <memory>
#include <iostream>
#include "../headers/SortedListInterface.h"
#include "../headers/Node.h"
#include "../headers/PrecondViolatedExcept.h" 


/*===============================================================================
CLASS:             LinkedSortedList{};
DESCRIPTION:	   Virtual definitions for sorted lists
NOTES:             Inherits from SortedListInterface
===============================================================================*/

template<typename dataType>
class LinkedSortedList : public SortedListInterface<dataType>{

	private:
		std::shared_ptr<Node<dataType> > headPtr;					// Pointer to first node in chain
		int itemCount;												// Current count of list items

		// Locates the node that is before the node that should or does contain the given entry
		std::shared_ptr<Node<dataType> >  getNodeBefore(const dataType& anEntry) const;
		//auto getNodeBefore(const dataType& anEntry) const;
		// Locate the node at a given position within the chain
		std::shared_ptr<Node<dataType> >  getNodeAt(int position) const;
		//auto getNodeAt(int position) const;
		// Returns a pointer to a copy of the chain to which origChainPtr points
		std::shared_ptr<Node<dataType> >  copyChain(const std::shared_ptr<Node<dataType> >& origChainPtr);
		//auto copyChain(const std::shared_ptr<Node<dataType> >& origChainPtr);

	public:
		LinkedSortedList();
		LinkedSortedList(const LinkedSortedList<dataType>& aList);
		~LinkedSortedList();

		bool insertSorted(const dataType& newEntry);
		bool removeSorted(const dataType& enEntry);
		int getPosition(const dataType& anEntry) const;

		// The following functions are the same as given in ListInterface
		bool isEmpty() const;
		int getLength() const;
		bool remove(int position);
		void clear();
		dataType getEntry(int position) const; //throw(PrecondViolatedExcept);
		void showList() const;


};

//#include "../src/LinkedSortedList.cpp"

#endif /*__LINKED_SORTED_LIST_H__*/