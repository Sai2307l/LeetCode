# Write your MySQL query statement below
with new_table as(
    select l1.id,l1.num
    from logs l1
    left join logs l2
    on l1.id = l2.id+1
    left join logs l3
    on l1.id = l3.id+2
    where l1.num = l2.num and l2.num = l3.num
) select distinct num as ConsecutiveNums from new_table