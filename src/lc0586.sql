# Write your MySQL query statement below
SELECT customer_number FROM
(SELECT customer_number, COUNT(*) AS count
FROM Orders
GROUP BY customer_number) AS a
ORDER BY count DESC
LIMIT 1
