create table DEPARTAMENT_AS(
Cod_dep number(3) primary key,
Den_dep varchar2(20) not null,
Nr_angajati number(2) default 0,
Total_salarii number default 0 );

create table ANGAJATI_AS(
Matricol number(3) primary key,
Cod_dep number(3) references DEPARTAMENT_AS(Cod_dep),
Nume varchar2(40),
Salariu number );

describe departament_as;
describe angajati_as; 