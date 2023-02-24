select car_id, c.car_type, (daily_fee * 30 * (100 - DISCOUNT_RATE) / 100) fee
from CAR_RENTAL_COMPANY_CAR c join CAR_RENTAL_COMPANY_DISCOUNT_PLAN p
    on c.car_type = p.car_type
where c.car_type in ('세단', 'SUV')
    and c.car_id not in (select car_id
                        from CAR_RENTAL_COMPANY_RENTAL_HISTORY
                        where '2022-11-01' between to_char(start_date, 'yyyy-mm-dd') and to_char(end_date, 'yyyy-mm-dd')
                         or '2022-11-30' between to_char(start_date, 'yyyy-mm-dd') and to_char(end_date, 'yyyy-mm-dd'))
    and (daily_fee * 30 * (100 - DISCOUNT_RATE) / 100) between 500000 and 1999999
    and DURATION_TYPE like '30%'
order by fee desc, c.car_type, car_id desc;