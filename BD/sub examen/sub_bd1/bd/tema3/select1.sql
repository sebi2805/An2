select count(*) 
from angajati_as
where Cod_dir = 
    (select Cod_dir 
    from directie_as 
    where den_dir='Centru de profit');

select count(*) from directie_as,angajati_as
where directie_as.Cod_dir=angajati_as.Cod_dir 
and directie_as.den_dir='Centru de profit';


select sum(salariu) from directie_as,departament_as,angajati_as
where directie_as.Den_dir = 'Directia generala' 
and departament_as.Den_dep != 'Director general'
and directie_as.Cod_dir=angajati_as.Cod_dir 
and directie_as.Cod_dir=departament_as.Cod_dir
and departament_as.Cod_Dep=angajati_as.Cod_dep;

select Den_dep,Den_dir from departament_as,directie_as
where departament_as.cod_dir=directie_as.cod_dir;

select Nume,Salariu,Den_dep,Den_dir 
from angajati_as,departament_as,directie_as
where Salariu = (
    select max(salariu) 
    from angajati_as,departament_as 
    where angajati_as.Cod_dep = departament_as.Cod_Dep 
    and angajati_as.Cod_dir = departament_as.Cod_dir
    and Den_dep = 'Productie')
and directie_as.Cod_dir=angajati_as.Cod_dir 
and directie_as.Cod_dir=departament_as.Cod_dir
and departament_as.Cod_Dep=angajati_as.Cod_dep;




