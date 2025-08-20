# Write your MySQL query statement below
SELECT a.name FROM Employee a
JOIN Employee b
ON a.id = b.managerID 
GROUP BY b.managerID
HAVING COUNT(*) >= 5;