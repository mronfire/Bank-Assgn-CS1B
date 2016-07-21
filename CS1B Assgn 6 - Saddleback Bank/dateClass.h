/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#ifndef DATECLASS_H_
#define DATECLASS_H_

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

enum months
{
	JANUARY = 1, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST,
	SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

class Date
{
public:
	/***CONSTRUCTOR & DESTRUCTOR***/
	Date();
	Date(unsigned short month,
		 unsigned short day,
		 unsigned short year);
	~Date();

	/***MUTATOR***/
	void SetDate(unsigned short month,
				 unsigned short day,
				 unsigned short year);

	/***ACCESSORS***/
	void GetDate(unsigned short &month,
				 unsigned short &day,
				 unsigned short &year) const;

	unsigned short GetYear() const;
	unsigned short GetMonth() const;
	unsigned short GetDay() const;

	string DisplayDate() const;

private:
	/***UTILITY METHODS***/
	unsigned short GetDaysInMonth(unsigned short month,
                                  unsigned short year) const;

	bool IsLeapYear(unsigned short year) const;

	/***VALIDATE METHODS***/
	bool ValidateMonth(unsigned	short month) const;

	bool ValidateDay(unsigned short month,
					 unsigned short day,
					 unsigned short year) const;

	bool ValidateYear(unsigned short year) const;

	/***ATTRIBUTES***/
	unsigned short dateMonth;
	unsigned short dateDay;
	unsigned short dateYear;

};

#endif /* DATECLASS_H_ */

/***********************************************************************
 * Date Class
 *   This class represents a date
 *   It manages 3 attributes: month, day, year
 ***********************************************************************/

/*******************************
 ** CONSTRUCTOR & DESTRUCTORS **
 *******************************/
/***********************************************************************
 * Date();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 * Date(unsigned short month,
 *	     unsigned short day,
 *		 unsigned short year);
 *    Constructor; Initializes class attributes
 *    Parameter: month, day, year
 *    Returns: Nothing
 ***********************************************************************/

/***********************************************************************
 *  ~Date();
 *    Destructor; Does not perform any specific function
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/

/***************
 ** MUTATORS  **
 ***************/
/***********************************************************************
 *  void SetDate();
 *
 *    Mutator; Sets the date, checks if the date is valid using private
 *    utitlies
 * ---------------------------------------------------------------------
 *    Parameter: month, day, year
 * ---------------------------------------------------------------------
 *    Returns: Nothing
 ***********************************************************************/

/***************
 ** ACCESSORS **
 ***************/
/***********************************************************************
 * void GetDate(unsigned short &month,
 *		        unsigned short &day,
 *		        unsigned short &year) const;
 *
 *   Accessor; Retrieves all attributes of the date object
 *   			(month, day, year).
 *---------------------------------------------------------------------
 *   Parameter: month, day, year
 *---------------------------------------------------------------------
 *   Returns: month, day, and year by reference
 **********************************************************************/

/***********************************************************************
 * unsigned short GetMonth( ) const;
 *
 *   Accessor; Retrieves the month of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: month
 **********************************************************************/

/***********************************************************************
 * unsigned short GetDay( ) const;
 *
 *   Accessor; Retrieves the day of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: day
 **********************************************************************/

/***********************************************************************
 * unsigned short GetYear( ) const;
 *
 *   Accessor; Retrieves the year of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: year
 **********************************************************************/

/***********************************************************************
 * Date DisplayDate( ) const;
 *
 *   Accessor; Displays the date in the format MM/DD/YYYY
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: nothing
 **********************************************************************/

/***********************************************************************
 * unsigned short GetDaysInMonth (unsigned short month,
						          unsigned short year) const;
 *
 *   Accessor; Retrieves the total days within a month
 *---------------------------------------------------------------------
 *   Parameter: month, year
 *---------------------------------------------------------------------
 *   Returns: total days in a month
 **********************************************************************/

/************
 * UTILITIES
 ************/
/***********************************************************************
 * bool IsLeapYear (unsigned short year) const;
 *
 *   Accessor;  Retrieves T/F if the year is a leap year
 *---------------------------------------------------------------------
 *   Parameter: year
 *---------------------------------------------------------------------
 *   Returns: true if the year is a leap year, and false if it is
 *    not a leap year
 **********************************************************************/

/*******************
 * VALIDATE METHODS
 *******************/
/***********************************************************************
 * bool ValidateYear (unsigned short year) const;
 *
 *   Accessor; Validate if the year is between 1900 and the current year
 *---------------------------------------------------------------------
 *   Parameter: year
 *---------------------------------------------------------------------
 *   Returns:  T/F if the year is a valid year
 **********************************************************************/

/***********************************************************************
 * bool ValidateMonth (unsigned short month) const;
 *
 *   Accessor; validate if the month is a valid month (1 - 12).
 *---------------------------------------------------------------------
 *   Parameter: month
 *---------------------------------------------------------------------
 *   Returns:   T/F if month is a valid month.
 **********************************************************************/

/***********************************************************************
 * bool ValidateDay (unsigned short month,
		             unsigned short day,
		             unsigned short year) const;
 *
 *   Accessor; validate if the day is between 1 - maxDays.
 *   maxDays is determined on whatever is the current month.
 *---------------------------------------------------------------------
 *   Parameter: month, day, year
 *---------------------------------------------------------------------
 *   Returns:   T/F if month is a valid day.
 **********************************************************************/
