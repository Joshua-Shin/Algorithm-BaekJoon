select extract(month from start_date) month, car_id, count(*) records
from CAR_RENTAL_COMPANY_RENTAL_HISTORY
where extract(month from start_date) between 8 and 10
    and car_id in (select car_id
                 from CAR_RENTAL_COMPANY_RENTAL_HISTORY
                 where extract(month from start_date) between 8 and 10
                 group by car_id
                 having count(*) >= 5)
group by extract(month from start_date), car_id
having count(*) != 0
order by extract(month from start_date), car_id desc;