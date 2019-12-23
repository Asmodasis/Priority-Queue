#ifndef __PRECOND_VIOLATED_EXCEPT_H__
#define __PRECOND_VIOLATED_EXCEPT_H__

/*===============================================================================
FILE:              PrecondViolatedExcept.h

DESCRIPTION:       The class declarations sending error messages

COMPILER:          GNU g++ 5.4 compiled through linux make 

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment

================================================================================*/

#include <stdexcept>
#include <string>

/*===============================================================================
CLASS:             PrecondViolatedExcept{};
DESCRIPTION:	   Errror message generation
NOTES:             Inherits std::logic_error from stdexcept 
===============================================================================*/

class PrecondViolatedExcept : public std::logic_error{
	public:
		PrecondViolatedExcept(const std::string& errMsg = "");
};

//#include "../src/PrecondViolatedExcept.cpp"

#endif /*__PRECOND_VIOLATED_EXCEPT_H__*/