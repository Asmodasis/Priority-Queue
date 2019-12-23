
/*===============================================================================
FILE:              Node.h

DESCRIPTION:       The class declarations for creating Nodes within a Linked

COMPILER:          GNU g++ 5.4 compiled through linux make 

NOTES:             Retrieved from the Textbook Data Abstraction and Problem Solving in C++ 
					Written by Frank M. Carrano and Timothy M. Henry 
					and code modified by Shawn Ray.

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Frank M. Carrano/Timothy M. Henry 			Retrieval Date 2018-10-06
Shawn Ray       	    2018-10-06         Version 1.0 started Assignment
Shawn Ray       	    2018-10-13         Version 1.1 Removed Auto keywords
														reason: the compiler 
														flagged it as an error

================================================================================*/

#include "../headers/Node.h"

/*=============================================================================
FUNCTION:          Node()
DESCRIPTION:       Default Constructor for generating Nodes for Linked lists
PRECONDITION:	   None.
POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
===============================================================================*/

template<typename dataType>
Node<dataType>::Node(){}
		
/*=============================================================================
FUNCTION:          Node(const dataType& addItem)
DESCRIPTION:       Overloaded Constructor, with an item
PRECONDITION:	   Must pass an item to be added to the Node
POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
===============================================================================*/

template<typename dataType>
Node<dataType>::Node(const dataType& addItem) : item(addItem){}
		
/*=============================================================================
FUNCTION:          Node(const dataType&, addItem, std::shared_ptr<Node<dataType> 
                                                                     >  nextNode)
DESCRIPTION:       Overloaded Constructor, with an item and pointer to next node
PRECONDITION:	   Must be passed an item and next Node pointer 
POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
===============================================================================*/

template<typename dataType>
Node<dataType>::Node(const dataType& addItem, std::shared_ptr<Node<dataType> >  nextNode)
					: item(addItem), next(nextNode){}

/*=============================================================================
FUNCTION:          setItem(const dataType& addItem)
DESCRIPTION:       Sets the item inside the Node
PRECONDITION:	   must have a Node to act on, and passed a item to set
POSTCONDITION:     None.
===============================================================================*/

template<typename dataType>
void Node<dataType>::setItem(const dataType& addItem){
	this->item = addItem;
}
		
/*=============================================================================
FUNCTION:          setNext(Node* nextNode)
DESCRIPTION:       Sets the next Node 
PRECONDITION:	   A node to act on, and a location for the next node
POSTCONDITION:
===============================================================================*/

template<typename dataType>
void Node<dataType>::setNext(std::shared_ptr<Node<dataType> > nextNode){
	this->next = nextNode;
}
		
/*=============================================================================
FUNCTION:          getItem() const
DESCRIPTION:       Gets an item from the Node
PRECONDITION:	   A node to act on
POSTCONDITION:     A location to store the item returned, data type determined by 
                     template
===============================================================================*/
		
template<typename dataType>
dataType Node<dataType>::getItem() const{
	return item;
}

/*=============================================================================
FUNCTION:          getNext()
DESCRIPTION:       Gets the next Node
PRECONDITION:	   A Node to act on and a Next pointer assigned
POSTCONDITION:     A pointer location for the Node being returned
===============================================================================*/
		
template<typename dataType>
std::shared_ptr<Node<dataType> > Node<dataType>::getNext(){
//auto Node<dataType>::getNext(){
	return next;
}

/*=============================================================================
FUNCTION:          ~Node()
DESCRIPTION:       The Node Destructor, frees the memory allocated for the next 
					 Node Pointer
PRECONDITION:	   None.
POSTCONDITION:     None.
===============================================================================*/

template<typename dataType>
Node<dataType>::~Node(){
	this->item = (dataType) 0;
	//free(this->next);
}


