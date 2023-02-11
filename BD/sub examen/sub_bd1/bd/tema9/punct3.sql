select denumire_produs, unitate_masura, pret  
from produse_cd A
where A.unitate_masura is not null and
0=(select count(*) from produse_interzise_cd 
where cod_clasa=A.cod_clasa and cod_produs=A.cod_produs);

select denumire_produs,unitate_masura, pret
from produse_cd
where produse_cd.unitate_masura is not null and
(cod_clasa,cod_produs) not in (select cod_clasa,cod_produs from
produse_interzise);


select cod_clasa, count(*), min(pret), max(pret) 
from produse_cd
group by cod_clasa;

select denumire_produs, cod_produs, pret, denumire_clasa from
clase_produs_cd A, produse_cd B where
2=(select count(*) from produse_cd C where 
B.pret<C.pret and 
0=(select count(*) from produse_interzise_cd where
C.cod_clasa=cod_clasa and C.cod_produs=cod_produs))
and A.cod_clasa=B.cod_clasa;

select cod_clasa, count(distinct unitate_masura) from produse_cd
where unitate_masura is not null
group by cod_clasa;

select A.cod_clasa, A.cod_produs from produse_interzise_cd A, produse_cd B
where A.cod_clasa=B.cod_clasa and A.cod_produs=B.cod_produs and
B.pret is null;
