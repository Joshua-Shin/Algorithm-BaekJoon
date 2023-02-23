select animal_id, animal_type, name
from animal_ins
where sex_upon_intake like 'Intact%' and
animal_id in (select animal_id 
             from animal_outs 
             where SEX_UPON_OUTCOME like 'Spayed%' or
             SEX_UPON_OUTCOME like 'Neutered%')
order by animal_id;