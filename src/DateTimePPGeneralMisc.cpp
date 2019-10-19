/**
 * DateTimePPGeneralMisc.cpp
 * Purpose: implements general miscellaneous functions of class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

/**
 * @brief DateTimePP::date
 * @return returns a date-time object which consists only of date variables, time variables are all set to zero
 */
DateTimePP DateTimePP::date() const {

    DateTimePP result;

    // set time variables to zero
    result.nseconds(0);
    result.seconds(0);
    result.minutes(0);
    result.hours(0);
    result.timezone(0);

    // set date variables to date values of (*this)
    result.days  ((*this).days()  );
    result.months((*this).months());
    result.years ((*this).years() );

    // return result object
    return result;
}

/**
 * DateTimePP::toString
 * @brief convert a DateTimePP object to either a formatted string or the unix-time as string
 * @param inUnixTime_ function returns unix-time as string if true, otherwise returns a formatted DateTimeString
 * @return returns either a formatted string or the unix-time as string, depending on inUnixTime_
 *
 * This function can convert a DateTimePP object to either a formatted data-time-string
 *   e.g. 2016-08-09T16:40:57Z
 * or to the unix-time (seconds since 1970) as string
 *   e.g. 1434055562
 *
 * NOTICE : only the DateTimePP values years, months, days, hours, minutes, seconds are supported
 *
 * for example :
 *
 *  DateTimePP dt;
 *  dt.seconds(2);       // seconds
 *  dt.minutes(46);     // minutes
 *  dt.hours(20);        // hours
 *  dt.days(11);        // days
 *  dt.months(6);        // months
 *  dt.years(2015);     // years
 *
 *  this returns the output
 *   2015-06-11T20:46:02Z or 1434055562
 *
 */
std::string DateTimePP::toString(bool inUnixTime_) const {

    std::stringstream dateTimeString;

    if (inUnixTime_) {
        // convert to number of seconds since 1970 (unix-time)
        long secondsSince1970 = (*this).toUnixTime();
        dateTimeString << secondsSince1970;
    } else {
        // convert to formatted string
        // e.g. 2016-08-09T16:40:57Z
        dateTimeString << (*this).years() << "-" ;
        dateTimeString << std::setfill('0') << std::setw(2);
        dateTimeString << (*this).months() << "-" ;
        dateTimeString << std::setfill('0') << std::setw(2);
        dateTimeString << (*this).days() << "T" ;
        dateTimeString << std::setfill('0') << std::setw(2);
        dateTimeString << (*this).hours() << ":" ;
        dateTimeString << std::setfill('0') << std::setw(2);
        dateTimeString << (*this).minutes()  << ":" ;
        dateTimeString << std::setfill('0') << std::setw(2);
        dateTimeString << (*this).seconds()  << "Z" ;
    }

    return dateTimeString.str();

}

