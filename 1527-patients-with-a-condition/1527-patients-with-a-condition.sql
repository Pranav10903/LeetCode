# Write your MySQL query statement below
select patient_id, patient_name, conditions 
from Patients 
where 
 substr(conditions,1,INSTR(conditions,' ')) like '%DIAB1%'
  or substr(conditions,INSTR(conditions,' '),length(conditions)) like '%DIAB1%'
  or conditions like 'DIAB1%'