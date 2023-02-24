select distinct c.car_id
from CAR_RENTAL_COMPANY_CAR c join CAR_RENTAL_COMPANY_RENTAL_HISTORY h
on c.car_id = h.car_id
where car_type = '세단' and to_char(start_date, 'yyyy-mm') = '2022-10'
order by car_id desc;