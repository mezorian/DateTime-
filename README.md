# DateTime++

```
    ___      _      _____ _                            
   /   \__ _| |_ __/__   (_)_ __ ___   ___   _     _   
  / /\ / _` | __/ _ \/ /\/ | '_ ` _ \ / _ \_| |_ _| |_ 
 / /_// (_| | ||  __/ /  | | | | | | |  __/_   _|_   _|
/___,' \__,_|\__\___\/   |_|_| |_| |_|\___| |_|   |_|  
                                                       
```

DateTime++ : A easy to use c++ library for date-time calculations

[![Build Status](https://travis-ci.org/mezorian/DateTimePP.svg?branch=master)](https://travis-ci.org/mezorian/DateTimePP) 
[![Coverage Status](https://coveralls.io/repos/github/mezorian/DateTimePP/badge.svg?branch=master)](https://coveralls.io/github/mezorian/DateTimePP?branch=master)

# Features / Roadmap

## v1.0.0 General Functions working
- [x] get / set DateTime values
- [x] set DateTime values to current local time
- [x] set DateTime values to current UTC time
- [x] add compare operators == != to compare DateTimePP objects
- [ ] get current time as unix time string
- [ ] throw exceptions if unixTime is not used properly
- [ ] throw exceptions if values are used that not work in the gregorian calender

## v1.1.0 Make class canonical
- [ ] add copy-constructor
- [ ] add standard constructor
- [ ] add assignment operator = 
- [ ] add comparison operators > < 
- [ ] add comparison operators =~ =~~ =~~~

## v1.1.0 Print to console, time-zone calculations
- [ ] output datetime in different formats to string
- [ ] move DateTimeObjects into new time-zone

## v1.2.0 arithmetics with DateTimePP objects
- [ ] add or subtract DateTimePP objects
- [ ] add operators + - += -=

## v1.3.0 weekday calculation
- [ ] get weekday by date

## v2.0.0 more test-cases ensuring typical pitfalls of date-time-calculation
- [ ] ensure winter time works
- [ ] ensure leap year works
- [ ] making all functions non-gregorian-time-save

## v3.0.0
- [ ] support nseconds in time

