#ifndef __NODE_H__
#define __NODE_H__

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
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment
Shawn Ray       	    2018-10-13          Version 1.1 Removed Auto keywords
														reason: the compiler 
														flagged it as an error

================================================================================*/
 
 #include <memory>


/*===============================================================================
CLASS:             Node{};
DESCRIPTION:	   Class declarations for Nodes within linked Lists
===============================================================================*/

template<typename dataType>
class Node {

	private:
		dataType item;								// whatever may be inside
		std::shared_ptr<Node<dataType> > next;		// pointer to the next Node

	public:
		Node();
		Node(const dataType& addItem);
		Node(const dataType& addItem, std::shared_ptr<Node<dataType> > nextNode);


		void setItem(const dataType& addItem);
		void setNext(std::shared_ptr<Node<dataType> > nextNode);
		
		dataType getItem() const;
		std::shared_ptr<Node<dataType> > getNext();
		//auto getNext();

		~Node();
};

//#include "../src/Node.cpp"

#endif /*__NODE_H__*/