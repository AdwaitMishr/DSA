select t.request_at as Day,
round(sum(
    case
     when t.status = 'cancelled_by_driver'
     or t.status = 'cancelled_by_client'
     then 1
     else 0
    end 
)/ count(*), 2)  as 'Cancellation Rate'
from trips t join Users c
on t.client_id = c.users_id join Users d
on t.driver_id = d.users_id
where c.banned = 'No'
and d.banned = 'No'
and t.request_at between '2013-10-01' and '2013-10-03'
group by t.request_at