-- 코드를 입력하세요
SELECT p.product_id, product_name, sum(price * amount) total_sales
from food_product p join food_order o
on p.product_id = o.product_id
where to_char(PRODUCE_DATE, 'yyyy-mm') = '2022-05'
group by p.product_id, product_name
order by total_sales desc, product_id;