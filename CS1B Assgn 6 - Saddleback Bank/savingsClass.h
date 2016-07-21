/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef SAVINGSCLASS_H_
#define SAVINGSCLASS_H_

#include "accountClass.h"

class Savings : public Account
{
public:
	/******************************************************************
	 * CONSTRUCTOS & DESTRUCTORS
	 ******************************************************************/
	Savings();
	Savings(Date openingDate, string name, int accountNum, float balance);
	virtual ~Savings();

	/******************************************************************
	 * MUTATORS
	 ******************************************************************/
	void SetAllValues(Date openingDate, string name, int accountNum,
					  float balance, float intRate);
	void SetInterestRate(float intRate);
	void Deposit(Date today, float amount);
	virtual bool Withdrawal(Date today, float amount);
	virtual void UpdateAcct(Date today);

	/******************************************************************
	 * ACCESSORS
	 ******************************************************************/
	float GetInterestRate() const;

protected:
	float interestRate;

};

#endif /* SAVINGSCLASS_H_ */

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * Savings();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Savings();
 *   Constructor; Initializes class attributes
 *   Parameter: peningDate, name, accountNum, balance
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 *  ~Savings();
 *    Destructor: Deletes the list in memory after program finishes
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 * Method SetAllValues() : Class Savings;
 *   Parameter: peningDate, name, accountNum, balance, intRate
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetOverdraftFee() : Class Savings;
 *   Parameter: overdraftFee
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Deposit() : Class Savings;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Withdrawal() : Class Savings;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method UpdateAcct() : Class Savings;
 *   Parameter: today
 *   Returns: Nothing
 ***********************************************************************/
/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 * Method GetInterestRate() : Class Savings;
 *   Parameter: none
 *   Returns: The interest rate
 ***********************************************************************/
