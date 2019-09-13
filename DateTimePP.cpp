#include "DateTimePP.h"

DateTimePP::DateTimePP() {

}

/**
 * @brief DateTimePP::nseconds
 * @return returns the nanoseconds value between 0 - (1e+9 - 1)
 */
int DateTimePP::nseconds(int newValue_) const {
    m_nseconds = newValue_ % 1E+9;
    return m_nseconds;
}

/**
 * @brief DateTimePP::seconds
 * @return returns the seconds value between 0 - 59
 */
int DateTimePP::seconds() const {
    return m_seconds;
}

/**
 * @brief DateTimePP::minutes
 * @return returns the minutes value between 0 - 59
 */
int DateTimePP::minutes() const {
    return m_minutes;
}

/**
 * @brief DateTimePP::hours
 * @return returns the hours value between 0 - 23
 */
int DateTimePP::hours() const {
    return m_hours;
}

/**
 * @brief DateTimePP::days
 * @return returns the days value between 1 - 31
 */
int DateTimePP::days() const {
    return m_days;
}

/**
 * @brief DateTimePP::months
 * @return returns the months value between 1 - 12
 */
int DateTimePP::months() const {
    return m_months;
}

/**
 * @brief DateTimePP::years
 * @return returns the years value between INT_MIN and INT_MAX
 */
int DateTimePP::years() const {
    return m_years;
}

/**
 * @brief DateTimePP::timezone
 * @return returns the difference in hours to the timezone UTC
 */
double DateTimePP::timezone() const {
    return m_timezone;
}

