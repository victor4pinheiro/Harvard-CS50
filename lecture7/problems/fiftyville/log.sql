-- Get data of crimes reported at July 28, 2022
SELECT description
FROM crime_scene_reports
WHERE year = 2021
    AND month = 7
    AND day = 28;
-- Get interviews from local
SELECT name,
    transcript
FROM interviews
WHERE year = 2021
    AND month = 7
    AND day = 28
    AND transcript LIKE "%bakery%";
-- Get suspects plates
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021
    AND month = 7
    AND day = 28
    AND hour = 10
    AND minute >= 15
    AND activity = "exit";
-- List withdrawals of the day
SELECT account_number
FROM atm_transactions
WHERE year = 2021
    AND month = 7
    AND day = 28
    AND atm_location LIKE "Leggett Street"
    AND transaction_type = "withdraw";
-- Get the accounts suspected
SELECT person_id,
    creation_year,
    atm_transactions.id
FROM bank_accounts
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = "Leggett Street"
    and atm_transactions.transaction_type = "withdraw";
-- Get the calls of the day
SELECT caller,
    receiver,
    duration
FROM phone_calls
WHERE year = 2021
    AND month = 7
    AND day = 28
    AND duration < 60;
-- Get the passport number
SELECT passport_number,
    seat
FROm passengers
WHERE flight_id = (
        SELECT flights.id
        FROM flights
            JOIN airports ON flights.origin_airport_id = airports.id
        WHERE airports.city = "Fiftyville"
            AND flights.year = 2021
            AND flights.day = 29
            AND flights.month = 7
            AND flights.hour < 12
        ORDER BY flights.hour
        LIMIT 1
    );
-- Get the destiny
SELECT city
FROM airports
    JOIN flights ON airports.id = flights.destination_airport_id
WHERE flights.origin_airport_id = (
        SELECT id
        FROM airports
        WHERE city = 'Fiftyville'
    )
    AND flights.year = 2021
    AND flights.day = 29
    AND flights.month = 7
ORDER BY flights.hour,
    flights.minute
LIMIT 1;
-- Get the thief
SELECT name
FROM people
    JOIN phone_calls ON phone_calls.caller = people.phone_number
    JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
    JOIN passengers ON people.passport_number = passengers.passport_number
    JOIN flights ON passengers.flight_id = flights.id
    JOIN airports ON airports.id = flights.origin_airport_id
    JOIN bank_accounts ON bank_accounts.person_id = people.id
    JOIN atm_transactions ON atm_transactions.account_number = bank_accounts.account_number
WHERE phone_calls.year = 2021
    AND phone_calls.day = 28
    AND phone_calls.month = 7
    AND phone_calls.duration <= 60
    AND bakery_security_logs.year = 2021
    AND bakery_security_logs.day = 28
    AND bakery_security_logs.month = 7
    AND bakery_security_logs.hour = 10
    AND bakery_security_logs.minute >= 15
    AND bakery_security_logs.activity = "exit"
    AND airports.city = "Fiftyville"
    AND atm_transactions.year = 2021
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND atm_transactions.atm_location = 'Leggett Street'
    AND atm_transactions.transaction_type = 'withdraw'
ORDER BY flights.hour,
    flights.minute;
-- During this SELECT, Bruce is on top of the list, so he is the suspect. Knowing the name, just get the number and check who is the receiver.
-- Get the accomplice
SELECT name
FROM people
WHERE phone_number in (
        SELECT receiver
        FROM phone_calls
        WHERE caller IN (
                SELECT phone_number
                FROM people
                WHERE name = "Bruce"
            )
            AND year = 2021
            AND month = 7
            AND day = 28
            AND duration < 60
    )