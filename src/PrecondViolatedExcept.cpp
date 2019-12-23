
/*===============================================================================
FILE:              PrecondViolatedExcept.cpp

DESCRIPTION:      The Implimentation file for sending error messages

COMPILER:          GNU g++ 5.4 compiled through linux make 

MODIFICATION HISTORY:

Author                  Date               Version
================================================================================
Shawn Ray       	    2018-10-06          Version 1.0 started Assignment

================================================================================*/


#include "../headers/PrecondViolatedExcept.h"
	

/*=============================================================================
FUNCTION:          PrecondViolatedExcept(const std::string& errMsg = "")
DESCRIPTION:       Overloaded Constructor, with an a message
PRECONDITION:	   Must pass an string to the class to send as an error message
POSTCONDITION:	   A location in memory for an Object to be stored (instantiated)
===============================================================================*/

PrecondViolatedExcept::PrecondViolatedExcept(const std::string& errMsg) : 
			std::logic_error("Precondition Violated Exception message recieved as : " + errMsg) {}