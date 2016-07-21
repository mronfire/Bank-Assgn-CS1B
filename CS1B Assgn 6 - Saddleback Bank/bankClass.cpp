/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "bankClass.h"

/*************************************************************************
 * Constructor: Class Bank
 *------------------------------------------------------------------------
 *   Default constructor.
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    None
 *
 *  POST-CONDITIONS:
 *    sets the attributes to default values
 *************************************************************************/
Bank::Bank()
{
	head = NULL;
	tail = NULL;
	numberOfAccts = 0;
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
 *    Destroys the Bank object
 *************************************************************************/
Bank::~Bank()
{
	AccountList *pointer; //CALC - pointer of AccountList

	pointer = head;

	//Clear List from the front
	while(pointer != NULL)
	{
		head = head->next;
		delete pointer;

		numberOfAccts--; //Decrements the number of accounts

		pointer = head;
	}
}

/*************************************************************************
 * Method OpenAccount: Class Bank
 *------------------------------------------------------------------------
 *  Adds an account to the doubly linked list
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    newAcct:	The new account to add to the list
 *
 *  POST-CONDITIONS:
 *    None
 *************************************************************************/
void Bank::OpenAccount(Account *newAcct)
{
	AccountList *pointer;   //CALC - A pointer of account list
	AccountList *searchPtr;	//CALC - A search pointer of account list
	bool        found;		//CALC - Node found in list

	pointer   = NULL;
	searchPtr = NULL;

	pointer = new AccountList; //Dynamically creates a new AccountList

	//IF-STATEMENT - Checks to see if link list is not empty
	if(pointer != NULL)
	{
		pointer->customerAccount = newAcct; //adds account to pointer in
											//link list

		if(head == NULL)
		{
			//Insert on empty list
			pointer->next = head;
			pointer->prev = NULL;
			head          = pointer;
			tail          = pointer;
		}
		else if(head->customerAccount->GetAccountNum() >
			    pointer->customerAccount->GetAccountNum())
		{
			//Add to front
			pointer->next = head;
			pointer->prev = NULL;
			head->prev    = pointer;
			tail		  = head;
			head          = pointer;
		}
		else
		{
			//Insert in middle
			searchPtr = head;
			found     = false;
			while(searchPtr->next != NULL && !found)
			{
				if(searchPtr->next->customerAccount->GetAccountNum() >
				   pointer->customerAccount->GetAccountNum())
				{
					found = true;
				}
				else
				{
					searchPtr = searchPtr->next;
				}
			}

			if(found)
			{
				pointer->next		  = searchPtr->next;
				searchPtr->next->prev = pointer;
				searchPtr->next       = pointer;
				pointer->prev  	      = searchPtr;
				searchPtr 			  = NULL;
			}
			else
			{
				//Insert to tail
				pointer->prev   = searchPtr;
				pointer->next   = NULL;
				tail			= pointer;
				searchPtr->next = pointer;
			}
		}

		numberOfAccts++; //increments number of accounts
	}
}

/*************************************************************************
 * Method Transfer: Class Bank
 *------------------------------------------------------------------------
 *  Transfers money from one account to the other
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    transDate 		: The date of transaction
 *    myAccount			: The Account object
 *    accNum		    : The account to transfer to
 *    transFromAcctNum	: The account to transfer from
 *    amount		    : The amount to transfer to the account
 *    oFile				: The output file
 *
 *  POST-CONDITIONS:
 *    Returns true or false based on if the transfer was successful
 *************************************************************************/
bool Bank::Transfer(Date transDate, Account *myAccount, float amount,
		            int transFromAcctNum, ofstream &oFile)
{
	Bank     myList;		  //CALC - Bank object
	bool     transferSuccess; //CALC - Successful transfer
	Account  *fromAccount;    //CALC - Account transferring from

	transferSuccess = false;

	//Find accounts in the doubly link list
	fromAccount = FindAccountPtr(transFromAcctNum);

	//Checks to see if it found the accounts
	if(fromAccount != NULL && myAccount != NULL)
	{
		//UpdateAcct - It will update account
		fromAccount->UpdateAcct(transDate);

		//check to see if there is enough funds in the account and if
		//withdraw is successful
		if(fromAccount->GetBalance() >= 0.00 &&
		   fromAccount->Withdrawal(transDate, amount))
		{
			//Deposit - It will deposit amount into account
			myAccount->Deposit(transDate, amount);
			//UpdateAcct - It will update account
			fromAccount->UpdateAcct(transDate);

			//OUTPUT//
			oFile << myList.OutputDisplay2(myAccount, transDate, amount,
										   "Transfer");
			//***OUTPUT***//
			oFile << left << setw(10) << ' ' << transFromAcctNum << "    $";
			oFile << right << setw(10) << fromAccount->GetBalance();
			oFile << endl;

			transferSuccess = true;
		}
	}

	return transferSuccess;

}

/*************************************************************************
 * Method FindAccountPtr: Class Bank
 *------------------------------------------------------------------------
 *  Finds an account inside the doubly linked list
 *------------------------------------------------------------------------
 *  PRE-CONDITIONS:
 *    acctNum: The account number to search for in the list
 *
 *  POST-CONDITIONS:
 *    Returns an account pointer
 *************************************************************************/
Account* Bank::FindAccountPtr(int acctNum)
{
	AccountList *pointer;   //CALC - pointer of AccountList
	Account     *searchPtr; //CALC - Account object
	bool        found;		//CALC - found success

	pointer    = head;
	searchPtr  = NULL;
	found      = false;

	//WHILE-LOOP - It will run until account was found or end of list
	while(pointer != NULL && !found)
	{
		if(pointer->customerAccount->GetAccountNum() == acctNum)
		{
			searchPtr = pointer->customerAccount;
			found     = true;
		}
		else
		{
			pointer = pointer->next;
		}
	}

	return searchPtr;

}

/***********************************************************************
 * Method: OutputHeader(): Class Bank
 * ---------------------------------------------------------------------
 * Parameters:
 * 		oFile: The output file
 * ---------------------------------------------------------------------
 * This method displays heading of the output file
 ***********************************************************************/
void Bank::OutputHeader(ofstream &oFile) const
{
	oFile << endl << left
		  << setw(19) << "TRANSACTION" << setw(13) << "DATE"
		  << setw(8)  << "ACCT #"      << setw(27) << "ACCT NAME"
		  << setw(16) << "AMOUNT"      << setw(11) << "BALANCE"
		  << setw(13) << "FROM ACCT#"  << "FROM ACCT BAL\n";

	oFile << setw(19) << "-----------" << setw(13) << "----------"
		  << setw(8)  << "-----"       << setw(23) << "--------------------"
		  << setw(13) << "----------"  << setw(18) << "--------------"
		  << setw(13) << "----------"  << "-------------\n";

}

/***********************************************************************
 * Method: OutputDisplay(): Class Bank
 * ---------------------------------------------------------------------
 * Parameters:
 * 		accObject : The Account object
 * 		thisDate  : The date of transaction
 * 		amount    : The amount of money in account
 * ---------------------------------------------------------------------
 * This method displays the data for the first input file
 ***********************************************************************/
string Bank::OutputDisplay(Account *accObject, Date thisDate,
						   float amount) const
{
	ostringstream output;

	//***OUTPUT***//
	output << left;
	output << setw(13) << thisDate.DisplayDate()
		   << setw(8)  << accObject->GetAccountNum()
		   << setw(23) << accObject->GetName() << "$";
	output << right    << setprecision(2) << fixed
		   << setw(9)  << amount;
	output << "   $"   << setw(13)
		   << accObject->GetBalance() << endl;

	return output.str();

}

/***********************************************************************
 * Method: OutputDisplay2(): Class Bank
 * ---------------------------------------------------------------------
 * Parameters:
 * 		accObject : The Account object
 * 		thisDate  : The date of transaction
 * 		amount    : The amount of money in account
 * 		accType   : The type of account
 * ---------------------------------------------------------------------
 * This method displays the data for the second input file
 ***********************************************************************/
string Bank::OutputDisplay2(Account *accObject, Date thisDate, float amount,
		                    string accType) const
{
	ostringstream output;

	//***OUTPUT***//
	output << left;
	output << setw(19) << accType
		   << setw(13) << thisDate.DisplayDate()
		   << setw(8)  << accObject->GetAccountNum()
		   << setw(23) << accObject->GetName() << "$";
	output << right << setprecision(2) << fixed << setw(9) << amount;
	output << "   $" << setw(13) << accObject->GetBalance();

	return output.str();
}
