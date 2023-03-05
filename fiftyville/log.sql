-- Keep a log of any SQL queries you execute as you solve the mystery.

--My idea: Intersect all people who (WENT ON PLANE-CALLED ON PHONE-USED ATM)- ALL AFTER THE CRIME

 --Finding list of cities
SELECT city FROM airports;

 --Finding Fiftyville airport id: it's 8
SELECT id FROM airports WHERE city = 'Fiftyville';

--Getting flights from Fiftyville after the incident (in chronological order)
SELECT * FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute;

--IF WANTING JUST FLIGHT ID
SELECT id FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute;


--Passport number of everyone from the above flights
SELECT DISTINCT(passport_number) FROM passengers
    WHERE flight_id IN (
    SELECT id FROM flights
    WHERE origin_airport_id = 8
    AND year = 2021
    AND month = 7
    AND day >=28
    ORDER BY day, hour, minute);

--Their phone numbers (departees)
SELECT phone_number FROM people WHERE passport_number IN (
SELECT DISTINCT(passport_number) FROM passengers WHERE flight_id IN (SELECT id FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute));

--
--
-- # GETTING DEEPER NOW
--
--

--Passport number of all callers after event
SELECT passport_number FROM people WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE year = 2021
AND month = 7
AND day >=28)

INTERSECT --with passport numbers of all departees' after the event

SELECT DISTINCT(passport_number) FROM passengers WHERE flight_id IN (SELECT id FROM flights
WHERE origin_airport_id = 8
AND year = 2021
AND month = 7
AND day >=28
ORDER BY day, hour, minute);

INTERSECT

SELECT caller FROM phone_calls
WHERE ID in (

SELECT id FROM JOIN phone_calls on phone_calls.caller = people.phone_number
WHERE 

)



