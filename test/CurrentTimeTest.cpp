/**
 * CurrentTimeTest.cpp
 * Purpose: implements tests for the functions of class DateTimePP which provide current time information
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("Test if now() stores the current local date time") {
    time_t  secondsSince1970;
    struct tm *ctime;
    time ( &secondsSince1970 );
    ctime = localtime ( &secondsSince1970 );
    DateTimePP dt;
    DateTimePP dtResult = dt.now();
    REQUIRE(dt.nseconds() == 0);
    REQUIRE(dt.seconds() == ctime->tm_sec);
    REQUIRE(dt.minutes() == ctime->tm_min);
    REQUIRE(dt.hours() == ctime->tm_hour);
    REQUIRE(dt.days() == ctime->tm_mday);
    REQUIRE(dt.months() == ctime->tm_mon+1);
    REQUIRE(dt.years() == ctime->tm_year+1900);
    REQUIRE(dt.timezone() == ctime->tm_gmtoff);

    REQUIRE(dtResult.nseconds() == 0);
    REQUIRE(dtResult.seconds() == ctime->tm_sec);
    REQUIRE(dtResult.minutes() == ctime->tm_min);
    REQUIRE(dtResult.hours() == ctime->tm_hour);
    REQUIRE(dtResult.days() == ctime->tm_mday);
    REQUIRE(dtResult.months() == ctime->tm_mon+1);
    REQUIRE(dtResult.years() == ctime->tm_year+1900);
    REQUIRE(dtResult.timezone() == ctime->tm_gmtoff);
}

TEST_CASE("Test if now(true) stores the current UTC date time") {
    time_t  secondsSince1970;
    struct tm *ctime;
    time ( &secondsSince1970 );
    ctime = gmtime ( &secondsSince1970 );
    DateTimePP dt;
    DateTimePP dtResult = dt.now(true);
    REQUIRE(dt.nseconds() == 0);
    REQUIRE(dt.seconds() == ctime->tm_sec);
    REQUIRE(dt.minutes() == ctime->tm_min);
    REQUIRE(dt.hours() == ctime->tm_hour);
    REQUIRE(dt.days() == ctime->tm_mday);
    REQUIRE(dt.months() == ctime->tm_mon+1);
    REQUIRE(dt.years() == ctime->tm_year+1900);
    REQUIRE(dt.timezone() == ctime->tm_gmtoff);

    REQUIRE(dtResult.nseconds() == 0);
    REQUIRE(dtResult.seconds() == ctime->tm_sec);
    REQUIRE(dtResult.minutes() == ctime->tm_min);
    REQUIRE(dtResult.hours() == ctime->tm_hour);
    REQUIRE(dtResult.days() == ctime->tm_mday);
    REQUIRE(dtResult.months() == ctime->tm_mon+1);
    REQUIRE(dtResult.years() == ctime->tm_year+1900);
    REQUIRE(dtResult.timezone() == ctime->tm_gmtoff);
}
