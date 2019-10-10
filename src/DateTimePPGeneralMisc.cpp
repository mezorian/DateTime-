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
