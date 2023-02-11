insert into directie_as(Cod_dir,Den_dir)
values (1,'Centru de cost');
insert into directie_as(Cod_dir,Den_dir)
values (2,'Centru de profit');
insert into directie_as(Cod_dir,Den_dir)
values (3,'Directia generala');

insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values (1,1,'Marketing');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values (1,3,'Director general');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values (1,2,'Productie');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values (4,1,'Resurse umane');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values (2,1,'Secretariat');

insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (1,3,1,'Ang.1',2000.675,TO_DATE('1 jan. 1998','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (2,1,2,'Ang.2',200.54,TO_DATE('10 feb. 1997','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (3,1,2,'Ang.3',500.343,TO_DATE('30 aug. 1980','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (4,2,1,'Ang.4',300.67,TO_DATE('4 oct. 1994','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (5,2,1,'Ang.5',200.323,TO_DATE('6 nov. 2000','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (6,2,1,'Ang.6',400.78,TO_DATE('7 sep. 1993','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (7,1,4,'Ang.7',500.33,TO_DATE('21 dec. 1991','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (8,1,4,'Ang.8',300.43,TO_DATE('26 may. 1999','DD MON. YYYY'));
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu,Data_angajarii)
values (9,1,1,'Ang.9',700.898,TO_DATE('15 mar. 1995','DD MON. YYYY'));


select * from directie_as;
select * from departament_as;
select * from angajati_as;