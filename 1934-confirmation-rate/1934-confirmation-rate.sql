# Write your MySQL query statement below
select S.user_id, round(avg (case when c.action='confirmed'THEN 1 
                             else 0 end),2) as confirmation_rate
from signups s
left join confirmations c
on s.user_id=c.user_id
group by s.user_id;

