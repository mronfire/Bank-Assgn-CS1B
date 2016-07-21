/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef ACCOUNTCLASS_H_
#define ACCOUNTCLASS_H_

#include "dateClass.h"

class Account
{
public:
	/******************************************************************
	 * CONSTRUCTORS & DESTRUCTORS
	 ******************************************************************/
	Account();
	Account(Date openingDate, string name, int accountNum, float balance);
	virtual ~Account();

	/******************************************************************
	 * MUTATORS
	 ******************************************************************/
	void SetAllValues(Date openingDate, string name, int accountNum,
					  float balance);
	void SetValue(string name);
	void SetValue(int accountNum);
	void SetValue(float balance);
	void SetValue(Date openingDate);

	/******************************************************************
	 * DEPOSIT
	 * ----------------------------------------------------------------
	 * Adds the amount into the account
	 ******************************************************************/
	virtual void Deposit(Date today, float amount);

	/******************************************************************
	 * WITHDRAWAL
	 * ----------------------------------------------------------------
	 * Deducts amount from account unless there are insufficient funds
	 * -Returns false if withdrawal can't be performed
	 ******************************************************************/
	virtual bool Withdrawal(Date today, float amount);

	/******************************************************************
	 * TRANFER FUNDS
	 * ----------------------------------------------------------------
	 * Transfers amount from the transfersAcct to this account.
	 * Withdrawal from transferAcct - deposit to this account.
	 * -Returns false if the transfer can't be performed either due to
	 * invalid account option or insufficient funds in the transferAcct
	 * -Returns true if transfer is completed
	 ******************************************************************/
	virtual bool TransferFunds(Date today, Account *transferAcct,
							   float amount);

	/******************************************************************
	 * UPDATE ACCT-
	 * ----------------------------------------------------------------
	 * Updates interest and overdraft charges based on the difference
	 * in months between the lastAccessDate and today.
	 * This should be called with each transaction
	 ******************************************************************/
	virtual void UpdateAcct(Date today);

	/******************************************************************
	 * ACCESSORS
	 ******************************************************************/
	Date   GetOpenDate() 	  const;
	string GetName()          const;
	int    GetAccountNum()    const;
	float  GetBalance()       const;
	Date   GetLastTransDate() const;

protected:
	string clientName;     //The clients name
	int    accNumber;	   //The account number
	float  currentBalance; //The current balance
	Date   openDate;	   //The opening date
	Date   lastAccessDate; //The last access date

};

#endif /* ACCOUNTCLASS_H_ */

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * Account();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Account();
 *   Constructor; Initializes class attributes
 *   Parameter: peningDate, name, accountNum, balance
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 *  ~Account();
 *    Destructor: Deletes the list in memory after program finishes
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 * Method SetAllValues() : Class Account;
 *   Parameter: peningDate, name, accountNum, balance
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetValue() : Class Account;
 *   Parameter: peningDate
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetValue() : Class Account;
 *   Parameter: name
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetAValue() : Class Account;
 *   Parameter: accountNum
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetValue() : Class Account;
 *   Parameter: balance
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Deposit() : Class Account;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Withdrawal() : Class Account;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method TransferFunds() : Class Account;
 *   Parameter: today, amount, transferAcct
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method UpdateAcct() : Class Account;
 *   Parameter: today
 *   Returns: Nothing
 ***********************************************************************/
/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 * Method GetOpenDate() : Class Account;
 *   Parameter: none
 *   Returns: The opening date
 ***********************************************************************/

/***********************************************************************
 * Method GetName() : Class Account;
 *   Parameter: none
 *   Returns: The name of client
 ***********************************************************************/

/***********************************************************************
 * Method GetAccountNum() : Class Account;
 *   Parameter: none
 *   Returns: The account number
 ***********************************************************************/

/***********************************************************************
 * Method GetBalance() : Class Account;
 *   Parameter: none
 *   Returns: The account balance
 ***********************************************************************/

/***********************************************************************
 * Method GetLastTransDate() : Class Account;
 *   Parameter: none
 *   Returns: The last transaction date
 ***********************************************************************/
