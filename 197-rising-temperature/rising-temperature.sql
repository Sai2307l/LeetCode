# Write your MySQL query statement below
select w1.id as Id from Weather w1
join weather w2
on w1.recordDate = w2.recordDate + Interval 1 DAY
WHERE w1.temperature > w2.temperature;