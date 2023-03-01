-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT city FROM airports; --Finding list of cities

SELECT id FROM airports WHERE city = 'Fiftyville'; --Finding Fiftyville id: 8

--Getting flights from Fiftyville after the incident (in chronological order)

SELECT * FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute;

--IF WANTING JUST ID
SELECT id FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute;


--Passport number of everyone from the above flights
SELECT DISTINCT(passport_number) FROM passengers WHERE flight_id IN (SELECT id FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute);

