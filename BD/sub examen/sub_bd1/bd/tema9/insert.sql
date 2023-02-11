insert into clase_produs_cd (cod_clasa, denumire_clasa) 
values (1, 'Materii prime');
insert into clase_produs_cd(cod_clasa, denumire_clasa) 
values (2, 'Materiale');
insert into clase_produs_cd (cod_clasa, denumire_clasa) 
values (3, 'Produse finite');
insert into clase_produs_cd(cod_clasa, denumire_clasa) 
values (4, 'Accesorii');

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (1, 1, 'Lemn', 'metru cub', 10);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs, pret)
values (1, 2, 'Sticla', 13);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura)
values (2, 1, 'Panza', 'metru');

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (2, 2, 'Hartie vrac', 'kg', 10);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (3, 1, 'Caiet', 'bucata', 7);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs)
values (3, 2, 'Carte');

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (3, 3, 'Creion', 'bucata', 2);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (3, 4, 'Haina', 'bucata', 40);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura, pret)
values (4, 1, 'Agrafa', 'set', 12);

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura)
values (4, 2, 'Cerneala', 'cutie');

insert into produse_cd (cod_clasa, cod_produs, denumire_produs,
unitate_masura,pret)
values (4, 3, 'Mina', 'cutie', 3);

insert into produse_interzise_cd (cod_clasa, cod_produs)
values (3, 4);
insert into produse_interzise_cd (cod_clasa, cod_produs)
values (4, 2);
