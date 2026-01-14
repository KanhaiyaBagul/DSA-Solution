# Write your MySQL query statement below
select class
from Courses
group by class 
Having count(class) >= 5;