#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("Test if DatetimePP points to 01.01.00 0:0:0") {
    DateTimePP dt;
    REQUIRE(dt.nseconds()  == 0);
    REQUIRE(dt.seconds()   == 0);
    REQUIRE(dt.seconds()   == 0);
    REQUIRE(dt.minutes()   == 0);
    REQUIRE(dt.hours()     == 0);
    REQUIRE(dt.days()      == 1);
    REQUIRE(dt.months()    == 1);
    REQUIRE(dt.years()     == 0);
    REQUIRE(dt.timezone()  == 0.0);
}

TEST_CASE("Test if get returns the previously set value") {
    DateTimePP dt;
    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;

    SECTION("test if get and set works for normal valid values") {
        nseconds = 200020;
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0;
    }

    SECTION("test if get and set works for normal valid values") {
        nseconds = 33333;
        seconds = 30;
        minutes = 31;
        hours = 23;
        days = 28;
        months = 11;
        years = 2000;
        timezone = 1.5;
    }


    SECTION("test if get and set works for time before christmas") {
        nseconds = 234234;
        seconds = 15;
        minutes = 58;
        hours = 22;
        days = 11;
        months = 12;
        years = -3000;
        timezone = 1.5;
    }

    REQUIRE(dt.nseconds(nseconds) == nseconds);
    REQUIRE(dt.seconds(seconds)   == seconds);
    REQUIRE(dt.minutes(minutes)   == minutes);
    REQUIRE(dt.hours(hours)       == hours);
    REQUIRE(dt.days(days)         == days);
    REQUIRE(dt.months(months)     == months);
    REQUIRE(dt.years(years)       == years);
    REQUIRE(dt.timezone(timezone) == timezone);

}
