/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/

#include "header.h"

 /***********************************************************************
 *
 * FUNCTION PrintHeader
 *_______________________________________________________________________
 * This function receives an assignment name, type
 *  and number then outputs the appropriate header -
 *  returns nothing.
 *_______________________________________________________________________
 * PRE-CONDITIONS
 * 		asNameF: Assignment Name has to be previously defined
 * 		asTypeF: Assignment Type has to be previously defined
 * 		asNumF : Assignment Number has to be previously defined
 *
 * POST-CONDITIONS
 * 		This function will output the class heading.
 ************************************************************************/

string PrintHeader(string programmer,// IN - programmers name
				   string asNameF,   // IN - assignment Name
 				   char asTypeF,     // IN - assignment type
	 	 	 	 				     //      (LAB or ASSIGNMENT)
 				   int asNumF)       // IN - assignment number
{

	ostringstream header;

	header << left;
	header << "***********************************************************";
	header << "\n* PROGRAMMED BY : " << programmer;
	header << "\n* " << setw(14) << "STUDENT ID" << ": 1028268";
	header << "\n* " << setw(14) << "CLASS" << ": CS1B –-> MWF - 8am";
	header << "\n* " ;

	// IF STATEMENT - The user will be able to choose if its a Lab or
	//				  assignment and output the proper output.
	if (toupper(asTypeF) == 'L')
	{
		header << "LAB #" << setw(9);
	}
	else
	{
		header << "ASSIGNMENT #" << setw(2);
	}

	header << asNumF << ": " << asNameF << endl;
	header << "***********************************************************";
	header << endl;
	header << right;

	return header.str();
}
