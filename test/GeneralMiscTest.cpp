/**
 * GeneralMiscTest.cpp
 * Purpose: implements tests for the general miscellaneous functions of class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("Test if toString without parameter returns a correctly formatted string") {
    DateTimePP dt;
    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;
    std::string expectedOutput;

    SECTION("test if toString without parameter works for normal valid values") {
        nseconds = 200020; // not relevant
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0; // not relevant
        expectedOutput = "2013-06-23T04:23:12Z";
    }

    SECTION("test toString without parameter works for normal valid values") {
        nseconds = 33333; // not relevant
        seconds = 30;
        minutes = 31;
        hours = 23;
        days = 28;
        months = 11;
        years = 2000;
        timezone = 1.5; // not relevant
        expectedOutput = "2000-11-28T23:31:30Z";
    }

    SECTION("test if toString without parameter works for time before christmas") {
        nseconds = 234234; // not relevant
        seconds = 15;
        minutes = 58;
        hours = 22;
        days = 11;
        months = 12;
        years = -3000;
        timezone = 1.5; // not relevant
        expectedOutput = "-3000-12-11T22:58:15Z";
    }

    REQUIRE(dt.nseconds(nseconds) == nseconds);
    REQUIRE(dt.seconds(seconds)   == seconds);
    REQUIRE(dt.minutes(minutes)   == minutes);
    REQUIRE(dt.hours(hours)       == hours);
    REQUIRE(dt.days(days)         == days);
    REQUIRE(dt.months(months)     == months);
    REQUIRE(dt.years(years)       == years);
    REQUIRE(dt.timezone(timezone) == timezone);
    REQUIRE(dt.toString() == expectedOutput);

}
