insert into dept_as(DeptNo,DeptNume,Loc)
values(1,'Vanzari','Bucuresti');
insert into dept_as(DeptNo,DeptNume,Loc)
values(2,'Productie','Ploiesti');

insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo)
values(1,'Sef1',TO_DATE('30-10-1999','DD-MM-YYYY'),2000,1);
insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo)
values(2,'Sef2',TO_DATE('12-12-1998','DD-MM-YYYY'),2300,2);
insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo,IdSef)
values(3,'Ang1',TO_DATE('4-1-2001','DD-MM-YYYY'),1500,1,1);
insert into ang_as(AngId,AngNume,DataAngajarii,deptNo,IdSef)
values(4,'Ang2',TO_DATE('5-3-1997','DD-MM-YYYY'),1,1);
insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo,IdSef)
values(5,'Ang3',TO_DATE('10-5-1998','DD-MM-YYYY'),1800,1,4);
insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo,IdSef)
values(6,'Ang4',TO_DATE('6-6-1999','DD-MM-YYYY'),1400,2,2);
insert into ang_as(AngId,AngNume,DataAngajarii,Salariu,deptNo,IdSef)
values(7,'Ang5',TO_DATE('10-10-2001','DD-MM-YYYY'),1000,2,6);


select * from dept_as; 
select * from ang_as; 