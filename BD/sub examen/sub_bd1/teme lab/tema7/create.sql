create table grupa_as(
cod_grupa number(3) primary key,
den_grupa varchar2(10) not null,
nr_studenti number(2) default 0);

create table studenti_as(
id_stud number(4) primary key,
grupa number(3) references grupa_as(cod_grupa),
data_nasterii date,
specializare varchar2(10));

describe grupa_as;
describe studenti_as;