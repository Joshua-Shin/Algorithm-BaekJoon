-- 코드를 입력하세요
SELECT book_id, author_name, to_char(published_date, 'YYYY-MM-DD') as PUBLISHED_DATE
from book join author
on book.author_id = author.author_id
where category = '경제'
order by published_date;

