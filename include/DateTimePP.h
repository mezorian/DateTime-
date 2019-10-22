/**
 * DateTimePP.h
 * Purpose: defines class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#ifndef DATETIMEPP_H
#define DATETIMEPP_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <time.h>
#include <stdexcept>

/**
 * @brief The DateTimePP class
 *
 *     ___      _      _____ _
 *    /   \__ _| |_ __/__   (_)_ __ ___   ___   _     _
 *   / /\ / _` | __/ _ \/ /\/ | '_ ` _ \ / _ \_| |_ _| |_
 *  / /_// (_| | ||  __/ /  | | | | | | |  __/_   _|_   _|
 * /___,' \__,_|\__\___\/   |_|_| |_| |_|\___| |_|   |_|
 *
 * DateTime++ : An easy to use C++ library for date-time calculations
 *
 */
class DateTimePP{
    public:
        /* --- constructors / destructors --- */
        DateTimePP() {};

        /* --- getter / setter --- */
        int nseconds() const;
        int nseconds(int newValue_);
        int seconds() const;
        int seconds(int newValue_);
        int minutes() const;
        int minutes(int newValue_)  ;
        int hours() const;
        int hours(int newValue_)    ;
        int days() const;
        int days(int newValue_)     ;
        int months() const;
        int months(int newValue_)   ;
        int years() const;
        int years(int newValue_)    ;
        double timezone() const;
        double timezone(double newValue_) ;
        DateTimePP date() const;

        /* --- get current time --- */
        DateTimePP now(bool UTC_ = false);

        /* --- get time in different formats --- */
        long toUnixTime() const;
        std::string toString(bool inUnixTime_ = false) const;
        DateTimePP fromString(const std::string &dateTimeString_);
        std::string deletePaddingZeros(const std::string &stringWithPaddingZeros_);

        /* --- get information about dates --- */
        int daysOfYear(int year_) const;
        int daysOfMonth(int month_, int year_) const;
        bool leapYear(int year_) const;
        int numberOfDaysBetweenTwoDates(const DateTimePP& date_ , const DateTimePP& date2_) const;

        /* --- operators --- */
        bool operator==(const DateTimePP& other_) const;
        bool operator!=(const DateTimePP& other_) const;
        bool operator<(const DateTimePP& other_) const;
        //DateTimePP& operator= (const DateTimePP& other_);

    private:
        int m_nseconds = 0;
        int m_seconds  = 0;
        int m_minutes  = 0;
        int m_hours    = 0;
        int m_days     = 0;
        int m_months   = 0;
        int m_years    = 0;
        double m_timezone = 0.0;
};

#endif // DATETIMEPP_H
