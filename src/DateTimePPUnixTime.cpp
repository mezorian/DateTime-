/**
 * DateTimePPUnixTime.cpp
 * Purpose: implements functions of class DateTimePP which convert a DateTimePP object into a unix time number
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

/* --- get time in different formats --- */

/**
 * @brief DateTimePP::unixTime
 * @return returns the date time defined in this object as unixTime / seconds since 1. January 1970 1:00:00 AM
 */
long DateTimePP::toUnixTime() const {

    long result=0;
    DateTimePP dt1970;
    dt1970.nseconds(0);
    dt1970.seconds(0);
    dt1970.minutes(0);
    dt1970.hours(0);
    dt1970.days(1);
    dt1970.months(1);
    dt1970.years(1970);

    if ( (dt1970 < (*this)) || (dt1970 == (*this)) ) {

        int daysDiff = numberOfDaysBetweenTwoDates(dt1970,(*this));

        // add seconds
        result = static_cast<long>((*this).seconds());
        // add minutes
        result += static_cast<long>((*this).minutes()) * static_cast<long>(60);
        // add hours
        result += static_cast<long>((*this).hours()) * static_cast<long>(60) * static_cast<long>(60);
        // add days
        result += static_cast<long>(daysDiff) * static_cast<long>(24) * static_cast<long>(60) * static_cast<long>(60);

    } else {
        throw std::invalid_argument( "Only dates >= 1.1.1970 00:00:00 can be used!" );
    }

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
