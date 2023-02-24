-- 코드를 입력하세요
SELECT category, price max_price, product_name
from food_product r1
where category in ('과자','국','김치','식용유') and
    price = (select max(price) 
              from food_product r2
              where r1.category = r2.category)
order by price desc;