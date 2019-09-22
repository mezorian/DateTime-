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

