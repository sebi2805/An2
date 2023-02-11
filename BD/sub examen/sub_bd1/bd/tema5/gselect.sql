select nume,den_dep, den_dir,
TO_CHAR(TRUNC(Data_angajarii,'MONTH'),'DD-MM-YY') 
from departament_as, directie_as, angajati_as 
where
angajati_as.Cod_dep=departament_as.Cod_dep and
angajati_as.Cod_dir=directie_as.Cod_dir and
departament_as.Cod_dir=directie_as.Cod_dir;

select nume, TRUNC(salariu,2) from angajati_as
where data_angajarii=(select min(data_angajarii) from angajati_as);

