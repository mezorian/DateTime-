/**
 * ArithmeticsTest.cpp
 * Purpose: implements tests for the arithmetic functions of class DateTimePP
 *
 * @author mezorian
 * @version 1.0.0
 */

#include "catch.hpp"
#include "DateTimePP.h"

TEST_CASE("test if numberOfDaysBetweenTwoDates is returning the correct number of days") {
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

    SECTION("test if numberOfDaysBetweenTwoDates with 5 days difference returns 5") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 6;
        month2 = 1;
        year2 = 1970;

        numberOfDays = 5;
    }

    SECTION("test if numberOfDaysBetweenTwoDates with 5 days difference returns 5") {
        day1 = 24;
        month1 = 12;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 5;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a normal year") {
        day1 = 14;
        month1 = 5;
        year1 = 2001;

        day2 = 2;
        month2 = 6;
        year2 = 2001;

        numberOfDays = 19;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a normal year") {
        day1 = 1;
        month1 = 1;
        year1 = 1970;

        day2 = 2;
        month2 = 2;
        year2 = 1970;

        numberOfDays = 32;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a normal year") {
        day1 = 24;
        month1 = 11;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 35;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a normal year") {
        day1 = 24;
        month1 = 10;
        year1 = 2015;

        day2 = 29;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 66;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a normal year") {
        day1 = 5;
        month1 = 4;
        year1 = 2001;

        day2 = 29;
        month2 = 7;
        year2 = 2001;

        numberOfDays = 115;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a normal year") {
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

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of february in a leap year") {
        day1 = 27;
        month1 = 2;
        year1 = 1972;

        day2 = 25;
        month2 = 3;
        year2 = 1972;

        numberOfDays = 27;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a leap year") {
        day1 = 14;
        month1 = 5;
        year1 = 2000;

        day2 = 2;
        month2 = 6;
        year2 = 2000;

        numberOfDays = 19;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a leap year") {
        day1 = 1;
        month1 = 1;
        year1 = 1972;

        day2 = 2;
        month2 = 2;
        year2 = 1972;

        numberOfDays = 32;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of the month in a normal year") {
        day1 = 24;
        month1 = 11;
        year1 = 2016;

        day2 = 29;
        month2 = 12;
        year2 = 2016;

        numberOfDays = 35;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 24;
        month1 = 10;
        year1 = 2132;

        day2 = 29;
        month2 = 12;
        year2 = 2132;

        numberOfDays = 66;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 5;
        month1 = 4;
        year1 = 2000;

        day2 = 29;
        month2 = 7;
        year2 = 2000;

        numberOfDays = 115;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 16;
        month1 = 3;
        year1 = 2180;

        day2 = 29;
        month2 = 12;
        year2 = 2180;

        numberOfDays = 288;
    }

    // -

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 24;
        month1 = 1;
        year1 = 2132;

        day2 = 29;
        month2 = 3;
        year2 = 2132;

        numberOfDays = 65;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 5;
        month1 = 2;
        year1 = 2000;

        day2 = 29;
        month2 = 7;
        year2 = 2000;

        numberOfDays = 175;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of more than one month in a leap year") {
        day1 = 16;
        month1 = 2;
        year1 = 2180;

        day2 = 30;
        month2 = 12;
        year2 = 2180;

        numberOfDays = 318;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole normal year") {
        day1 = 31;
        month1 = 12;
        year1 = 2180;

        day2 = 31;
        month2 = 12;
        year2 = 2181;

        numberOfDays = 365;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole normal year") {
        day1 = 31;
        month1 = 12;
        year1 = 1960;

        day2 = 31;
        month2 = 12;
        year2 = 1961;

        numberOfDays = 365;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole normal year") {
        day1 = 31;
        month1 = 12;
        year1 = 2000;

        day2 = 31;
        month2 = 12;
        year2 = 2001;

        numberOfDays = 365;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole normal year") {
        day1 = 31;
        month1 = 12;
        year1 = 2018;

        day2 = 31;
        month2 = 12;
        year2 = 2019;

        numberOfDays = 365;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole normal year") {
        day1 = 31;
        month1 = 12;
        year1 = 2180;

        day2 = 31;
        month2 = 12;
        year2 = 2181;

        numberOfDays = 365;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole leap year") {
        day1 = 31;
        month1 = 12;
        year1 = 1959;

        day2 = 31;
        month2 = 12;
        year2 = 1960;

        numberOfDays = 366;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole leap year") {
        day1 = 31;
        month1 = 12;
        year1 = 1999;

        day2 = 31;
        month2 = 12;
        year2 = 2000;

        numberOfDays = 366;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works for a whole leap year") {
        day1 = 31;
        month1 = 12;
        year1 = 2019;

        day2 = 31;
        month2 = 12;
        year2 = 2020;

        numberOfDays = 366;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 3;
        month1 = 10;
        year1 = 2014;

        day2 = 31;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 454;
    }


    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 15;
        month1 = 7;
        year1 = 1974;

        day2 = 20;
        month2 = 10;
        year2 = 1975;

        numberOfDays = 462;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 31;
        month1 = 10;
        year1 = 2049;

        day2 = 3;
        month2 = 10;
        year2 = 2050;

        numberOfDays = 337;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 3;
        month1 = 10;
        year1 = 2015;

        day2 = 31;
        month2 = 12;
        year2 = 2016;

        numberOfDays = 455;
    }


    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 15;
        month1 = 7;
        year1 = 1975;

        day2 = 20;
        month2 = 10;
        year2 = 1976;

        numberOfDays = 463;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 31;
        month1 = 10;
        year1 = 2047;

        day2 = 3;
        month2 = 10;
        year2 = 2048;

        numberOfDays = 338;
    }

    // -

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 3;
        month1 = 10;
        year1 = 2013;

        day2 = 31;
        month2 = 12;
        year2 = 2015;

        numberOfDays = 819;
    }


    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 15;
        month1 = 7;
        year1 = 1972;

        day2 = 20;
        month2 = 10;
        year2 = 1975;

        numberOfDays = 1192;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a normal year") {
        day1 = 31;
        month1 = 10;
        year1 = 2049;

        day2 = 3;
        month2 = 10;
        year2 = 2051;

        numberOfDays = 702;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 3;
        month1 = 10;
        year1 = 2015;

        day2 = 31;
        month2 = 12;
        year2 = 2019;

        numberOfDays = 1550;
    }


    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 15;
        month1 = 7;
        year1 = 1975;

        day2 = 20;
        month2 = 10;
        year2 = 1979;

        numberOfDays = 1558;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of a leap year") {
        day1 = 30;
        month1 = 4;
        year1 = 2047;

        day2 = 3;
        month2 = 12;
        year2 = 2050;

        numberOfDays = 1313;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of multiple years") {
        day1 = 3;
        month1 = 10;
        year1 = 2000;

        day2 = 31;
        month2 = 12;
        year2 = 2050;

        numberOfDays = 18351;
    }


    SECTION("test if numberOfDaysBetweenTwoDates works over the end of multiple years") {
        day1 = 15;
        month1 = 7;
        year1 = 1975;

        day2 = 20;
        month2 = 10;
        year2 = 2019;

        numberOfDays = 16168;
    }

    SECTION("test if numberOfDaysBetweenTwoDates works over the end of multiple years") {
        day1 = 30;
        month1 = 4;
        year1 = 1647;

        day2 = 7;
        month2 = 10;
        year2 = 3019;

        numberOfDays = 501272;
    }


    dt1.days(day1);
    dt1.months(month1);
    dt1.years(year1);

    dt2.days(day2);
    dt2.months(month2);
    dt2.years(year2);

    REQUIRE(dt.numberOfDaysBetweenTwoDates(dt1,dt2) == numberOfDays);
}

TEST_CASE("test if numberOfDaysBetweenTwoDates throws an exception for years < 1582") {
    DateTimePP dt1,dt2;
    int year=0;
    bool willThrowException=false;

    SECTION("test with years negative years") {
        year = -1;
        willThrowException = true;
    }

    SECTION("test with years negative years") {
        year = -14;
        willThrowException = true;
    }

    SECTION("test with years negative years") {
        year = -2000;
        willThrowException = true;
    }

    SECTION("test with years before 1582") {
        year = 0;
        willThrowException = true;
    }

    SECTION("test with years before 1582") {
        year = 3;
        willThrowException = true;
    }

    SECTION("test with years before 1582") {
        year = 400;
        willThrowException = true;
    }

    SECTION("test with years before 1582") {
        year = 1000;
        willThrowException = true;
    }

    SECTION("test with years before 1582") {
        year = 1581;
        willThrowException = true;
    }

    SECTION("test year 1582") {
        year = 1582;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 1583;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 1590;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 1600;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 1811;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 2000;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 2583;
        willThrowException = false;
    }

    SECTION("test with years after 1582") {
        year = 5583;
        willThrowException = false;
    }

    dt1.years(year);
    dt2.years(year);

    if (willThrowException) {
        REQUIRE_THROWS(dt1.numberOfDaysBetweenTwoDates(dt1,dt2));
    } else {
        REQUIRE_NOTHROW(dt1.numberOfDaysBetweenTwoDates(dt1,dt2));
    }

}

TEST_CASE("test if numberOfDaysBetweenTwoDates throws an exception if dt1 > dt2") {
    DateTimePP dt1,dt2;
    int year1=0, year2=0;
    bool willThrowException=false;

    SECTION("test with years in wrong order") {
        year1 = 2600;
        year2 = 2500;
        willThrowException = true;
    }

    SECTION("test with years in wrong order") {
        year1 = 2015;
        year2 = 2014;
        willThrowException = true;
    }

    SECTION("test with years in wrong order") {
        year1 = 2000;
        year2 = 1995;
        willThrowException = true;
    }

    SECTION("test with years in wrong order") {
        year1 = 1601;
        year2 = 1589;
        willThrowException = true;
    }

    dt1.years(year1);
    dt2.years(year2);

    REQUIRE_THROWS(dt1.numberOfDaysBetweenTwoDates(dt1,dt2));
    REQUIRE_NOTHROW(dt1.numberOfDaysBetweenTwoDates(dt2,dt1));

}

TEST_CASE("test if 'date is equal, but time not returns 1'-bug is not occuring") {
    DateTimePP dt,dt1,dt2;

    int nseconds = 10000;
    int seconds = 20;
    int minutes = 46;
    int hours = 6;
    int days = 15;
    int months = 5;
    int years = 2001;

    dt1.nseconds(nseconds);
    dt1.seconds(seconds);
    dt1.minutes(minutes);
    dt1.hours(hours);
    dt1.days(days);
    dt1.months(months);
    dt1.years(years);

    dt2 = dt1;

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in nseconds") {
        dt2.nseconds(nseconds+1);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in nseconds") {
        dt2.nseconds(nseconds+5);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in nseconds") {
        dt2.nseconds(nseconds+10);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in seconds") {
        dt2.seconds(seconds+1);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in seconds") {
        dt2.seconds(seconds+5);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in seconds") {
        dt2.seconds(seconds+10);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in minutes") {
        dt2.minutes(minutes+1);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in minutes") {
        dt2.minutes(minutes+5);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in minutes") {
        dt2.minutes(minutes+10);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in hours") {
        dt2.hours(hours+1);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in hours") {
        dt2.hours(hours+5);
    }

    SECTION("test if numberOfDaysBetweenTwoDates with same date returns 0 for changes in hours") {
        dt2.hours(hours+10);
    }

    REQUIRE(dt.numberOfDaysBetweenTwoDates(dt1,dt2) == 0);
}
