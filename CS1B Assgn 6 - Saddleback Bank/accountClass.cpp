/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "accountClass.h"

/*************************************************************************
 * Constructor: Class Account
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Account::Account()
{
	clientName.clear();
	accNumber      = 0;
	currentBalance = 0.00;
}

/*************************************************************************
 * Constructor: Class Account
 *------------------------------------------------------------------------
 *  Non-Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Account::Account(Date openingDate, string name, int accountNum,
				 float balance)
{
	openDate       = openingDate;
	clientName     = name;
	accNumber      = accountNum;
	currentBalance = balance;
}

/*************************************************************************
 * Destructor: Class Bank
 *------------------------------------------------------------------------
 *  Does not perform any specific function
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 * 	  None
 *
 *  POST-CONDITIONS:
 *    Destroys the Account object
 *************************************************************************/
Account::~Account() {}

/***********************************************************************
 * Method: SetAllValues() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		openingDate  : The day of transaction
 * 		balance      : The amount in account
 * 		name		 : The client's name
 * 		accountNum   : The account number
 * ---------------------------------------------------------------------
 * This method will set all values to the attributes
 ***********************************************************************/
void Account::SetAllValues(Date openingDate, string name, int accountNum,
		                   float balance)
{
	openDate       = openingDate;
	clientName     = name;
	accNumber      = accountNum;
	currentBalance = balance;
}

/***********************************************************************
 * Method: SetValue() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		name		 : The client's name
 * ---------------------------------------------------------------------
 * This method will set the client's name value
 ***********************************************************************/
void Account::SetValue(string name)
{
	clientName = name;
}

/***********************************************************************
 * Method: SetValue() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		accountNum   : The account number
 * ---------------------------------------------------------------------
 * This method will set the account number value
 ***********************************************************************/
void Account::SetValue(int accountNum)
{
	accNumber = accountNum;
}

/***********************************************************************
 * Method: SetValue() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		balance      : The amount in account
 * ---------------------------------------------------------------------
 * This method will set the balance value
 ***********************************************************************/
void Account::SetValue(float balance)
{
	currentBalance = balance;
}

/***********************************************************************
 * Method: SetValue() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		openingDate  : The day of transaction
 * ---------------------------------------------------------------------
 * This method will set the open date value
 ***********************************************************************/
void Account::SetValue(Date openingDate)
{
	openDate = openingDate;
}

/***********************************************************************
 * Method: Deposit() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today : The day of transaction
 * 		amount:	The amount to add to the account
 * ---------------------------------------------------------------------
 * This method deposits an amount of money to the account
 ***********************************************************************/
void Account::Deposit(Date today, float amount)
{
	currentBalance += amount;
	lastAccessDate = today;
}

/***********************************************************************
 * Method : Withdraw() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		amount :	Amount to take out of the account
 * 		today  :	The day of transaction
 * ---------------------------------------------------------------------
 * This method withdraws the amount from the account
 ***********************************************************************/
bool Account::Withdrawal(Date today, float amount)
{
	cout << "Account withdraw!\n";
	return false;
}

/***********************************************************************
 * Method : TransferFunds() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		amount       :	Amount to take out of the account
 * 		today        :	The day of transaction
 * 		transferAcct :  The account to be transfer from
 * ---------------------------------------------------------------------
 * This method transfer the amount from one account to another one
 ***********************************************************************/
bool Account::TransferFunds(Date today, Account *transferAcct,
						    float amount)
{
	cout << "Transferring funds!\n";
	return false;
}

/***********************************************************************
 * Method : UpdateAcct() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		today        :	The day of transaction
 * ---------------------------------------------------------------------
 * This method updates the account last access date
 ***********************************************************************/
void Account::UpdateAcct(Date today)
{
	lastAccessDate = today;
}

/***********************************************************************
 * Method : GetOpenDate() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the open date
 ***********************************************************************/
Date Account::GetOpenDate() const
{
	return openDate;
}

/***********************************************************************
 * Method : GetName() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the name of the client
 ***********************************************************************/
string Account::GetName() const
{
	return clientName;
}

/***********************************************************************
 * Method : GetAccountNum() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the account number
 ***********************************************************************/
int Account::GetAccountNum() const
{
	return accNumber;
}

/***********************************************************************
 * Method : GetBalance() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the current balance
 ***********************************************************************/
float Account::GetBalance() const
{
	return currentBalance;
}

/***********************************************************************
 * Method : GetLastTransDate() : Class Account
 * ---------------------------------------------------------------------
 * Parameters:
 * 		none
 * ---------------------------------------------------------------------
 * This method returns the last access date
 ***********************************************************************/
Date Account::GetLastTransDate() const
{
	return lastAccessDate;
}

