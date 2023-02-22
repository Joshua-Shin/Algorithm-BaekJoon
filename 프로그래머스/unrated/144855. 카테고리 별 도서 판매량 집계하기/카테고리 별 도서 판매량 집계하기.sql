-- 코드를 입력하세요
SELECT r1.category, sum(sales) as total_sales
from book r1 join book_sales r2
on r1.book_id = r2.book_id
where r2.sales_date between to_date('2022-01-01', 'yyyy-mm-dd') 
        and to_date('2022-01-31', 'yyyy-mm-dd')
group by r1.category
order by r1.category;
