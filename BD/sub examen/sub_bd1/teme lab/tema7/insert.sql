insert into grupa_as(cod_grupa,den_grupa)
values(1,'gr1');
insert into grupa_as(cod_grupa,den_grupa)
values(2,'gr2');
insert into grupa_as(cod_grupa,den_grupa)
values(3,'gr3');

insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(1,1,TO_DATE('14-11-1980','DD-MM-YYYY'),'Retele');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(2,1,TO_DATE('3-7-1978','DD-MM-YYYY'),'Aplicatii');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(3,1,TO_DATE('30-4-1981','DD-MM-YYYY'),'Retele');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(4,1,TO_DATE('1-1-1979','DD-MM-YYYY'),'Hard');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(5,2,TO_DATE('3-7-1980','DD-MM-YYYY'),'Aplicatii');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(6,2,TO_DATE('24-10-1981','DD-MM-YYYY'),'Retele');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(7,3,TO_DATE('6-7-1980','DD-MM-YYYY'),'Retele');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(8,1,TO_DATE('2-12-1980','DD-MM-YYYY'),'Retele');
insert into studenti_as(id_stud,grupa,data_nasterii,specializare)
values(9,2,TO_DATE('25-5-1978','DD-MM-YYYY'),'Aplicatii');

select * from grupa_as;
select * from studenti_as;