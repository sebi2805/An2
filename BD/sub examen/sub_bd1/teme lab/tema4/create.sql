create table directie_as(
Cod_dir number(3) primary key,
Den_dir varchar2(20));

create table departament_as(
Cod_dep number(3),
Cod_dir number(3) references directie_as(Cod_dir),
Den_dep varchar2(20),
primary key(Cod_dep,Cod_dir));

create table angajati_as(
Matricol number(3) primary key,
Cod_dir number(3),
Cod_dep number(3),
Nume varchar2(20),
Salariu number,
foreign key(Cod_dir,Cod_dep) references departament_as(Cod_dir,Cod_dep));

describe directie_as;
describe departament_as;
describe angajati_as; 