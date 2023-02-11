create table clase_produs_cd(
cod_clasa number(3) primary key,
denumire_clasa varchar2(50));

create table produse_cd(
cod_clasa number(3) references clase_produs_cd(cod_clasa),
cod_produs number(3),
denumire_produs varchar2(50),
unitate_masura varchar2(20),
pret number,
primary key(cod_clasa,cod_produs));

create table produse_interzise_cd(
cod_clasa number(3),
cod_produs number(3),
foreign key(cod_clasa,cod_produs) references
produse_cd(cod_clasa,cod_produs));
