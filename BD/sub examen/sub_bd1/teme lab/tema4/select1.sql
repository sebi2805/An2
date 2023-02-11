select lower(Nume),upper(Den_dep),Den_dir 
from angajati_as,departament_as,directie_as
where angajati_as.Cod_dir = departament_as.Cod_dir
and angajati_as.Cod_dir = directie_as.Cod_dir
and angajati_as.Cod_dep = departament_as.Cod_Dep;

select Cod_dir,Den_dir,INSTR(Den_dir,'er') 
from directie_as
where instr(Den_dir,'er')!=0;

select Nume,Den_dep,LENGTH(Den_dep)
from angajati_as,departament_as
where angajati_as.Cod_dep = departament_as.Cod_dep
and angajati_as.Cod_dir = departament_as.Cod_dir;