/**
 * DateTimePPOperator.cpp
 * Purpose: implements the operators of class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "DateTimePP.h"

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

/**
 * @brief DateTimePP::operator <
 * @param other_ other DateTimePP object to compare with
 * @return returns true if (*this) is before other_ . For this comparison all time variables from years downto nseconds are used
 */
bool DateTimePP::operator<(const DateTimePP &other_) const {

    bool result=false;

    // check years
    if ( (*this).years() < other_.years() ) {
        result = true;
    } else if ( (*this).years() == other_.years() ) {
        // check months
        if ( (*this).months() < other_.months() ) {
            result = true;
        } else if ( (*this).months() == other_.months() ) {
            // check days
            if ( (*this).days() < other_.days() ) {
                result = true;
            } else if ( (*this).days() == other_.days() ) {
                // check hours
                if ( (*this).hours() < other_.hours() ) {
                    result = true;
                } else if ( (*this).hours() == other_.hours() ) {
                    // check minutes
                    if ( (*this).minutes() < other_.minutes() ) {
                        result = true;
                    } else if ( (*this).minutes() == other_.minutes() ) {
                        // check seconds
                        if ( (*this).seconds() < other_.seconds() ) {
                            result = true;
                        } else if ( (*this).seconds() == other_.seconds() ) {
                            // check nseconds
                            if ( (*this).nseconds() < other_.nseconds() ) {
                                result = true;
                            }
                        }
                    }
                }
            }
        }
    }

    // return result value
    return result;

}

