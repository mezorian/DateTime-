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


/**
 * DateTimePP::fromString
 * @brief parse formatted date-time-string to DateTimePP object
 * @param dateTimeString_ formatted date-time-string
 * @return returns a DateTimePP object which contains the datetime of dateTimeString_
 *
 * converts a date-time-string which MUST be formatted like :
 * yyyy-mm-ddThh:mm:ssZ
 * see the following example on how the string has to be formatted :
 * 2016-08-09T16:40:57Z
 *
 * NOTICE : only the tm-fields tm_year, tm_mon, tm_mday, tm_hour, tm_min, tm_sec are supported
 *          the other fields are ALWAYS initialized empty :
 */
DateTimePP DateTimePP::fromString(const std::string& dateTimeString_) {

    DateTimePP result;
    std::stringstream temp;
    std::string substring;

    // parse year
    substring = dateTimeString_.substr(0,4);
    result.years(stoi(substring));
    // parse month
    substring = dateTimeString_.substr(5,2);
    substring = deletePaddingZeros(substring);
    result.months(stoi(substring));
    // parse day
    substring = dateTimeString_.substr(8,2);
    substring = deletePaddingZeros(substring);
    result.days(stoi(substring));
    // parse hour
    substring = dateTimeString_.substr(11,2);
    substring = deletePaddingZeros(substring);
    result.hours(stoi(substring));
    // parse minutes
    substring = dateTimeString_.substr(14,2);
    substring = deletePaddingZeros(substring);
    result.minutes(stoi(substring));
    // parse seconds
    substring = dateTimeString_.substr(17,2);
    substring = deletePaddingZeros(substring);
    result.seconds(stoi(substring));

    (*this) = result;

    return result;

}

/**
 * DateTimePP::deletePaddingZeros
 * @brief removes leading padding zeros from a given string
 * @param stringWithPaddingZeros_ string with padding zeros
 * @return return stringWithPaddingZeros_ without padding zeros
 *
 * NOTICE : if stringWithPaddingZeros_ consists of only zeros
 *          the function returns "0"
 */
std::string DateTimePP::deletePaddingZeros(const std::string &stringWithPaddingZeros_) {

    std::string result = stringWithPaddingZeros_;

    // erase leading zeros
    result.erase(0, result.find_first_not_of('0'));

    // if every char was a zero
    // return only one zero
    if (result == "") {
        result = "0";
    }

    return result;
}

