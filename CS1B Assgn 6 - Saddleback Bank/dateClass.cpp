/*************************************************************************
 * AUTHOR		: Mario Rodriguez
 * STUDENT ID	: 1028268
 * ASSIGN #6    : Saddleback Bank
 * CLASS		: CS1B
 * SECTION		: MWF: 8am
 * DUE DATE		: 5/23/16
 ************************************************************************/
#include "dateClass.h"

/***********************************************************************
 * Date();
 *   Constructor; Initializes class attributes
 *   Parameter: None
 *   Returns: Nothing
 ***********************************************************************/
Date::Date()
{
	dateMonth = 0;
	dateDay   = 0;
	dateYear  = 0;
}

/***********************************************************************
 * Date(unsigned short month,
 *	     unsigned short day,
 *		 unsigned short year);
 *    Constructor; Initializes class attributes
 *    Parameter: month, day, year
 *    Returns: Nothing
 ***********************************************************************/
Date::Date(unsigned short month, unsigned short day,
		   unsigned short year)
{
	dateMonth = month;
	dateDay   = day;
	dateYear  = year;
}

/***********************************************************************
 *  ~Date();
 *    Destructor; Does not perform any specific function
 *    Parameter: None
 *    Returns: Nothing
 ***********************************************************************/
Date::~Date() {}

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
void Date::SetDate(unsigned short month, unsigned short day,
				   unsigned short year)
{
	//IF-STATEMENT - If date is valid then it will set the date
	if(ValidateMonth(month) && ValidateDay(month, day, year) &&
	   ValidateYear(year))
	{
		dateMonth = month;
		dateDay   = day;
		dateYear  = year;
	}
}

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
void Date::GetDate(unsigned short &month, unsigned short &day,
				   unsigned short &year) const
{
	month = dateMonth;
	day   = dateDay;
	year  = dateYear;
}

/***********************************************************************
 * unsigned short GetYear( ) const;
 *
 *   Accessor; Retrieves the year of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: year
 **********************************************************************/
unsigned short Date::GetYear() const
{
	return dateYear;
}

/***********************************************************************
 * unsigned short GetMonth( ) const;
 *
 *   Accessor; Retrieves the month of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: month
 **********************************************************************/
unsigned short Date::GetMonth() const
{
	return dateMonth;
}

/***********************************************************************
 * unsigned short GetDay( ) const;
 *
 *   Accessor; Retrieves the day of the date object.
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: day
 **********************************************************************/
unsigned short Date::GetDay() const
{
	return dateDay;
}

/***********************************************************************
 * Date DisplayDate( ) const;
 *
 *   Accessor; Displays the date in the format MM/DD/YYYY
 *---------------------------------------------------------------------
 *   Parameter: none
 *---------------------------------------------------------------------
 *   Returns: nothing
 **********************************************************************/
string Date::DisplayDate() const
{
	ostringstream output;

	output << dateMonth;
	output << "/" ;
	output << dateDay;
	output << "/";
	output << dateYear;

	return output.str();
}

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
unsigned short Date::GetDaysInMonth (unsigned short month,
									 unsigned short year) const
{
	unsigned short days; //CALC - Number of days in month

	//IF-STATEMENT - This will calculate the days in month
	if(month == FEBRUARY)
	{
		if(IsLeapYear(year))
		{
			days = 29;
		}
		else
		{
			days = 28;
		}
	}
	else if (month == APRIL || month == JUNE ||
			 month == SEPTEMBER || month == NOVEMBER)
	{
		days = 30;
	}
	else
	{
		days = 31;
	}
	return days;
}

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
bool Date::IsLeapYear(unsigned short int year) const
{
	bool leap; //CALC - Leap year true or false

	//IF-STATEMENT - It will calculate if it is leap year or not
	if(year % 100 == 0)
	{
		if(year % 400 == 0)
		{
			leap = true;
		}
		else
		{
			leap = false;
		}
	}
	else if(year % 4 == 0)
	{
		leap = true;
	}
	else
	{
		leap = false;
	}

	return leap;
}

/***********************************************************************
 * bool ValidateMonth (unsigned short month) const;
 *
 *   Accessor; validate if the month is a valid month (1 - 12).
 *---------------------------------------------------------------------
 *   Parameter: month
 *---------------------------------------------------------------------
 *   Returns:   T/F if month is a valid month.
 **********************************************************************/
bool Date::ValidateMonth(unsigned short int month) const
{
	bool valid; //CALC - Valid month

	valid = false;

	//IF-STATEMENT - If month is in between then is valid
	if(month >= JANUARY && month <= DECEMBER)
	{
		valid = true;
	}

	return valid;

}

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
bool Date::ValidateDay(unsigned short month, unsigned short day,
		               unsigned short year) const
{
	unsigned short maxDays; //CALC - max number of days

	//GetDaysInMonth - This will get the days in an specific month
	maxDays = GetDaysInMonth(month, year);

	return (day >= 1 && day <= maxDays);
}

/***********************************************************************
 * bool ValidateYear (unsigned short year) const;
 *
 *   Accessor; Validate if the year is between 1900 and the current year
 *---------------------------------------------------------------------
 *   Parameter: year
 *---------------------------------------------------------------------
 *   Returns:  T/F if the year is a valid year
 **********************************************************************/
bool Date::ValidateYear(unsigned short int year) const
{
	bool valid; //CALC - Valid year

	valid = false;

	//IF-STATEMENT - If year is in between then its valid
	if(year >= 1990 && year <= 2016)
	{
		valid = true;
	}

	return valid;
}




