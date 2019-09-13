#ifndef DATETIMEPP_H
#define DATETIMEPP_H

#include <iostream>
#include <time.h>

class DateTimePP{
    public:
        DateTimePP();
        int nseconds();
        int nseconds(int newValue_);
        int seconds();
        int seconds(int newValue_);
        int minutes();
        int minutes(int newValue_)  ;
        int hours();
        int hours(int newValue_)    ;
        int days();
        int days(int newValue_)     ;
        int months();
        int months(int newValue_)   ;
        int years();
        int years(int newValue_)    ;
        double timezone();
        double timezone(double newValue_) ;
    private:
        int m_nseconds = 0;
        int m_seconds  = 0;
        int m_minutes  = 0;
        int m_hours    = 0;
        int m_days     = 1;
        int m_months   = 1;
        int m_years    = 0;
        double m_timezone = 0.0;
};

#endif // DATETIMEPP_H

/**
 * DBInterface::getCurrentDateTime
 * @brief gets current local time and outputs it
 * @return returns current local time as tm struct
 *
tm getCurrentDateTime(bool cutToHours_) {
    // create time variable
    time_t  secondsSince1970;
    struct tm *result;
    time ( &secondsSince1970 );
    result = localtime ( &secondsSince1970 );
    result->tm_year += 1900;
    result->tm_mon  += 1;
    result->tm_isdst = 0;
    if (cutToHours_) {
        result->tm_min = 0;
        result->tm_sec = 0;
    }
    return *result;
}

cout << "Hello World" << endl;
while (true) {
    tm time = getCurrentDateTime(false);
    cout << time.tm_hour << ":" << time.tm_min << ":" << time.tm_sec << endl;
    cout << time.tm_mday << "." << time.tm_mon << "." << time.tm_year << endl;
    cout << time.tm_zone << " " << time.tm_gmtoff << endl;
}

    */
