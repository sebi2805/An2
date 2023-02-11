select count(*) from ang_as,dept_as
where ang_as.deptno=dept_as.deptno and deptnume='Productie'
and AngId in (select IdSef from ang_as );

select * from ang_as a1 where
nvl(idSef,0)!=0 and
nvl(salariu,0) > (select nvl(salariu,0) from ang_as a2 where
a1.idsef=a2.angid);


