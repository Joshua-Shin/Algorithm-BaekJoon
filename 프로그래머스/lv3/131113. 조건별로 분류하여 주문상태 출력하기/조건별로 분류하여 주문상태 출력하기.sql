-- 코드를 입력하세요
SELECT order_id, product_id, to_char(out_date, 'yyyy-mm-dd') as OUT_DATE,
    case
        when out_date <= to_date('2022-05-01', 'yyyy-mm-dd') then '출고완료'
        when out_date is null then '출고미정'
        else '출고대기'
    end as 출고여부
from FOOD_ORDER
order by order_id;