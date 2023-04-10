-- Keep a log of any SQL queries you execute as you solve the mystery.

--Finding the descriptions on the day of the crime at humphrey street

SELECT description FROM crime_scene_reports
   ...> WHERE day = 28 and month = 7
   ...> and street = 'Humphrey Street';