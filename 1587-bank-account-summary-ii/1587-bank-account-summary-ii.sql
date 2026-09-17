# Write your MySQL query statement below
select Users.name ,sum(transactions.amount ) as balance
from transactions
join users
on users.account=transactions.account
group by users.name,users.account
having sum(transactions.amount)>10000;