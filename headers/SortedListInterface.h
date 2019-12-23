#ifndef __SORTED_LIST_INTERFACE_H__
#define __SORTED_LIST_INTERFACE_H__

/*===============================================================================
FILE:              SortedListInterface.h

DESCRIPTION:       The interface for a sorted list

COMPILER:          GNU g++ 5.4 compiled through linux make 

NOTES:             Retried from lecture slides from Dr. Kostas Alexis for CS302

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Dr. Kostas Alexis 		Retrieval date 2018-10-06 
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment

================================================================================*/

/*===============================================================================
CLASS:             SortedListInterface{};
DESCRIPTION:	   Virtual definitions for sorted lists
NOTES:             Inheriting this class requires definitions for functions.
===============================================================================*/

template<typename dataType>
class SortedListInterface{

	public:
		virtual bool insertSorted(const dataType& newEntry) = 0;
		virtual bool removeSorted(const dataType& anEntry) = 0;
		virtual int getPosition(const dataType& anEntry) const = 0;
		virtual bool isEmpty() const = 0;
		virtual int getLength() const = 0;
		virtual bool remove(int position) = 0;
		virtual void clear() = 0;
		virtual dataType getEntry(int position) const = 0;
		virtual ~SortedListInterface() { }								// destructor definition
};


#endif /*__SORTED_LIST_INTERFACE_H__*/