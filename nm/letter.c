#include "ft_nm.h"

t_trente getTyper(t_elf fle, Elf32_Sym *sys)
{
	t_trente t;
	
	t.shndx = sys->st_shndx;
	t.info = sys->st_info;
	t.flags = fle.shdr[t.shndx].sh_flags;
	t.type = fle.shdr[t.shndx].sh_type;
	t.bind = ELF32_ST_BIND(t.info);
	t.ltype = ELF32_ST_TYPE(t.info);
	t.c = '?';
	return t;
}

char alphe(char e, char t, int i)
{
	if (i)
		return (t);
	return (e);
}

char letter(t_elf fle, Elf32_Sym *sys)
{
	t_trente t;

	t = getTyper(fle, sys);
	if (t.bind == STB_GNU_UNIQUE)
		t.c = 'u';
	else if (t.bind == STB_WEAK)
		t.c = alphe('W', 'w', t.shndx == SHN_UNDEF);
	else if (t.bind == STB_WEAK && t.ltype == STT_OBJECT)
		t.c = alphe('V', 'v', t.shndx == SHN_UNDEF);
	else if (t.shndx == SHN_UNDEF)
		t.c = alphe('U','u', t.bind == STB_LOCAL);
	else if (t.shndx == SHN_ABS)
		t.c = alphe('A','a', t.bind == STB_LOCAL);
	else if (t.shndx == SHN_COMMON)
    		t.c = alphe('C', 'c', STB_LOCAL);
	else if (t.type == SHT_NOBITS && t.flags == (SHF_ALLOC | SHF_WRITE))
		t.c = alphe('B', 'b', t.bind == STB_LOCAL);
	else if (t.type == SHT_PROGBITS && t.flags == SHF_ALLOC)
		t.c = alphe('R','r', t.bind == STB_LOCAL);
	else if (t.type == SHT_PROGBITS && t.flags == (SHF_ALLOC | SHF_WRITE))
		t.c = alphe('D', 'd', t.info == STB_GLOBAL);
	else if (t.type == SHT_DYNAMIC)
		t.c = alphe('D', 'd', t.ltype == STB_GLOBAL);
	else if (t.type == SHT_PROGBITS || t.type == SHT_INIT_ARRAY || t.type == SHT_FINI_ARRAY )
		t.c = alphe('T', 't',t.bind == STB_LOCAL);
	return t.c;
}
