# Write your MySQL query statement below

select e2.name as Employee
from employee e2
join employee e1
on  e2.managerid=e1.id
where e2.salary>e1.salary;
