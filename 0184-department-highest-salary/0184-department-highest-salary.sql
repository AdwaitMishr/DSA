select d.name as Department, e.name as Employee, e.salary as Salary
from Employee e join Department d
on e.departmentId = d.id
group by d.id, e.name, e.salary, e.departmentId
having e.salary = (Select max(e2.salary) from Employee e2 where e2.departmentId = e.departmentId)