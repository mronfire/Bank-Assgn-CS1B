/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef BANKCLASS_H_
#define BANKCLASS_H_

#include "accountClass.h"

class Bank
{
public:
	/**************************************************************
	 * CONSTRUCTORS & DESTRUCTORS
	 **************************************************************/
	Bank();
	~Bank();

	/**************************************************************
	 * MUTATORS
	 **************************************************************/
	void OpenAccount(Account *newAcct);
	bool Transfer(Date transDate, Account *myAccount, float amount,
			      int transFromAcctNum, ofstream &oFile);

	/**************************************************************
	 * ACCESSORS
	 **************************************************************/
	void OutputHeader(ofstream &oFile) const;
	string OutputDisplay(Account *accObject, Date thisDate,
						 float amount) const;
	string OutputDisplay2(Account *accObject, Date thisDate, float amount,
						  string accType) const;
	//Return pointer to an account
	Account *FindAccountPtr(int acctNum);

private:
//Struct of accounts
struct AccountList
	{
		Account     *customerAccount; //The customer account pointer
		AccountList *next;			  //Pointer to next account
		AccountList *prev;            //Pointer to previous account
	};

	AccountList *head;			//The beginning of the list
	AccountList *tail;			//The end of the list
	int          numberOfAccts; //The number of accounts in the list
};

#endif /* BANKCLASS_H_ */

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * Bank();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/
/***********************************************************************
 *  ~Bank();
 *    Destructor: Deletes the list in memory after program finishes
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 *  OpenAccount();
 *
 *    Mutator; Adds the account to the doubly linked list
 * ---------------------------------------------------------------------
 *    Parameter: newAcct
 * ---------------------------------------------------------------------
 *    Returns: Nothing
 ***********************************************************************/
/***********************************************************************
 *  Transfer();
 *
 *    Mutator; Transfers money from one account to the other account
 *    specified from the input file
 * ---------------------------------------------------------------------
 *    Parameter: myAccount, fromAccount, amount, transDate, oFile
 * ---------------------------------------------------------------------
 *    Returns: A boolean value to check if the transfer was successful
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/
/***********************************************************************
 *  OutputHeader();
 *
 *    Accessor; Displays the heading of the output table to the
 *    output file
 * ---------------------------------------------------------------------
 *    Parameter: none
 * ---------------------------------------------------------------------
 *    Returns: A string variable to output into the output file
 ***********************************************************************/

/***********************************************************************
 *  OutputDisplay();
 *
 *    Accessor; Displays the data for first input file
 * ---------------------------------------------------------------------
 *    Parameter: accObject, thisDate, amount
 * ---------------------------------------------------------------------
 *    Returns: A string variable to output into the output file
 ***********************************************************************/

/***********************************************************************
 *  OutputDisplay2();
 *
 *    Accessor; Displays the data for second input file
 * ---------------------------------------------------------------------
 *    Parameter: accObj, thisDate, amount, accType
 * ---------------------------------------------------------------------
 *    Returns: A string variable to output into the output file
 ***********************************************************************/

/***********************************************************************
 *  FindAccountPtr();
 *
 *    Accessor; Finds an account object in the doubly linked list based
 *    on the account number passed in
 * ---------------------------------------------------------------------
 *    Parameter: acctNum
 * ---------------------------------------------------------------------
 *    Returns: An Account pointer
 ***********************************************************************/

