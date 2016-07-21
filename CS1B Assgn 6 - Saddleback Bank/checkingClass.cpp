/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "checkingClass.h"

/*************************************************************************
 * Constructor: Class Checking
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Checking::Checking()
{
	overdraftPenalty = 20.00;
}

/*************************************************************************
 * Constructor: Class Checking
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Checking::Checking(Date openingDate, string name, int accountNum,
		           float balance)
{
	openDate         = openingDate;
	clientName       = name;
	accNumber        = accountNum;
	currentBalance   = balance;
	overdraftPenalty = 20.00;
}

/*************************************************************************
 * Destructor: Class Checking
 *------------------------------------------------------------------------
 *  Does not perform any specific function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 * 	  None
 *
 *  POST-CONDITIONS:
 *    Destroys the Checking object
 *************************************************************************/
Checking::~Checking() {}

/***********************************************************************
 * Method: SetAllValues() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		openingDate  : The day of transaction
 * 		balance      : The amount in account
 * 		name		 : The client's name
 * 		accountNum   : The account number
 * ---------------------------------------------------------------------
 * This method will set all values to the attributes
 ***********************************************************************/
void Checking::SetAllValues(Date openingDate, string name, int accountNum,
	 	                    float balance, float overdraftFee)
{
	openDate         = openingDate;
	clientName       = name;
	accNumber        = accountNum;
	currentBalance   = balance;
	overdraftPenalty = overdraftFee;
}

/***********************************************************************
 * Method: SetOverdraftFee() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		overdraftFee : The overdraft fee
 * ---------------------------------------------------------------------
 * This method will set the overdraft fee
 ***********************************************************************/
void Checking::SetOverdraftFee(float overdraftFee)
{
	overdraftPenalty = overdraftFee;
}

/***********************************************************************
 * Method: Deposit() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today : The day of transaction
 * 		amount:	The amount to add to the account
 * ---------------------------------------------------------------------
 * This method deposits an amount of money to the account
 ***********************************************************************/
void Checking::Deposit(Date today, float amount)
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
bool Checking::Withdrawal(Date today, float amount)
{
	bool validWith;  //CALC - Valid withdrawal
	int  minBalance; //CALC - The minimum balance

	minBalance = -200.00;
	validWith  = false;

	//IF-STATEMENT - It will check if account hasn't gone below -200.00
	if(currentBalance >= minBalance)
	{
		currentBalance -= amount;

		if(today.GetMonth() > lastAccessDate.GetMonth() &&
		   currentBalance < 0.0)
		{
			currentBalance -= overdraftPenalty;
		}
		lastAccessDate = today;
		validWith      = true;
	}

	return validWith;
}

/***********************************************************************
 * Method : UpdateAcct() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today        :	The day of transaction
 * ---------------------------------------------------------------------
 * This method updates the account last access date
 ***********************************************************************/
void Checking::UpdateAcct(Date today)
{
	//IF_STATEMENT - If a month has passed it will take penalty fee from
	//				 account balance
	if(today.GetMonth() > lastAccessDate.GetMonth() &&
	   currentBalance < 0.0)
	{
		currentBalance -= overdraftPenalty;
	}
}

/***********************************************************************
 * Method : GetOverdraftFee() : Class Checking
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the overdraft fee penalty
 ***********************************************************************/
float Checking::GetOverdraftFee() const
{
	return overdraftPenalty;
}
