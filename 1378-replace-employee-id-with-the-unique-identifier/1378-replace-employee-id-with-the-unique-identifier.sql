# Write your MySQL query statement below
SELECT en.unique_id AS unique_id,e.name AS name FROM EmployeeUNI en RIGHT JOIN
Employees e ON e.id=en.id;