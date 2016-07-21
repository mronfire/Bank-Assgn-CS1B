/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "savingsClass.h"

/*************************************************************************
 * Constructor: Class Savings
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Savings::Savings()
{
	interestRate = 0.10;
}

/*************************************************************************
 * Constructor: Class Savings
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Savings::Savings(Date openingDate, string name, int accountNum,
		           float balance)
{
	openDate       = openingDate;
	clientName     = name;
	accNumber      = accountNum;
	currentBalance = balance;
	interestRate   = 0.10;
}

/*************************************************************************
 * Destructor: Class Savings
 *------------------------------------------------------------------------
 *  Does not perform any specific function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 * 	  None
 *
 *  POST-CONDITIONS:
 *    Destroys the Savings object
 *************************************************************************/
Savings::~Savings() {}

/***********************************************************************
 * Method: SetAllValues() : Class Savings
 * ---------------------------------------------------------------------
 * Parameters:
 * 		openingDate  : The day of transaction
 * 		balance      : The amount in account
 * 		name		 : The client's name
 * 		accountNum   : The account number
 * 		intRate		 : The interest rate
 * ---------------------------------------------------------------------
 * This method will set all values to the attributes
 ***********************************************************************/
void Savings::SetAllValues(Date openingDate, string name, int accountNum,
	 	                    float balance, float intRate)
{
	openDate         = openingDate;
	clientName       = name;
	accNumber        = accountNum;
	currentBalance   = balance;
	interestRate     = intRate;
}

/***********************************************************************
 * Method: SetAllValues() : Class Savings
 * ---------------------------------------------------------------------
 * Parameters:
 * 		intRate		 : The interest rate
 * ---------------------------------------------------------------------
 * This method will set the interest rate value
 ***********************************************************************/
void Savings::SetInterestRate(float intRate)
{
	interestRate = intRate;
}

/***********************************************************************
 * Method: Deposit() : Class Savings
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today : The day of transaction
 * 		amount:	The amount to add to the account
 * ---------------------------------------------------------------------
 * This method deposits an amount of money to the account
 ***********************************************************************/
void Savings::Deposit(Date today, float amount)
{
	currentBalance += amount;
	lastAccessDate = today;
}

/***********************************************************************
 * Method : Withdraw() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		amount :	Amount to take out of the account
 * 		today  :	The day of transaction
 * ---------------------------------------------------------------------
 * This method withdraws the amount from the account
 ***********************************************************************/
bool Savings::Withdrawal(Date today, float amount)
{
	bool success;

	success = false;
	lastAccessDate = today;

	//IF-STATEMENT - It will check if the account balance after withdraw
	//			     will be negative, if so then it cannot withdraw
	if(currentBalance - amount >= 0.0)
	{
		currentBalance -= amount;
		success = true;
	}
	return success;
}

/***********************************************************************
 * Method : UpdateAcct() : Class Savings
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today        :	The day of transaction
 * ---------------------------------------------------------------------
 * This method updates the account last access date
 ***********************************************************************/
void Savings::UpdateAcct(Date today)
{
	int differenceInMonths;
	int count;

	differenceInMonths = 0;

	//IF-STATEMENT - It will check if a month has passed, if so it will
	//				 get the months and multiply the interest rate
	if(today.GetMonth() > lastAccessDate.GetMonth())
	{
		differenceInMonths = today.GetMonth() - lastAccessDate.GetMonth();

		for(count = 0; count < differenceInMonths; count++)
		{
			currentBalance *= interestRate;
		}
	}
}

/***********************************************************************
 * Method : UpdateAcct() : Class Savings
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the interest rate
 ***********************************************************************/
float Savings::GetInterestRate() const
{
	return interestRate;
}
