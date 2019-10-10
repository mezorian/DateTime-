/**
 * DateTimePPCurrentTime.cpp
 * Purpose: implements functions of class DateTimePP which provide current time information
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

/* --- get current time --- */

/**
 * @brief DateTimePP::now
 * @param UTC if true the current UTC time is used, otherwise the current local time is used
 * @return returns a DateTimePP object which has the current date time set
 *
 * now() sets the values of your DateTimePP object to the current time.
 * For this, the current local time is used.
 * If you set the parameter UTC to true, now() is not using the current local time but
 * the UTC time instead. The parameter is set to false by default.
 *
 */
DateTimePP DateTimePP::now(bool UTC_) {

    // create time variable
    time_t  secondsSince1970;
    struct tm *ctime;
    time ( &secondsSince1970 );

    // if UTC_ set object to gmt time, otherwise use local time
    if (UTC_) {
        ctime = gmtime ( &secondsSince1970 );
    } else {
        ctime = localtime ( &secondsSince1970 );
    }

    nseconds(0); // not supported yet
    seconds(ctime->tm_sec);
    minutes(ctime->tm_min);
    hours(ctime->tm_hour);
    days(ctime->tm_mday);
    months(ctime->tm_mon+1);
    years(ctime->tm_year+1900);
    timezone(ctime->tm_gmtoff);

    return (*this);
}
