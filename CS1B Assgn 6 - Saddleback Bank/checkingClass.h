/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef CHECKINGCLASS_H_
#define CHECKINGCLASS_H_

#include "accountClass.h"

class Checking : public Account
{
public:
	/******************************************************************
	 * CONSTRUCTOS & DESTRUCTORS
	 ******************************************************************/
	Checking();
	Checking(Date openingDate, string name, int accountNum, float balance);
	virtual ~Checking();

	/******************************************************************
	 * MUTATORS
	 ******************************************************************/
	void SetAllValues(Date openingDate, string name, int accountNum,
			 	 	  float balance, float overdraftFee);
	void SetOverdraftFee(float overdraftFee);
	void Deposit(Date today, float amount);
	virtual bool Withdrawal(Date today, float amount);
	virtual void UpdateAcct(Date today);

	/******************************************************************
	 * ACCESSORS
	 ******************************************************************/
	float GetOverdraftFee() const;

protected:
	float overdraftPenalty;

};

#endif /* CHECKINGCLASS_H_ */

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * Checking();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Checking();
 *   Constructor; Initializes class attributes
 *   Parameter: peningDate, name, accountNum, balance
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 *  ~Checking();
 *    Destructor: Deletes the list in memory after program finishes
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 * Method SetAllValues() : Class Checking;
 *   Parameter: peningDate, name, accountNum, balance, overdraftFee
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetOverdraftFee() : Class Checking;
 *   Parameter: overdraftFee
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Deposit() : Class Checking;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Withdrawal() : Class Checking;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method UpdateAcct() : Class Checking;
 *   Parameter: today
 *   Returns: Nothing
 ***********************************************************************/
/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 * Method GetOverdraftFee() : Class Checking;
 *   Parameter: none
 *   Returns: The overdraft fee
 ***********************************************************************/
