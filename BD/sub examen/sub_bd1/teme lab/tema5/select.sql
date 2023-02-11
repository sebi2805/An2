select Nume,Den_dep,Den_dir,TO_CHAR(
TRUNC(Data_angajarii,'MONTH'),'DD-MM-YYYY')
from directie_as,departament_as,angajati_as
where angajati_as.Cod_dir = departament_as.Cod_dir
and angajati_as.Cod_dep = departament_as.Cod_dep
and directie_as.Cod_dir = angajati_as.Cod_dir;

select Nume,ROUND(Salariu,2) 
from angajati_as
where Data_angajarii = (select MIN(Data_angajarii) from angajati_as);

select REPLACE(Nume,'Ang.','Angajatul'),Data_angajarii,
TO_CHAR( LAST_DAY(Data_angajarii), 'DD/MM/YY'),
TO_CHAR( NEXT_DAY(Data_angajarii,'MONDAY'),'DD-MON-RRRR')
from angajati_as;

select Nume,SUBSTR( TO_CHAR(Data_angajarii,'MON'),0,2)
from angajati_as;

select Nume,Den_dir
from angajati_as,directie_as
where angajati_as.Cod_dir = directie_as.Cod_dir
and Salariu > TO_CHAR(Data_angajarii,'YYYY'); 

select Nume,Salariu,Den_dep,decode(Den_Dep,'Director general','Director','Alt job')
from angajati_as,departament_as
where angajati_as.Cod_dir = departament_as.Cod_dir
and angajati_as.Cod_dep = departament_as.Cod_dep;

select Den_dep,MIN(Salariu),MAX(Data_angajarii)
from angajati_as,departament_as
where angajati_as.Cod_dir = departament_as.Cod_Dir
and angajati_as.Cod_Dep = departament_as.Cod_dep
group by Den_dep;

select AVG(Salariu) 
from angajati_as
where Nume!='Ang.5';


select Cod_dep,Cod_dir,min(salariu),max(salariu),avg(salariu)
from angajati_as
group by cod_dep,cod_dir;

select nume from angajati_as where
salariu = (select max(salariu) from angajati_as)
union
select nume from angajati_as where
salariu = (select max(salariu) from angajati_as where
salariu<(select max(salariu) from angajati_as))
union
select nume from
angajati_as where
salariu = (select max(salariu) from angajati_as where
salariu<(select max(salariu) from angajati_as where salariu<(select
max(salariu) from angajati_as)));
