/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef MONEYMARKETCLASS_H_
#define MONEYMARKETCLASS_H_

#include "savingsClass.h"

class MoneyMarket : public Savings
{
public:
	/******************************************************************
	 * CONSTRUCTOS & DESTRUCTORS
	 ******************************************************************/
	MoneyMarket();
	MoneyMarket(Date openingDate, string name, int accountNum,
				float balance, float intRate, float withdrPenalty);
	virtual ~MoneyMarket();

	/******************************************************************
	 * MUTATORS
	 ******************************************************************/
	void SetAllValues(Date openingDate, string name, int accountNum,
				      float balance, float intRate, float withdrPenalty);
	void SetWithdrawalPenalty(float withdrPenalty);
	void Deposit(Date today, float amount);
	virtual bool Withdrawal(Date today, float amount);

	/******************************************************************
	 * ACCESSORS
	 ******************************************************************/
	float GetWithdrawalPenalty() const;

protected:
	float withdrawalPenalty;

};

#endif /* MONEYMARKETCLASS_H_ */

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * MoneyMarket();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * MoneyMarket();
 *   Constructor; Initializes class attributes
 *   Parameter: peningDate, name, accountNum, balance, intRate,
 *              withdrPenalty
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 *  ~MoneyMarket();
 *    Destructor: Deletes the list in memory after program finishes
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 * Method SetAllValues() : Class MoneyMarket;
 *   Parameter: peningDate, name, accountNum, balance, intRate,
 *              withdrPenalty
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method SetWithdrawalPenalty() : Class MoneyMarket;
 *   Parameter: withdrPenalty
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Deposit() : Class MoneyMarket;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method Withdrawal() : Class MoneyMarket;
 *   Parameter: today, amount
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Method UpdateAcct() : Class MoneyMarket;
 *   Parameter: today
 *   Returns: Nothing
 ***********************************************************************/
/***************
 ** ACCESSORS **
 ***************/

/***********************************************************************
 * Method GetWithdrawalPenalty() : Class MoneyMarket;
 *   Parameter: none
 *   Returns: The withdrawal penalty
 ***********************************************************************/

