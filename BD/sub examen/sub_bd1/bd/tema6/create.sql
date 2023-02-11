create table dept_as(
DeptNo number(3) primary key,
DeptNume varchar2(10),
Loc varchar2(10));

create table ang_as(
AngId number(6) primary key,
AngNume varchar2(20),
DataAngajarii date,
Salariu number,
DeptNo number(3) references dept_as(DeptNo),
IdSef number(3));

describe dept_as;
describe ang_as;