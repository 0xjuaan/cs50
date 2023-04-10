-- Keep a log of any SQL queries you execute as you solve the mystery.

--Finding the descriptions on the day of the crime at humphrey street
SELECT description FROM crime_scene_reports
   ...> WHERE day = 28 and month = 7
   ...> and street = 'Humphrey Street';

--Useful Output:
--Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |

--Now I'm thinking to check the bakery tapes

SELECT description FROM crime_scene_reports
   ...> WHERE day = 28 and month = 7
   ...> and street = 'Humphrey Street';