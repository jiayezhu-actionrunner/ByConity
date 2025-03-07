SELECT MAKETIME(10,30,45);
SELECT MAKETIME(00,22,34);
SELECT MAKETIME(01,77,88);
SELECT MAKETIME('12','45','32');
SELECT MAKETIME(25,45,30);
SELECT SEC_TO_TIME(4500);
SELECT SEC_TO_TIME('3600');
SELECT SEC_TO_TIME(86400);
SELECT SEC_TO_TIME(86401);
SELECT SEC_TO_TIME(-86401);

SELECT TIME_TO_SEC('10:45:30');
SELECT TIME_TO_SEC('2023-05-21 10:30:00');
SELECT TIME_TO_SEC('2023-05-21 15:10:00.123456'::DATETIME(6));
SELECT TIME_TO_SEC('2023-05-21');
SELECT TIME_TO_SEC('12:30:15');

SELECT TIME_TO_SEC(TIME'10:45:30');
SELECT TIME_TO_SEC(DATETIME'2023-05-21 10:30:00');
SELECT TIME_TO_SEC(DATE'2023-05-21');

use test;
DROP TABLE IF EXISTS test.time_to_sec_table;
CREATE TABLE test.time_to_sec_table
(
    val1 UInt64, 
    val2 TIME,
    val3 DATE,
    val4 DATETIME,
    val5 UInt64,
    val6 UInt64
) ENGINE=CnchMergeTree() ORDER BY val1;

INSERT INTO test.time_to_sec_table VALUES(0, '01:02:03', '2022-01-01', '2022-01-01 00:00:00', 22, 34);
INSERT INTO test.time_to_sec_table VALUES(1, '23:02:03', '2022-01-01', '2022-12-31 23:00:00', 57, 58);
INSERT INTO test.time_to_sec_table VALUES(2, '23:02:03', '2022-01-01', '2022-01-01 00:00:00', 12, 00);
SELECT val1, TIME_TO_SEC(val2), SEC_TO_TIME(TIME_TO_SEC(val2)), TIME_TO_SEC(MAKETIME(val1, val5, val6)), TIME_TO_SEC(val3), TIME_TO_SEC(val4) FROM test.time_to_sec_table ORDER BY val1 ASC;
DROP TABLE test.time_to_sec_table;

