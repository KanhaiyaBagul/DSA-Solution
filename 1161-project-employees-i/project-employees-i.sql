# Write your MySQL query statement below
#first here we find the sum of all the experience we have and divide by the count of it
select p.project_id , ROUND(sum(e.experience_years) / count(e.experience_years),2) as average_years
from Project as p
join Employee e
on p.employee_id = e.employee_id
group by p.project_id
