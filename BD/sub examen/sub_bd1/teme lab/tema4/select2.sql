select Nume,REPLACE(Nume,'An','I'),LENGTH(REPLACE(Nume,'An','I'))
from angajati_as;

select ROUND( SUM(Salariu),2 ) 
from angajati_as,departament_as
where angajati_as.Cod_dir = departament_as.Cod_dir
and angajati_as.Cod_dep = departament_as.Cod_dep
and Den_dep ='Director general';

select Nume,SUBSTR(Den_dep,1,5),REPLACE(Den_dir,'i','o'),Salariu
from angajati_as,departament_as,directie_as
where angajati_as.Cod_dir = departament_as.Cod_dir
and angajati_as.Cod_dep = departament_as.Cod_dep
and angajati_as.Cod_dir = directie_as.Cod_dir
and salariu >= 
    (select avg(Salariu) 
	from angajati_as); 

select Nume ,MOD(TRUNC(Salariu),3)
from angajati_as; 