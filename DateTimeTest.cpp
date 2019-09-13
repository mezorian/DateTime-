#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "DateTimePP.h"


TEST_CASE("Test if DatetimePP points to 01.01.00 0:0:0") {
    DateTimePP dt;
    REQUIRE(dt.nseconds()  == 0);
    REQUIRE(dt.seconds()  == 0);
    REQUIRE(dt.seconds()  == 0);
    REQUIRE(dt.minutes()  == 0);
    REQUIRE(dt.hours()    == 0);
    REQUIRE(dt.days()     == 1);
    REQUIRE(dt.months()   == 1);
    REQUIRE(dt.years()    == 0);
    REQUIRE(dt.timezone() == 0.0);
}

TEST_CASE("Test if get returns the previously set value") {
    DateTimePP dt;
    int nseconds, seconds, minutes, hours, days, months, years;
    double timezone;

    SECTION("test if get and set works for normal valid values") {
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0;

        REQUIRE(dt.seconds(seconds)  == seconds);
        REQUIRE(dt.minutes(minutes)  == minutes);
        REQUIRE(dt.hours(hours)    == hours);
        REQUIRE(dt.days(days)     == days);
        REQUIRE(dt.months(months)   == months);
        REQUIRE(dt.years(years)    == years);
        REQUIRE(dt.timezone(timezone) == timezone);
    }

}

