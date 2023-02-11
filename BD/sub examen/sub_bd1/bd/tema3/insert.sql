insert into directie_as(Cod_dir,Den_dir)
values(1,'Centru de cost');
insert into directie_as(Cod_dir,Den_dir)
values(2,'Centru de profit');
insert into directie_as(Cod_dir,Den_dir)
values(3,'Directia generala');

insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values(1,1,'Marketing');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values(1,3,'Director general');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values(1,2,'Productie');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values(4,1,'Resurse umane');
insert into departament_as(Cod_dep,Cod_dir,Den_dep)
values(2,1,'Secretariat');

insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(1,3,1,'Ang.1',2000);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(2,1,2,'Ang.2',200);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(3,1,2,'Ang.3',500);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(4,2,1,'Ang.4',300);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(5,2,1,'Ang.5',200);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(6,2,1,'Ang.6',400);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(7,1,4,'Ang.7',500);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(8,1,4,'Ang.8',300);
insert into angajati_as(Matricol,Cod_dir,Cod_dep,Nume,Salariu)
values(9,1,1,'Ang.9',700);

select * from directie_as;
select * from departament_as;
select * from angajati_as; 