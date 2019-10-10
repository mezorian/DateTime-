/**
 * DateTimePPDateTimeInfo.cpp
 * Purpose: implements functions of class DateTimePP which provide information about a date-time
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

/* --- get information about dates --- */

/**
 * @brief DateTimePP::daysOfYear
 * @param year_ year (>= 1582) of which this function returns the number of days
 * @return returns the number of days of the given year_
 */
int DateTimePP::daysOfYear(int year_) const {
    int result;

    if (year_ >= 1582) {

        if (leapYear(year_)) {
            result = 366;
        } else {
            result = 365;
        }

    } else {
        throw std::invalid_argument( "Only years >= 1582 can be used! This is because the Gregorian calender is used since this year." );
    }

    return result;
}

/**
 * @brief DateTimePP::daysOfMonth
 * @param month_ month of which the number of days have to be returned
 * @param year_ year (>= 1582) of the month
 * @return returns the number of days the month_ had in the year for years >= 1582. This function also considers leap-years
 */
int DateTimePP::daysOfMonth(int month_, int year_) const {
    int numberOfDaysOfMonth = 0;

    if (year_ >= 1582) {

        switch (month_) {
            case 1  : numberOfDaysOfMonth = 31; break;
            case 2  : if ( leapYear(year_)) {
                        numberOfDaysOfMonth = 29;
                      } else {
                        numberOfDaysOfMonth = 28;
                      }; break;
            case 3  : numberOfDaysOfMonth = 31; break;
            case 4  : numberOfDaysOfMonth = 30; break;
            case 5  : numberOfDaysOfMonth = 31; break;
            case 6  : numberOfDaysOfMonth = 30; break;
            case 7  : numberOfDaysOfMonth = 31; break;
            case 8  : numberOfDaysOfMonth = 31; break;
            case 9  : numberOfDaysOfMonth = 30; break;
            case 10 : numberOfDaysOfMonth = 31; break;
            case 11 : numberOfDaysOfMonth = 30; break;
            case 12 : numberOfDaysOfMonth = 31; break;
        }
    } else {
        throw std::invalid_argument( "Only years >= 1582 can be used! This is because the Gregorian calender is used since this year." );
    }
    return  numberOfDaysOfMonth;
}

/**
 * @brief DateTimePP::leapYear
 * @param year_ year (>= 1582) of which you want to know whether it is a leap year or not.
 * @return returns true if year_ is a leap year, otherwise false
 *
 * A leap year is a calendar year containing an additional day added to keep the calendar year
 * synchronized with the astronomical or seasonal year.
 *
 * This function uses the the Gregorian calendar, each leap year has 366 days instead of 365,
 * by extending February to 29 days rather than the common 28.
 * These extra days occur in years which are multiples of four
 * (with the exception of years that can be divided by 100 and which can not be divided by 400).
 *
 * Source Wikipedia:
 * https://en.wikipedia.org/wiki/Leap_year
 *
 * Please note that this function can only be used for years >= 1582.
 * This is because the Gregorian calender is used since this year.
 * For years before this, other leap-year rules have to be used.
 *
 */
bool DateTimePP::leapYear(int year_) const {
    bool yearIsLeapYear = false;

    if (year_ >= 1582) {
        if (year_ % 4 != 0 ) {
            yearIsLeapYear = false;
        } else if (year_ % 100 != 0) {
            yearIsLeapYear = true;
        } else if (year_ % 400 != 0) {
            yearIsLeapYear = false;
        } else {
            yearIsLeapYear = true;
        }
    } else {
        throw std::invalid_argument( "Only years >= 1582 can be used! This is because the Gregorian calender is used since this year." );
    }

    return yearIsLeapYear;
}
