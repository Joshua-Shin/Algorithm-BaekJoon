-- 코드를 입력하세요
SELECT USER_ID, NICKNAME, sum(PRICE) as TOTAL_SALES
from USED_GOODS_BOARD a join USED_GOODS_USER b
    on a.WRITER_ID = b.USER_ID
where STATUS = 'DONE'
group by USER_ID, NICKNAME
having sum(PRICE) >= 700000
order by sum(PRICE);