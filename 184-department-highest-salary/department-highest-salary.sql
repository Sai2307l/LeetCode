# Write your MySQL query statement below
with new_table as(
select e.id,e.name,e.salary,d.id as department_Id,d.name as department_Name
from Employee e
left join Department d on e.departmentId = d.id
), new_table2 as( 
    select id, name , salary, department_Id , department_Name ,
    dense_rank() over (
    partition by department_Id
    order by salary desc) 
    as salary_rank from new_table
) select department_Name as Department,name as Employee,salary as Salary
from new_table2 where salary_rank =1;



 