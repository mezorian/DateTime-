#include "DateTimePP.h"

DateTimePP::DateTimePP() {

}

/**
 * @brief DateTimePP::nseconds
 * @return returns the nanoseconds value between 0 - (1e+9 - 1)
 */
int DateTimePP::nseconds() {
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
    m_nseconds = (newValue_ % 1000000000) - 1;
    return nseconds();
}

/**
 * @brief DateTimePP::seconds
 * @return returns the seconds value between 0 - 59
 */
int DateTimePP::seconds() {
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
    m_seconds = (newValue_ % 60) - 1;
    return seconds();
}

/**
 * @brief DateTimePP::minutes
 * @return returns the minutes value between 0 - 59
 */
int DateTimePP::minutes() {
    return m_minutes;
}

/**
 * @brief DateTimePP::minutes
 * @param newValue_ new seconds value between 0 - 59
 * @return returns the minutes value between 0 - 59
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::minutes(int newValue_) {
    m_minutes = (newValue_ % 60) - 1;
    return minutes();
}

/**
 * @brief DateTimePP::hours
 * @return returns the hours value between 0 - 23
 */
int DateTimePP::hours() {
    return m_hours;
}

/**
 * @brief DateTimePP::hours
 * @param newValue_ new seconds value between 0 - 23
 * @return returns the hours value between 0 - 23
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::hours(int newValue_) {
    m_hours = (newValue_ % 24) - 1;
    return hours();
}

/**
 * @brief DateTimePP::days
 * @return returns the days value between 1 - 31
 */
int DateTimePP::days() {
    return m_days;
}

/**
 * @brief DateTimePP::days
 * @param newValue_ new seconds value between 0 - 23
 * @return returns the days value between 1 - 31
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::days(int newValue_) {
    m_days = (newValue_ % 31);
    return days();
}

/**
 * @brief DateTimePP::months
 * @return returns the months value between 1 - 12
 */
int DateTimePP::months() {
    return m_months;
}

/**
 * @brief DateTimePP::months
 * @param newValue_ new seconds value between 1 - 12
 * @return returns the months value between 1 - 12
 *
 * This function automatically adjust the given parameter to the possible values by using modulo
 */
int DateTimePP::months(int newValue_) {
    m_months = (newValue_ % 12);
    return months();
}

/**
 * @brief DateTimePP::years
 * @return returns the years value between INT_MIN and INT_MAX
 */
int DateTimePP::years() {
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
double DateTimePP::timezone(double newValue_) {
    return m_timezone;
}

