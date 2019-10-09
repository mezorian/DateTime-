#include "catch.hpp"
#include "DateTimePP.h"
#include <chrono>
#include <thread>

TEST_CASE("Test if unix-time conversion is working") {
    DateTimePP dt;
    int nseconds=0, seconds=0, minutes=0, hours=0, days=0, months=0, years=0;
    double timezone=0.0;
    long unixTime = 0;

    SECTION("test if unixTime works for normal valid values") {
        nseconds = 0; // not relevant
        seconds = 12;
        minutes = 23;
        hours = 4;
        days = 23;
        months = 6;
        years = 2013;
        timezone = 2.0; // not relevant
        unixTime = 1371961392;
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
        unixTime = 975454290;
    }

    SECTION("test if unixTime works for beginning of unix epoch") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 0;
    }

    SECTION("test if unixTime works for counting seconds") {
        nseconds = 0; // not relevant
        seconds = 1;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 1;
    }

    SECTION("test if unixTime works for counting seconds") {
        nseconds = 0; // not relevant
        seconds = 5;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 5;
    }

    SECTION("test if unixTime works for counting seconds") {
        nseconds = 0; // not relevant
        seconds = 59;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 59;
    }

    SECTION("test if unixTime works for counting minutes") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 1;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 60;
    }

    SECTION("test if unixTime works for counting minutes") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 5;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 300;
    }

    SECTION("test if unixTime works for counting minutes") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 59;
        hours = 0;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 3540;
    }

    SECTION("test if unixTime works for counting hours") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 1;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 3600;
    }

    SECTION("test if unixTime works for counting hours") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 5;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 18000;
    }

    SECTION("test if unixTime works for counting hours") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 23;
        days = 1;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 82800;
    }

    SECTION("test if unixTime works for counting days") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 2;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 86400;
    }

    SECTION("test if unixTime works for counting days") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 6;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 432000;
    }

    SECTION("test if unixTime works for counting days") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 31;
        months = 1;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 2592000;
    }

    SECTION("test if unixTime works for counting months") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 2;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 2678400;
    }

    SECTION("test if unixTime works for counting months") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 6;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 13046400;
    }

    SECTION("test if unixTime works for counting months") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 10;
        years = 1970;
        timezone = 0; // not relevant
        unixTime = 23587200;
    }

    SECTION("test if unixTime works for counting years") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1971;
        timezone = 0; // not relevant
        unixTime = 31536000;
    }

    SECTION("test if unixTime works for counting years") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1975;
        timezone = 0; // not relevant
        unixTime = 157766400;
    }

    SECTION("test if unixTime works for counting years") {
        nseconds = 0; // not relevant
        seconds = 0;
        minutes = 0;
        hours = 0;
        days = 1;
        months = 1;
        years = 1980;
        timezone = 0; // not relevant
        unixTime = 315532800;
    }

/*
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
    } */

    SECTION("test if unixTime works for biggest possible 32 bit time : 19. January 2038, 3:14:08") {
        nseconds = 0; // not relevant
        seconds = 8;
        minutes = 14;
        hours = 3;
        days = 19;
        months = 1;
        years = 2038;
        timezone = 0; // not relevant
        unixTime = 2147483648;
    }

    SECTION("test if unixTime works for times bigger than storable with 32 bit : 19. January 2038, 3:14:09") {
        nseconds = 0; // not relevant
        seconds = 9;
        minutes = 14;
        hours = 3;
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
        unixTime = 32503683600;
    }
/*
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
    } */

    REQUIRE(dt.nseconds(nseconds) == nseconds);
    REQUIRE(dt.seconds(seconds)   == seconds);
    REQUIRE(dt.minutes(minutes)   == minutes);
    REQUIRE(dt.hours(hours)       == hours);
    REQUIRE(dt.days(days)         == days);
    REQUIRE(dt.months(months)     == months);
    REQUIRE(dt.years(years)       == years);
    REQUIRE(dt.timezone(timezone) == timezone);

    REQUIRE(dt.toUnixTime() == unixTime);
}



/*
SECTION("test if unixTime works for time before christmas") {
    nseconds = 0; // not relevant
    seconds = 15;
    minutes = 58;
    hours = 22;
    days = 11;
    months = 12;
    years = -3000;
    timezone = 1.5; // not relevant
    unixTime =
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

 */

TEST_CASE("Test if toUnixTime returns the same time then calculated by the std libraries") {
    DateTimePP dt;

    SECTION("don't wait") {

    }

    SECTION("wait 1 second") {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    SECTION("wait 1 second") {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    SECTION("wait 1 second") {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    std::time_t result = std::time(nullptr);
    std::localtime(&result);
    long resultLong = result;
    REQUIRE(dt.now(true).toUnixTime() == resultLong);


}
