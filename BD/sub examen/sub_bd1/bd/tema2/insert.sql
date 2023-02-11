insert into departament_as(Cod_dep,Den_dep)
values(1,'Depart. X');
insert into departament_as(Cod_dep,Den_dep)
values(2,'Depart. Y');
insert into departament_as(Cod_dep,Den_dep)
values(3,'Depart. Z');

insert into angajati_as(Matricol,Cod_dep,Nume,Salariu)
values(1,1,'Nume 1',100);
insert into angajati_as(Matricol,Cod_dep,Nume,Salariu)
values(2,3,'Nume 2',200);
insert into angajati_as(Matricol,Cod_dep,Nume,Salariu)
values(3,1,'Nume 3',150);
insert into angajati_as(Matricol,Cod_dep,Nume,Salariu)
values(4,2,'Nume 4',400);
insert into angajati_as(Matricol,Cod_dep,Nume,Salariu)
values(5,3,'Nume 5',800);

select * from departament_as;
select * from angajati_as;