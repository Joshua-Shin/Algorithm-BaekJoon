-- 코드를 입력하세요
SELECT BOOK_ID, to_char(PUBLISHED_DATE, 'yyyy-mm-dd') as PUBLISHED_DATE
from book
where to_char(PUBLISHED_DATE, 'yyyy') = '2021'
    and CATEGORY = '인문'
order by PUBLISHED_DATE;
