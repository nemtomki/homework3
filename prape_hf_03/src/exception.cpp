/*
 * exception.cpp
 *
 *  Created on: 2018. dec. 4.
 *      Author: prajczer
 */
#ifndef EXCEPTION_CPP_
#define EXCEPTION_CPP_
#include <exception>

class UnderFlowException : public std::exception {
    public:
        const char* what() const throw() { return "UnderFlow!"; }
};

class OverFlowException : public std::exception {
    public:
        const char* what() const throw() { return "OverFlow!"; }

};
class OutOfIndexException : public std::exception {
public:
	const char* what() const throw() {
		return "Index is out of boundaries!";
	}
};


#endif /* EXCEPTION_CPP_ */



