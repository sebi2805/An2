--nr de angajati ai departamentului 'Productie' care sunt sefii altcuiva
select count(*) 
from ang_as,dept_as
where ang_as.DeptNo = dept_as.DeptNo
and DeptNume = 'Productie' and
AngId IN (select nvl(IdSef,0) from ang_as);

select A.AngNume
from ang_as A,ang_as S
where A.IdSef = S.AngId 
and nvl(A.Salariu,0) > nvl(S.Salariu,0)
and nvl(A.IdSef,0)!=0;
 
select AngNume,DeptNume,Loc,Salariu,DataAngajarii
from dept_as,ang_as
where dept_as.DeptNo = ang_as.DeptNo
and DataAngajarii > TO_DATE('1-JAN-1999','DD-MON-YYYY')
and ang_as.DeptNo = 1
UNION
select AngNume,DeptNume,Loc,Salariu,DataAngajarii
from dept_as,ang_as
where dept_as.DeptNo = ang_as.DeptNo
and DataAngajarii > TO_DATE('1-JAN-1999','DD-MON-YYYY')
and ang_as.DeptNo = 2
ORDER BY DataAngajarii;

select AngNume,DeptNume,Salariu
from ang_as A,dept_as
where dept_as.DeptNo = A.DeptNo
and 3 > (select count(*) from ang_as where nvl(A.Salariu,0) >
nvl(Salariu,0) );

select A.AngNume,A.DataAngajarii
from ang_as A,ang_as S
where A.IdSef = S.AngId
and A.DataAngajarii < S.DataAngajarii;

select A.AngNume,A.Salariu,S.AngNume
from ang_as A,ang_as S
where A.IdSef = S.AngId
and nvl(A.Salariu,0) > (select AVG(nvl(Salariu ,0)) from ang_as)
union 
select A.AngNume,A.Salariu,S.AngNume
from ang_as A,ang_as S
where A.IdSef = S.AngId and
nvl(A.IdSef,0)=0 and
nvl(A.Salariu,0) > (select avg(nvl(Salariu,0)) from ang_as); 
