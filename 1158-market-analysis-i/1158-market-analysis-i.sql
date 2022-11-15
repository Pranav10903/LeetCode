# Write your MySQL query statement below
select user_id as buyer_id, join_date, SUM(IF(order_date > "2018-12-31" and order_date < "2020-01-01" ,1,0)) as orders_in_2019 from Users
left join Orders on buyer_id = user_id
group by user_id