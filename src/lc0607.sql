# Write your MySQL query statement below
SELECT s.name FROM SalesPerson AS s
WHERE s.sales_id NOT IN (
    SELECT o.sales_id FROM Orders AS o
    INNER JOIN Company AS c ON c.com_id=o.com_id
    WHERE c.name="RED"
)
