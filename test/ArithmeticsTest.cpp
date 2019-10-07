#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("bal") {
    DateTimePP dt,dt1,dt2;
    int month1, year1, day1, month2, year2, day2, numberOfDays;

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0") {
        day1 = 15;
        month1 = 5;
        year1 = 2001;

        day2 = 15;
        month2 = 5;
        year2 = 2001;

        numberOfDays = 0;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 1;
        month2 = 1;
        year2 = 1970;

        numberOfDays = 0;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0") {
        day1 = 25;
        month1 = 12;
        year1 = 2015;

        day2 = 25;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 0;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with one day difference returns 1") {
        day1 = 14;
        month1 = 5;
        year1 = 2001;

        day2 = 15;
        month2 = 5;
        year2 = 2001;

        numberOfDays = 1;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with one day difference returns 1") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 2;
        month2 = 1;
        year2 = 1970;

        numberOfDays = 1;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with one day difference returns 1") {
        day1 = 24;
        month1 = 12;
        year1 = 2015;

        day2 = 25;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 1;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with five days difference returns 5") {
        day1 = 14;
        month1 = 5;
        year1 = 2001;

        day2 = 19;
        month2 = 5;
        year2 = 2001;

        numberOfDays = 5;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with one day difference returns 5") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 6;
        month2 = 1;
        year2 = 1970;

        numberOfDays = 5;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with one day difference returns 5") {
        day1 = 24;
        month1 = 12;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 5;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month") {
        day1 = 14;
        month1 = 5;
        year1 = 2001;

        day2 = 2;
        month2 = 6;
        year2 = 2001;

        numberOfDays = 19;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 2;
        month2 = 2;
        year2 = 1970;

        numberOfDays = 32;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month") {
        day1 = 24;
        month1 = 11;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 35;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month") {
        day1 = 24;
        month1 = 10;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 66;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month") {
        day1 = 5;
        month1 = 4;
        year1 = 2001;

        day2 = 29;
        month2 = 7;
        year2 = 2001;

        numberOfDays = 115;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month") {
        day1 = 16;
        month1 = 3;
        year1 = 2001;

        day2 = 29;
        month2 = 12;
        year2 = 2001;

        numberOfDays = 288;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of february in a normal year") {
        day1 = 16;
        month1 = 2;
        year1 = 2003;

        day2 = 29;
        month2 = 3;
        year2 = 2003;

        numberOfDays = 41;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of february in a normal year") {
        day1 = 28;
        month1 = 2;
        year1 = 2005;

        day2 = 1;
        month2 = 3;
        year2 = 2005;

        numberOfDays = 1;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of february in a leap year") {
        day1 = 16;
        month1 = 2;
        year1 = 2000;

        day2 = 29;
        month2 = 3;
        year2 = 2000;

        numberOfDays = 42;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of february in a leap year") {
        day1 = 28;
        month1 = 2;
        year1 = 2060;

        day2 = 1;
        month2 = 3;
        year2 = 2060;

        numberOfDays = 2;
    }

    dt1.days(day1);
    dt1.months(month1);
    dt1.years(year1);

    dt2.days(day2);
    dt2.months(month2);
    dt2.years(year2);

    REQUIRE(dt.numberOfDaysBetweenTwoDates(dt1,dt2) == numberOfDays);
}
