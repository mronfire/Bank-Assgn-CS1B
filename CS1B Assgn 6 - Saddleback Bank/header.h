/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef HEADER_H_
#define HEADER_H_

#include "bankClass.h"
#include "accountClass.h"
#include "checkingClass.h"
#include "savingsClass.h"
#include "moneyMarketClass.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <ios>
#include <limits>
using namespace std;

//PROTOTYPES
/************************************************************************
 * PrintHeader
 * This function receives an assignment name, type and number then outputs
 * the appropriate header - returns the header box with information from
 * the programmer.
 ************************************************************************/
string PrintHeader(string programmer,// IN - programmers name
				   string asNameF,   // IN - assignment Name
 				   char asTypeF,     // IN - assignment type
	 	 	 	 				     //      (LAB or ASSIGNMENT)
 				   int asNumF);      // IN - assignment number

#endif /* HEADER_H_ */
