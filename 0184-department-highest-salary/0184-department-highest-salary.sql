# Write your MySQL query statement below
SELECT Department,Employee,Salary FROM
(SELECT D.name as Department, E.name as Employee, E.salary AS Salary,
    DENSE_RANK() OVER(PARTITION BY E.departmentId ORDER BY E.salary DESC) AS pr
FROM Employee E LEFT JOIN Department D ON E.departmentId=D.id) AS P
WHERE pr=1;