# Write your MySQL query statement below
select distinct a.Email
from Person as a, Person as b
where a.Id != b.Id and a.Email = b.Email;
