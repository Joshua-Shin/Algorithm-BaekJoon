-- 코드를 입력하세요
SELECT food_type, rest_id, rest_name, favorites
from rest_info r1
where favorites = (select max(favorites)
                   from rest_info r2
                   where r1.food_type = r2.food_type)
order by food_type desc;                   