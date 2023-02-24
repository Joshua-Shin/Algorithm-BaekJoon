select car_id, max(
    case
        when '2022-10-16' between to_char(START_DATE, 'yyyy-mm-dd') 
            and to_char(END_DATE, 'yyyy-mm-dd') then '대여중'
        else '대여 가능'
    end) as AVAILABILITY
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
group by car_id
order by car_id desc;