# Write your MySQL query statement below
select b.Id
from Weather as a, Weather as b
where timestampdiff(day,a.Date,b.Date) = 1 and b.Temperature > a.Temperature; 
