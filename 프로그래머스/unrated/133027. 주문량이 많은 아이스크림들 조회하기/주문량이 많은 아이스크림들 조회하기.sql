-- 코드를 입력하세요
-- SELECT * from FIRST_HALF;
-- select * from july;

select flavor
from
    (select flavor, sum(total_order) as total
    from july
    group by flavor
    union all
    SELECT flavor, sum(total_order) as total
    from FIRST_HALF
    group by flavor)
group by flavor
order by sum(total) desc
fetch next 3 rows only;