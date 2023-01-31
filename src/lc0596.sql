# Write your MySQL query statement below
SELECT c.class FROM (
    SELECT c.class, COUNT(*) count FROM Courses c
    GROUP BY c.class
) c
WHERE c.count >= 5
