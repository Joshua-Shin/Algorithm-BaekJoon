-- 코드를 입력하세요
SELECT a.AUTHOR_ID, AUTHOR_NAME, CATEGORY, sum(SALES * PRICE) as TOTAL_SALES
from BOOK a join AUTHOR b on a.AUTHOR_ID = b.AUTHOR_ID
            join BOOK_SALES c on a.BOOK_ID = c.BOOK_ID
where to_char(SALES_DATE, 'yyyy-mm') = '2022-01'
group by a.AUTHOR_ID, AUTHOR_NAME, CATEGORY
order by a.AUTHOR_ID, CATEGORY desc;