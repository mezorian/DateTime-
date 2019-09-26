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
    REQUIRE(dt.months() == ctime->tm_mon);
    REQUIRE(dt.years() == ctime->tm_year);
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
    REQUIRE(dt.months() == ctime->tm_mon);
    REQUIRE(dt.years() == ctime->tm_year);
    REQUIRE(dt.timezone() == ctime->tm_gmtoff);
}

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

TEST_CASE("Test if unix-time conversion is working") {
    DateTimePP dt;
    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;
    int unixTime = 0;

    SECTION("test if unixTime works for normal valid values") {
        nseconds = 0; // not relevant
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0; // not relevant
        unixTime = 1415247792;
    }

    SECTION("test if unixTime for normal valid values") {
        nseconds = 0; // not relevant
        seconds = 30;
        minutes = 31;
        hours = 23;
        days = 28;
        months = 11;
        years = 2000;
        timezone = 1.5; // not relevant
        unixTime = 1018567890;
    }


/*    SECTION("test if unixTime works for time before christmas") {
        nseconds = 0; // not relevant
        seconds = 15;
        minutes = 58;
        hours = 22;
        days = 11;
        months = 12;
        years = -3000;
        timezone = 1.5; // not relevant
        unixTime =
    }*/

    SECTION("test if unixTime works for beginning of unix epoch") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 1;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 0;
    }

    SECTION("test if unixTime works for before the beginning of unix epoch") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 1;
        days = 1;
        months = 1;
        years = 1960;
        timezone = 0; // not relevant
        unixTime = -315619200;
    }

    SECTION("test if unixTime works for biggest possible 32 bit time : 19. January 2038, 4:14:08") {
        nseconds = 0; // not relevant
        seconds = 8;
        minutes = 14;
        hours = 4;
        days = 19;
        months = 1;
        years = 2038;
        timezone = 0; // not relevant
        unixTime = 2147483648;
    }

    SECTION("test if unixTime works for times bigger than storable with 32 bit : 19. January 2038, 4:14:09") {
        nseconds = 0; // not relevant
        seconds = 9;
        minutes = 14;
        hours = 4;
        days = 19;
        months = 1;
        years = 2038;
        timezone = 0; // not relevant
        unixTime = 2147483649;
    }

    SECTION("test if unixTime works for times much bigger than storable with 32 bit : 1. January 3000, 1:00:00") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 1;
        days = 1;
        months = 1;
        years = 3000;
        timezone = 0; // not relevant
        unixTime = 32503680000;
    }

    SECTION("test if unixTime works for smallest possible 32 bit time : 13. December 1901, 20:45:52 ") {
        nseconds = 0; // not relevant
        seconds = 52;
        minutes = 45;
        hours = 20;
        days = 13;
        months = 12;
        years = 1901;
        timezone = 0; // not relevant
        unixTime = -2147487248;
    }

    SECTION("test if unixTime works for times smaller than storable with 32 bit : 13. December 1901, 20:45:51 ") {
        nseconds = 0; // not relevant
        seconds = 51;
        minutes = 45;
        hours = 20;
        days = 13;
        months = 12;
        years = 1901;
        timezone = 0; // not relevant
        unixTime = -2147487249;
    }

    SECTION("test if unixTime works for times much smaller than storable with 32 bit : January 11, 1000 11:11:11") {
        nseconds = 0; // not relevant
        seconds = 11;
        minutes = 11;
        hours = 11;
        days = 11;
        months = 11;
        years = 1111;
        timezone = 0; // not relevant
        unixTime = -27080311729;
    }

    REQUIRE(dt.nseconds(nseconds) == nseconds);
    REQUIRE(dt.seconds(seconds)   == seconds);
    REQUIRE(dt.minutes(minutes)   == minutes);
    REQUIRE(dt.hours(hours)       == hours);
    REQUIRE(dt.days(days)         == days);
    REQUIRE(dt.months(months)     == months);
    REQUIRE(dt.years(years)       == years);
    REQUIRE(dt.timezone(timezone) == timezone);

    REQUIRE(dt.unixTime() == unixTime);
}
