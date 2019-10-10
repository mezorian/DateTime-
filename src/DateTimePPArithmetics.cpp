/**
 * DateTimePPArithmetics.cpp
 * Purpose: implements the arithmetic functions of class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

/**
 * @brief DateTimePP::numberOfDaysBetweenTwoDates
 * @param date1_ start-date with year (>= 1582)
 * @param date2_ end-date with year (>= 1582)
 * @return returns the number of days between the two dates
 *
 * This function calculates in full days. The time-stamp and time-zone are not considered.
 * Leap years are considered during calculation.
 * date1_ has to be <= date2_
 *
 * For example :
 *  : numberOfDaysBetweenTwoDates(1.1.2000,1.1.2000) == 0
 *  : numberOfDaysBetweenTwoDates(1.1.2000,2.1.2000) == 1
 *  : numberOfDaysBetweenTwoDates(1.1.2000,10.1.2000) == 9
 */
int DateTimePP::numberOfDaysBetweenTwoDates(const DateTimePP &date1_, const DateTimePP &date2_) const {
    DateTimePP result, date1 = date1_, date2 = date2_;
    int numberOfDays = 0;

    if ( (date1_.years() < 1582) || (date2_.years() < 1582) )  {
        throw std::invalid_argument( "Only years >= 1582 can be used! This is because the Gregorian calender is used since this year." );
    }

    if ( (date1_ < date2_) || (date1_ == date2_) ) {

        while (date1.date() < date2.date()) {
            date1.days(date1.days()+1);
            numberOfDays++;
            if ( date1.days() > daysOfMonth(date1.months(),date1.years()) ) {
                date1.months( date1.months() + 1);
                date1.days(1);
            }
            if ( date1.months() > 12 ) {
                date1.years( date1.years() + 1);
                date1.months(1);
            }
        }

    } else {
        throw std::invalid_argument( "Error : date1_ has to be before date2_ . Please switch the order of the parameters." );
    }

    return numberOfDays;
}
