select Cod_dir,Den_dir,INSTR(Den_dir,'er') from directie_as
where INSTR(Den_dir,'er')!=0;
