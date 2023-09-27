-- Keep a log of any SQL queries you execute as you solve the mystery.
-- lets see the crime scene on the theft day first
 SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28;
 --We found out that the robbery had 3 witnesses, so we take a look at the testimonies on that day
 SELECT * FROM interviews WHERE month = 7 AND day = 28;
 --I checked the interviews and only IDs 161, 162 and 163 were related to the bakery.
--I found some important points that will help to find the thief
--1- The thief got into the car 10 minutes after the robbery and the camera recorded it
--2- The thief took money early in the morning
--3- Shortly after the robbery, the thief made a missed call for less than a minute
--4- The first ticket the next day was bought by the thief's colleague from fiftyville
--So my conclusion is as follows
--I will try to find the thief by checking the camera and understanding the car 
--I will try to find the thief by sharing the money withdrawal early in the morning and the phone call after the robbery, and his colleague will be the buyer of the first ticket on 7/29, and I will find the destination and the case will be solved.

SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw";
--account_number that i should found names
SELECT name FROM people JOIN bank_accounts ON people.id = bank_accounts.person_id WHERE bank_accounts.account_number = (SELECT account_number FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = "Leggett Street" AND transaction_type = "withdraw");
--28500762 -> Luca
--28296815 -> Kenny
--76054385 -> Taylor
--49610011 -> Bruce
--25506511 -> Iman
--81061156 -> Benista
--26013199 -> Diana
SELECT * FROM phone_calls WHERE year = 2021 AND month = 7 AND day =28 AND duration < 60;
--now find out names
SELECT name FROM people WHERE phone_number = SELECT caller FROM phone_calls WHERE year = 2021 AND month = 7 AND day =28 AND duration < 60;
--Kelsey
--Sofia
--Bruce
--Kelsey
--Taylor
--Diana
--Carina
--Kenny
--Benista



--so there are 3 suspects
--Bruce
--Kenny
--Taylor

SELECT  license_plate FROM bakery_security_logs WHERE  year=2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >19 AND minute <36)
--lets check bakery_security_logs 
SELECT * FROM bakery_security_logs WHERE year=2021 AND month = 7 AND day = 28 AND hour = 10;
--based on information about time of robbery only these case is suspects
--theft -> 10:15    interviwe sead car get out by 10 minute after -> 10:25
--write this code to find names
SELECT name FROM people WHERE  license_plate = (SELECT  license_plate FROM bakery_security_logs WHERE  year=2021 AND month = 7 AND day = 28 AND hour = 10 AND minute >19 AND minute <36);
--264 | 2021 | 7 | 28 | 10 | 20 | exit | G412CB7 -> Sofia
--265 | 2021 | 7 | 28 | 10 | 21 | exit | L93JTIZ -> Iman
--266 | 2021 | 7 | 28 | 10 | 23 | exit | 322W7JE -> Diana
--267 | 2021 | 7 | 28 | 10 | 23 | exit | 0NTHK55 _> Kelsey
--268 | 2021 | 7 | 28 | 10 | 35 | exit | 1106N58 -> Bruce

--so WE FOUND IT

--Bruce






-- lets go for planes
-- find fiftyville code
SELECT * FROM airports;
--code is 8
SELECT * FROM flights WHERE year = 2021 AND day = 29 AND month = 7 AND origin_airport_id = 8;
--flights is :
-- id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
-- 18 | 8 | 6 | 2021 | 7 | 29 | 16 | 0
-- 23 | 8 | 11 | 2021 | 7 | 29 | 12 | 15
-- 53 | 8 | 9 | 2021 | 7 | 29 | 15 | 20
-- 43 | 8 | 1 | 2021 | 7 | 29 | 9 | 30
-- 36 | 8 | 4 | 2021 | 7 | 29 | 8 | 20

-- we go for first flight of day ID -> 36


 SELECT name FROM people WHERE  passport_number = (SELECT  passport_number FROM passengers JOIN flights ON passengers.flight_id = flights.id WHERE flights.id = 36);

-- ID = 36 ->  New York City :
-- Doris
-- Sofia
-- Bruce
-- Edward
-- Kelsey
-- Taylor
-- Kenny
-- Luca


-- ITS MUST BE Taylor FOR SURE
--Bruce



--Lets check phone number of receiver for Tylor call
--233 | (367) 555-5533 | (375) 555-8161 | 2021 | 7 | 28 | 45
SELECT name FROM people WHERE phone_number = "(375) 555-8161"
--receiver is Robin



-- 1-> Bruce
-- 2-> New York City
-- 3-> Robin


--Yousof.A.Asadi(Y.A.A)5/22/2023


