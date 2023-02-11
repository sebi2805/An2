select count(*) from directie_as,angajati_as 
where directie_as.Cod_dir=angajati_as.Cod_dir and
Den_dir='Centru de profit';

select sum(salariu) from directie_as,departament_as,angajati_as 
where den_dir='Directia generala' and 
den_dep='Director general' and
directie_as.Cod_dir=angajati_as.Cod_dir and
angajati_as.Cod_dir=departament_as.Cod_dir and
departament_as.Cod_dep=angajati_as.Cod_dep;

select Den_dep, Den_dir from directie_as,departament_as
where directie_as.Cod_dir=departament_as.Cod_dir;

select nume, salariu, Den_dep, Den_dir from
directie_as,departament_as,angajati_as
where salariu=(select max(salariu) from angajati_as) and
directie_as.Cod_dir=angajati_as.Cod_dir and
angajati_as.Cod_dir=departament_as.Cod_dir and
departament_as.Cod_dep=angajati_as.Cod_dep;

select 'Angajatul '||nume||' face parte din departamentul '||Den_dep from
departament_as,angajati_as 
where departament_as.Cod_dir=angajati_as.Cod_dir and
departament_as.Cod_dep=angajati_as.Cod_dep;

select max(salariu), nume from
angajati_as
where salariu<(select max(salariu) from angajati_as);
