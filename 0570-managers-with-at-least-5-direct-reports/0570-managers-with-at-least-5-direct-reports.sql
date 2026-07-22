# Write your MySQL query statement below
select e.name from employee e join employee e2 on e.id=e2.managerid group by e.id having
count(e2.id)>=5