#include "ft_nm.h"
#include <stdio.h>
#include <string.h>

Elf32_Sym *getSym(t_elf fle, Elf32_Shdr *ph, unsigned int y)
{
	Elf32_Sym *z;
	unsigned int i;

	z = NULL;
	if ((z = (Elf32_Sym*)malloc(sizeof(Elf32_Sym) * y)) == NULL)
			return NULL;
	i = 0;
	while (i < y)
	{
		Elf32_Sym p  = *(Elf32_Sym*)(fle.ptr + ph->sh_offset + (sizeof(Elf32_Sym) * i));  
		z[i++] = p;
	}
	return z;
}

t_tab symo(t_elf fle, Elf32_Sym sys, Elf32_Shdr *ph)
{
	t_tab t;
	
	t.vs = 1;
	t.error = 0;
	t.exa = sys.st_value;
	t.name =(char *)fle.ptr + fle.shdr[ph->sh_link].sh_offset + sys.st_name;
	return t;
}

char getChar()
{
	char t;

	t = ' ';
	
	return t;
}

t_tab *getTab(unsigned long sym, Elf32_Sym *sys, t_elf fle, Elf32_Shdr *ph)
{
	unsigned long 	l;
	int		a;
	t_tab 		*t;

	l = 0;
	t = NULL;
	if ((t = (t_tab *)malloc(sizeof(t_tab) * sym)) == NULL)
		return NULL;
	while (l < sym)
	{
		a = ELF32_ST_TYPE(sys[l].st_info);
		t[l].vs = 0;
		if (a == STT_FUNC || a == STT_OBJECT || a == STT_NOTYPE)
		{
			t[l] = symo(fle, sys[l], ph);
			if (t[l].error < 0)
			{
				free(t);
				return NULL;
			}
		}
		l++;
	}
	return t;
}


t_tab *nettoie(t_tab *e, unsigned long sym, unsigned long h)
{
	t_tab *t;
	t = NULL;
	unsigned long x;

	x = 0;
	while (h < sym)
	{
		if (e[h].vs && ft_strlen(e[h].name) > 0)
			x++;
		h++;
	}
	if ((t = (t_tab *)malloc((sizeof(t_tab) * (x + 1)))) == NULL)
		return NULL;
	h = 0;
	x = 0;
	while (h < sym)
	{
		if (e[h].vs && ft_strlen(e[h].name) > 0)
		{
			t[x] = e[h];
			t[x].end = 0;
			x++;
		}
		h++;
	}
	t[x].end = 1;
	free(e);
	return t;
}


static int symb32(t_elf fle, Elf32_Shdr *ph, int y)
{
	unsigned int sym;
	Elf32_Sym *sys; 
	t_tab *e;

	sym = ph->sh_size / sizeof(Elf32_Sym);
	if ((sys = getSym(fle, ph, sym)) == NULL)
		return (-1);
	if ((e = getTab(sym, sys, fle, ph)) == NULL)
	{
		free(sys);
		return (-1);
	}
	e = nettoie(e, sym, 0);
	trie(e);
	for (unsigned int i = 0; e[i].end == 1 ; i++) {
		if (e[i].vs)
			ft_printf("|%s|\n", e[i].name);
	}
	free(sys);
	free(e);
	return (y);
}

Elf32_Shdr *getSh( unsigned char *ptr, Elf32_Ehdr *eh)
{
	int i;
	Elf32_Shdr	*f;


	i = 0;
	f = NULL;
	if ((f = (Elf32_Shdr * )malloc(sizeof(Elf32_Shdr) * eh->e_shoff)) == NULL)
		return (NULL);
	while (i < eh->e_shnum)
	{
		f[i] = *(Elf32_Shdr *)(ptr + (sizeof(Elf32_Shdr) * i));
	       i++;	
	}
	return f;
}

void ft_32(t_elf fle, int y)
{
	Elf32_Ehdr	*eh;
	Elf32_Shdr	*ph;
	unsigned char 	*ptr;
	int 		i;

	i = 0;
	eh = (Elf32_Ehdr *)fle.ptr;
	ptr = (unsigned char *)fle.ptr + eh->e_shoff;
	if ((fle.shdr = getSh(ptr, eh)) == NULL)
			return;
	while (i < eh->e_shnum)
	{
		ph = (Elf32_Shdr *)(ptr + (sizeof(Elf32_Shdr) * i));
		if (ph->sh_type == SHT_SYMTAB)
		{
			y = symb32(fle, ph, y);
			if (y < 0) {
				free(fle.shdr);
				return ;
			}
		}
		i++;
	}
	free(fle.shdr);
}
