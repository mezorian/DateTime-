/**
 * DateTimePP.cpp
 * Purpose: implements class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"
#include <chrono>

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
 * @param newValue_ new years value between INT_MIN and INT_MAX
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
