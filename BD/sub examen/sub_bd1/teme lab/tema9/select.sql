select denumire_produs,unitate_masura,pret
from produse_cd,clase_produs_cd
where produse_cd.cod_clasa = clase_produs_cd.cod_clasa
and denumire_clasa='Produse finite' and

