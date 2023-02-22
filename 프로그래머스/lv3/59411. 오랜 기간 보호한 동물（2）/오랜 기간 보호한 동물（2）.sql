-- 코드를 입력하세요
SELECT o.animal_id, i.name
from animal_ins i join animal_outs o
on i.animal_id = o.animal_id
order by (o.datetime - i.datetime) desc
fetch next 2 rows only;