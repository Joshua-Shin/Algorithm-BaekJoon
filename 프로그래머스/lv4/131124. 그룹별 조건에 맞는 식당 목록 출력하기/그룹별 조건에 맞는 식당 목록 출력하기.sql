select member_name, review_text, to_char(review_date, 'yyyy-mm-dd') review_date
from MEMBER_PROFILE m join REST_REVIEW r
on m.member_id = r.member_id
where m.member_id in 
(select member_id
from REST_REVIEW
group by member_id
having count(*) = (select max(count(*)) from REST_REVIEW group by member_id))
order by review_date, review_text;