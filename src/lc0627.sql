# Write your MySQL query statement below
UPDATE Salary AS s
SET s.sex=IF(s.sex='m', 'f', 'm')
