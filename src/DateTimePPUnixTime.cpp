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
