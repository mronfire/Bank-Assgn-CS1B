/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "header.h"
/*************************************************************************
 * Saddleback Bank
 * _______________________________________________________________________
 * This program will run at once from two separate files. One file contains
 * the type of accounts and the second file contains the type of transaction
 * to be executed. The program then will read from files and execute
 * everything properly.
 * _______________________________________________________________________
 *  INPUT:
 *		None. Everything is coming from 2 files.
 * 	OUTPUT:
 *		The program will output a table containing the type of accounts
 *		with all the data from that account, and also the type of transaction
 *		done with those accounts.
 ************************************************************************/
int main()
{
	Bank        myList;			  //CALC - The bank object
	Date	    myDate;			  //CALC - Date object
	Account     *myAccount;		  //CALC - The Account object
	Checking    *myChecking;	  //CALC - The checking account object
	Savings     *mySavings;		  //CALC - The savings account object
	MoneyMarket *myMoneyMarket;	  //CALC - The money market account object
	ifstream    inFile;			  //CALC - The first input file
	ifstream    inFile2;		  //CALC - The second input file
	ofstream    oFile;			  //CALC - The output file

	unsigned short month;		  //IN & CALC & OUT - The month
	unsigned short day;			  //IN & CALC & OUT - The day
	unsigned short year;		  //IN & CALC & OUT - The year
	unsigned short accountNumber; //IN & CALC & OUT - The account number
	unsigned short fromAccount;	  //IN & CALC & OUT - Transfer from account
	unsigned short toAccount;	  //IN & CALC & OUT - Transfer to account
	float	       accountBalance;//IN & CALC & OUT - Account balance
	float		   amount;		  //IN & CALC & OUT - The amount of trans
	string		   accountType;	  //IN & CALC & OUT - The account type
	string		   accountName;   //IN & CALC & OUT - The holder name
	string         transType;	  //IN & CALC & OUT - Transaction type

	//INITIALIZE//
	month 			= 0;
	day   			= 0;
	year  			= 0;
	accountNumber 	= 0;
	fromAccount 	= 0;
	toAccount		= 0;
	amount			= 0;
	accountBalance  = 0.00;

	oFile.open("outputFile.txt");//open output file

	//PrintHeader - This function will output the Class Heading
	oFile << PrintHeader("Mario Rodriguez","Saddleback Bank",
			             'A', 6);

	//OutputHeader - Displays header for file
	myList.OutputHeader(oFile);

	inFile.open("accInputFile.txt");//open accounts file

	//WHILE-LOOP - It will read in from the file until it hits the end
	while(!inFile.eof())
	{
		inFile >> month;
		inFile >> day;
		inFile >> year;
		inFile >> accountNumber;
		inFile >> accountType;
		inFile >> accountBalance;
		getline(inFile, accountName);

		//SetDate - This will set the date for transaction
		myDate.SetDate(month, day, year);

		//SWITCH - This will check what type of account it is, and open a
		//		   new account of that type. Then it will assign it to an
		//		   account pointer in order to add it to our doubly link
		//		   list
		switch(accountType[0])
		{
		case 'C': myChecking = new Checking(myDate, accountName,
										    accountNumber, accountBalance);

				  myAccount = myChecking;

				  oFile << left << setw(19) << "OPEN CHECKING";

				  myChecking = NULL;
				  break;

		case 'S' : mySavings = new Savings(myDate, accountName,
			    						  accountNumber, accountBalance);

				   myAccount = mySavings;

				   oFile << left << setw(19) << "OPEN SAVINGS";

				   mySavings = NULL;
				   break;

		case 'M' : myMoneyMarket = new MoneyMarket(myDate, accountName,
			    								    accountNumber,
												    accountBalance, 0.20,
												    1.50);

				   myAccount = myMoneyMarket;

				   oFile << left << setw(19) << "OPEN Money Market";

				   myMoneyMarket = NULL;
				   break;

		default: cout << "***Invalid Account!***";

		}//END SWITCH

		//***OUTPUT***//
		oFile << myList.OutputDisplay(myAccount, myDate, accountBalance);

		//OpenAccount - It will add the account into the doubly link list
		myList.OpenAccount(myAccount);

	}//END WHILE

	inFile.close();//close accounts file

	/*******************************************************************
	 *                          SECOND FILE                            *
	 *******************************************************************/
	//WHILE-LOOP - It will read in from the file until it hits the end
	inFile2.open("transInputFile.txt");//Open transaction file

	while(!inFile2.eof())
	{
		inFile2 >> month;
		inFile2 >> day;
		inFile2 >> year;
		inFile2 >> toAccount;
		inFile2 >> amount;
		inFile2 >> transType;

		//SetDate - This will set the date of transaction
		myDate.SetDate(month, day, year);

		//FindAccountPtr - This will find the account pointer in the list
		myAccount = myList.FindAccountPtr(toAccount);

		//IF-STATEMENT - This will check what kind of transaction is, and
		//				 call on the proper methods to complete transaction
		if(transType == "Transfer")
		{
			inFile2 >> fromAccount;
			inFile2.ignore(numeric_limits<streamsize>::max(),'\n');

			//IF-STATEMENT - If transfer is successful it will output data
			//				 but if transfer cannot be executed because of
			//				 insufficient funds or accounts are the same
			//				 it will let know the user
			if(!myList.Transfer(myDate, myAccount, amount, fromAccount,
					            oFile))
			{
				if(toAccount == fromAccount)
				{
					oFile << "\n**** ERROR CAN\'T TRANSFER INTO"
							 " THE SAME ACCOUNT ****\n";
				}
				else
				{
					oFile << "\n*** TRANSFER FROM " << fromAccount << " TO "
						  << toAccount << " NOT ALLOWED! ***\n"
						  << "***        DUE TO INSUFFICIENT"
							 " FUNDS        ***\n\n";
				}
			}
		}
		else if(transType == "Withdrawal")
		{
			//UpdateAcct - It will update the transaction date for account
			myAccount->UpdateAcct(myDate);
			//Withdrawal - It will withdraw right amount from account
			myAccount->Withdrawal(myDate, amount);

			//OUTPUT//
			oFile << myList.OutputDisplay2(myAccount, myDate, amount,
										   "Withdrawal");
			oFile << endl;
		}
		else
		{
			//UpdateAcct - It will update the transaction date for account
			myAccount->UpdateAcct(myDate);
			//Deposit - It will deposit right amount to account
			myAccount->Deposit(myDate, amount);

			//OUTPUT//
			oFile << myList.OutputDisplay2(myAccount, myDate, amount,
										   "Deposit");
			oFile << endl;
		}//END IF

	}//END WHILE

	inFile2.close();//close transaction file

	oFile.close();//close output file

	return 0;
}
