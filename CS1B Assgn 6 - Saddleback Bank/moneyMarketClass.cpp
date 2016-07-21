/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "moneyMarketClass.h"

/*************************************************************************
 * Constructor: Class MoneyMarket
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
MoneyMarket::MoneyMarket()
{
	withdrawalPenalty = 1.50;
}

/*************************************************************************
 * Constructor: Class MoneyMarket
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
MoneyMarket::MoneyMarket(Date openingDate, string name, int accountNum,
		                 float balance, float intRate, float withdrPenalty)
{
	openDate            = openingDate;
	clientName          = name;
	accNumber           = accountNum;
	currentBalance      = balance;
	interestRate        = intRate;
	withdrawalPenalty   = withdrPenalty;
}

/*************************************************************************
 * Destructor: Class MoneyMarket
 *------------------------------------------------------------------------
 *  Does not perform any specific function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 * 	  None
 *
 *  POST-CONDITIONS:
 *    Destroys the MoneyMarket object
 *************************************************************************/
MoneyMarket::~MoneyMarket() {}

/***********************************************************************
 * Method: SetAllValues() : Class MoneyMarket
 * ---------------------------------------------------------------------
 * Parameters:
 * 		openingDate  : The day of transaction
 * 		balance      : The amount in account
 * 		name		 : The client's name
 * 		accountNum   : The account number
 * 		intRate		 : The interest rate
 * 		withdrPenalty: The withdraw penalty
 * ---------------------------------------------------------------------
 * This method will set all values to the attributes
 ***********************************************************************/
void MoneyMarket::SetAllValues(Date openingDate, string name, int accountNum,
	                           float balance, float intRate,
							   float withdrPenalty)
{
	openDate           = openingDate;
	clientName         = name;
	accNumber          = accountNum;
	currentBalance     = balance;
	interestRate       = intRate;
	withdrawalPenalty  = withdrPenalty;
}

/***********************************************************************
 * Method: SetAllValues() : Class MoneyMarket
 * ---------------------------------------------------------------------
 * Parameters:
 * 		withdrPenalty: The withdraw penalty
 * ---------------------------------------------------------------------
 * This method will set the withdraw penalty value
 ***********************************************************************/
void MoneyMarket::SetWithdrawalPenalty(float withdrPenalty)
{
	withdrawalPenalty = withdrPenalty;
}

/***********************************************************************
 * Method: Deposit() : Class MoneyMarket
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today : The day of transaction
 * 		amount:	The amount to add to the account
 * ---------------------------------------------------------------------
 * This method deposits an amount of money to the account
 ***********************************************************************/
void MoneyMarket::Deposit(Date today, float amount)
{
	currentBalance += amount;
	lastAccessDate = today;
}

/***********************************************************************
 * Method : Withdraw() : Class MoneyMarket
 * ---------------------------------------------------------------------
 * Parameters:
 * 		amount :	Amount to take out of the account
 * 		today  :	The day of transaction
 * ---------------------------------------------------------------------
 * This method withdraws the amount from the account
 ***********************************************************************/
bool MoneyMarket::Withdrawal(Date today, float amount)
{
	bool  success;   //CALC - Withdraw successful
	float tempAmount;//CALC - Temporary amount

	success = false;
	lastAccessDate = today;

	//IF-STATEMENT - It will check if there is enough money in the account
	//				 to withdraw successfully
	if(currentBalance - amount >= 0.0)
	{
		tempAmount = currentBalance - amount;

		if(tempAmount - withdrawalPenalty != 0)
		{
			currentBalance = currentBalance - amount - withdrawalPenalty;
			success = true;
		}
	}
	return success;
}

/***********************************************************************
 * Method : GetWithdrawalPenalty() : Class MoneyMarket
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the withdraw penalty
 ***********************************************************************/
float MoneyMarket::GetWithdrawalPenalty() const
{
	return withdrawalPenalty;
}
