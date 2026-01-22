# Write your MySQL query statement below

select e.name as name from Employee as e
left join Employee m
on e.id = m.managerId
group by e.name,e.id
having count(m.managerId) >= 5


