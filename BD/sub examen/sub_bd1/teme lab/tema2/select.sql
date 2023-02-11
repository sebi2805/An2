update departament_as 
set nr_angajati = ( 
select count(*) from angajati_as,departament_as 
where angajati_as.Cod_dep=departament_as.Cod_dep and 
departament_as.Den_dep='Depart. X'
)
where Den_dep='Depart. X';


update departament_as 
set Total_salarii = ( 
select sum(angajati_as.Salariu) from angajati_as,departament_as 
where angajati_as.Cod_dep=departament_as.Cod_dep and 
departament_as.Den_dep='Depart. Z'
)
where Den_dep='Depart. Z';
