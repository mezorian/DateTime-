#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("Test if equal operator returns true and unqual operator returns false if all member variables of a DateTimePP object are equal") {
    DateTimePP dt1, dt2;

    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;

    SECTION("test if equal operator works for normal valid values") {
        nseconds = 200020;
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0;
    }

    SECTION("test if equal operator works for normal valid values") {
        nseconds = 33333;
        seconds = 30;
        minutes = 31;
        hours = 23;
        days = 28;
        months = 11;
        years = 2000;
        timezone = 1.5;
    }


    SECTION("test if equal operator works for time before christmas") {
        nseconds = 234234;
        seconds = 15;
        minutes = 58;
        hours = 22;
        days = 11;
        months = 12;
        years = -3000;
        timezone = 1.5;
    }

    REQUIRE(dt1.nseconds(nseconds) == dt2.nseconds(nseconds));
    REQUIRE(dt1.seconds(seconds)   == dt2.seconds(seconds));
    REQUIRE(dt1.minutes(minutes)   == dt2.minutes(minutes));
    REQUIRE(dt1.hours(hours)       == dt2.hours(hours));
    REQUIRE(dt1.days(days)         == dt2.days(days));
    REQUIRE(dt1.months(months)     == dt2.months(months));
    REQUIRE(dt1.years(years)       == dt2.years(years));
    REQUIRE(dt1.timezone(timezone) == dt2.timezone(timezone));
    REQUIRE(dt1 == dt2);
    REQUIRE_FALSE(dt1 != dt2);
}

TEST_CASE("Test if equal operator returns false and unqual operator returns true if at least one member variables of a DateTimePP object are unequal") {
    DateTimePP dt1, dt2;

    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;

    nseconds = 200020;
    seconds = 12;
    minutes = 23;
    hours = 4;
    days = 23;
    months = 6;
    years = 2013;
    timezone = 2.0;

    REQUIRE(dt1.nseconds(nseconds) == dt2.nseconds(nseconds));
    REQUIRE(dt1.seconds(seconds)   == dt2.seconds(seconds));
    REQUIRE(dt1.minutes(minutes)   == dt2.minutes(minutes));
    REQUIRE(dt1.hours(hours)       == dt2.hours(hours));
    REQUIRE(dt1.days(days)         == dt2.days(days));
    REQUIRE(dt1.months(months)     == dt2.months(months));
    REQUIRE(dt1.years(years)       == dt2.years(years));
    REQUIRE(dt1.timezone(timezone) == dt2.timezone(timezone));

    SECTION("test if unequal and equal compare the nseconds value") {
        dt2.nseconds(nseconds + 1);
    }

    SECTION("test if unequal and equal compare the seconds value") {
        dt2.seconds(seconds + 1);
    }

    SECTION("test if unequal and equal compare the minutes value") {
        dt2.minutes(minutes + 1);
    }

    SECTION("test if unequal and equal compare the hours value") {
        dt2.hours(hours + 1);
    }

    SECTION("test if unequal and equal compare the days value") {
        dt2.days(days + 1);
    }

    SECTION("test if unequal and equal compare the months value") {
        dt2.months(months + 1);
    }

    SECTION("test if unequal and equal compare the years value") {
        dt2.years(years + 1);
    }

    SECTION("test if unequal and equal compare the timezone value") {
        dt2.timezone(timezone + 1.0);
    }

    REQUIRE_FALSE(dt1 == dt2);
    REQUIRE(dt1 != dt2);
}
