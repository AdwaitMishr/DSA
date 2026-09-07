select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e join Department d
on e.departmentId = d.id
where 3 > (
    Select count(distinct e2.salary)
    from Employee e2
    where e2.salary > e.salary AND
    e.departmentId = e2.departmentId
)