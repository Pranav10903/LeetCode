# Write your MySQL query statement below
select activity_date as day, count(*) as active_users
from (
    select activity_date, user_id
    from activity
    where activity_date between '2019-06-28' and '2019-07-27'
    group by activity_date, user_id) t
group by activity_date;