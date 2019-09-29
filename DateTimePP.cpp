#include "DateTimePP.h"
#include <chrono>

DateTimePP::DateTimePP() {

}

/* --- getter / setter --- */

/**
 * @brief DateTimePP::nseconds
 * @return returns the nanoseconds value between 0 - (1e+9 - 1)
 */
int DateTimePP::nseconds() const {
    return m_nseconds;
}

/**
 * @brief DateTimePP::nseconds
 * @param newValue_ new nano-seconds value between 0 - (1e+9 - 1)
 * @return returns the nanoseconds value between 0 - (1e+9 - 1)
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::nseconds(int newValue_) {
    m_nseconds = newValue_;
    return nseconds();
}

/**
 * @brief DateTimePP::seconds
 * @return returns the seconds value between 0 - 59
 */
int DateTimePP::seconds() const {
    return m_seconds;
}

/**
 * @brief DateTimePP::seconds
 * @param newValue_ new seconds value between 0 - 59
 * @return returns the seconds value between 0 - 59
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::seconds(int newValue_) {
    m_seconds = newValue_;
    return seconds();
}

/**
 * @brief DateTimePP::minutes
 * @return returns the minutes value between 0 - 59
 */
int DateTimePP::minutes() const {
    return m_minutes;
}

/**
 * @brief DateTimePP::minutes
 * @param newValue_ new minutes value between 0 - 59
 * @return returns the minutes value between 0 - 59
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::minutes(int newValue_) {
    m_minutes = newValue_;
    return minutes();
}

/**
 * @brief DateTimePP::hours
 * @return returns the hours value between 0 - 23
 */
int DateTimePP::hours() const {
    return m_hours;
}

/**
 * @brief DateTimePP::hours
 * @param newValue_ new hours value between 0 - 23
 * @return returns the hours value between 0 - 23
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::hours(int newValue_) {
    m_hours = newValue_;
    return hours();
}

/**
 * @brief DateTimePP::days
 * @return returns the days value between 1 - 31
 */
int DateTimePP::days() const {
    return m_days;
}

/**
 * @brief DateTimePP::days
 * @param newValue_ new days value between 1 - 31
 * @return returns the days value between 1 - 31
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::days(int newValue_) {
    m_days = newValue_;
    return days();
}

/**
 * @brief DateTimePP::months
 * @return returns the months value between 1 - 12
 */
int DateTimePP::months() const {
    return m_months;
}

/**
 * @brief DateTimePP::months
 * @param newValue_ new months value between 1 - 12
 * @return returns the months value between 1 - 12
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::months(int newValue_) {
    m_months = newValue_;
    return months();
}

/**
 * @brief DateTimePP::years
 * @return returns the years value between INT_MIN and INT_MAX
 */
int DateTimePP::years() const {
    return m_years;
}

/**
 * @brief DateTimePP::years
 * @param newValue_ new seconds value between INT_MIN - INT_MAX
 * @return returns the years value between INT_MIN and INT_MAX
 *
 */
int DateTimePP::years(int newValue_) {
    m_years = newValue_;
    return years();
}

/**
 * @brief DateTimePP::timezone
 * @return returns the difference in hours to the timezone UTC
 */
double DateTimePP::timezone() const {
    return m_timezone;
}

/**
 * @brief DateTimePP::timezone
 * @param newValue_ new value for difference in hours to the timezone UTC
 * @return returns the difference in hours to the timezone UTC
 */
double DateTimePP::timezone(double newValue_) {
    m_timezone = newValue_;
    return timezone();
}

/* --- get current time --- */

/**
 * @brief DateTimePP::now
 * @param UTC if true the current UTC time is used, otherwise the current local time is used
 *
 * now() sets the values of your DateTimePP object to the current time.
 * For this, the current local time is used.
 * If you set the parameter UTC to true, now() is not using the current local time but
 * the UTC time instead. The parameter is set to false by default.
 */
void DateTimePP::now(bool UTC_) {
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
    months(ctime->tm_mon);
    years(ctime->tm_year);
    timezone(ctime->tm_gmtoff);
}

/* --- get time in different formats --- */

/**
 * @brief DateTimePP::unixTime
 * @return returns the date time defined in this object as unixTime / seconds since 1. January 1970 1:00:00 AM
 */
long DateTimePP::unixTime() const {

    long yearsDiff    = years()  - 1970;
    long monthsDiff   = months() - 1;
    long daysDiff     = days()   - 1;
    long hoursDiff    = hours()  - 1;

    // add seconds
    long result = seconds();
    // add minutes
    result += minutes() * 60;
    // add hours
    result += hoursDiff * 60 * 60;
    // add days
    result += daysDiff * 24 * 60 * 60;
    // add months
    //result += numberOfDaysSinceMonth(monthsDiff) * 24 * 60 * 60; // TODO
    // add years
    //result += numberOfDaysFrom1970ToYear(yearsDiff) * 24 * 60 * 60; // TODO

    return result;
}

/* --- get information about dates --- */

int DateTimePP::daysOfMonth(int month_, int year_) const {
    int numberOfDaysOfMonth = 0;

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

/* --- operators --- */

/**
 * @brief DateTimePP::operator ==
 * @param other_ other DateTimePP object to compare with
 * @return returns true if all member variables of both DateTimePP objects are identical
 */
bool DateTimePP::operator==(const DateTimePP &other_) const {
    // check if attributes are identical
    bool isIdentical = ( ( (*this).nseconds() == other_.nseconds() ) &&
                         ( (*this).seconds()  == other_.seconds()  ) &&
                         ( (*this).minutes()  == other_.minutes()  ) &&
                         ( (*this).hours()    == other_.hours()    ) &&
                         ( (*this).days()     == other_.days()     ) &&
                         ( (*this).months()   == other_.months()   ) &&
                         ( (*this).years()    == other_.years()    ) &&
                         ( (*this).timezone() == other_.timezone() ) );

    // return result of comparison
    return isIdentical;
}

/**
 * @brief DateTimePP::operator !=
 * @param other_ other DateTimePP object to compare with
 * @return returns true if at least one of the member variables of the both DateTime objects are not identical
 */
bool DateTimePP::operator!=(const DateTimePP &other_) const {
    // check if identical and return the invers
    return (!((*this == other_)));
}

