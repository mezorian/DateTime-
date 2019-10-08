#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("Test if now() stores the current local date time") {
    time_t  secondsSince1970;
    struct tm *ctime;
    time ( &secondsSince1970 );
    ctime = localtime ( &secondsSince1970 );
    DateTimePP dt;
    dt.now();
    REQUIRE(dt.nseconds() == 0);
    REQUIRE(dt.seconds() == ctime->tm_sec);
    REQUIRE(dt.minutes() == ctime->tm_min);
    REQUIRE(dt.hours() == ctime->tm_hour);
    REQUIRE(dt.days() == ctime->tm_mday);
    REQUIRE(dt.months() == ctime->tm_mon+1);
    REQUIRE(dt.years() == ctime->tm_year+1900);
    REQUIRE(dt.timezone() == ctime->tm_gmtoff);
}

TEST_CASE("Test if now(true) stores the current UTC date time") {
    time_t  secondsSince1970;
    struct tm *ctime;
    time ( &secondsSince1970 );
    ctime = gmtime ( &secondsSince1970 );
    DateTimePP dt;
    dt.now(true);
    REQUIRE(dt.nseconds() == 0);
    REQUIRE(dt.seconds() == ctime->tm_sec);
    REQUIRE(dt.minutes() == ctime->tm_min);
    REQUIRE(dt.hours() == ctime->tm_hour);
    REQUIRE(dt.days() == ctime->tm_mday);
    REQUIRE(dt.months() == ctime->tm_mon+1);
    REQUIRE(dt.years() == ctime->tm_year+1900);
    REQUIRE(dt.timezone() == ctime->tm_gmtoff);
}
