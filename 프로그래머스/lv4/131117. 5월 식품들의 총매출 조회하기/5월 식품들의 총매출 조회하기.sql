SELECT p.product_id, product_name, sum(amount * price) total_sales
from food_product p join food_order o
on p.product_id = o.product_id
where to_char(o.produce_date, 'yyyy-mm') = '2022-05'
group by product_name, p.product_id
order by total_sales desc, p.product_id;