select 'Angajatul '|| Nume ||' face parte din departamentul ' || Den_dep
from angajati_as, departament_as
where angajati_as.Cod_Dep = departament_as.Cod_dep
and angajati_as.Cod_dir = departament_as.Cod_dir; 

select Nume,Salariu 
from angajati_as 
where Salariu = ( 
    select max(Salariu) from angajati_as where Salariu != (
	select max(Salariu) from angajati_as  
    )
);

 