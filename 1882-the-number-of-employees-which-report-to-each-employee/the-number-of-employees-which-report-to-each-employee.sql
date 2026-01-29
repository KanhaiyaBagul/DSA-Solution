# Write your MySQL query statement below

select m.employee_id , m.name , count(*) as reports_count , round(sum(e.age) / count(*)) as average_age
from employees as m
join employees as e
on m.employee_id = e.reports_to
group by m.employee_id
order by m.employee_id; 
