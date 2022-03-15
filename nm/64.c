#include "ft_nm.h"
#include <stdio.h>
#include <string.h>

Elf64_Sym *getSym(t_elf fle, Elf64_Shdr *ph, unsigned int y)
{
	Elf64_Sym *z;
	unsigned int i;

	z = NULL;
	if ((z = (Elf64_Sym*)malloc(sizeof(Elf64_Sym) * y)) == NULL)
			return NULL;
	i = 0;
	while (i < y)
	{
		Elf64_Sym p  = *(Elf64_Sym*)(fle.ptr + ph->sh_offset + (sizeof(Elf64_Sym) * i));  
		z[i++] = p;
	}
	return z;
}

t_tab symo(t_elf fle, Elf64_Sym sys, Elf64_Shdr *ph)
{
	t_tab t;
	
	t.vs = 1;
	t.error = 0;
	t.t = letter(fle, &sys);
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

t_tab *getTab(unsigned long sym, Elf64_Sym *sys, t_elf fle, Elf64_Shdr *ph)
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
		a = ELF64_ST_TYPE(sys[l].st_info);
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


static int symb64(t_elf fle, Elf64_Shdr *ph, int y)
{
	unsigned int sym;
	Elf64_Sym *sys; 
	t_tab *e;

	sym = ph->sh_size / sizeof(Elf64_Sym);
	if ((sys = getSym(fle, ph, sym)) == NULL)
		return (-1);
	if ((e = getTab(sym, sys, fle, ph)) == NULL)
	{
		free(sys);
		return (-1);
	}
	if ((e = nettoie(e, sym, 0)) == NULL)
		return (-1);
	trie(e);
	affiche(e);
	free(sys);
	free(e);
	return (y);
}

Elf64_Shdr *getSh( unsigned char *ptr, Elf64_Ehdr *eh)
{
	int i;
	Elf64_Shdr	*f;


	i = 0;
	f = NULL;
	if ((f = (Elf64_Shdr * )malloc(sizeof(Elf64_Shdr) * eh->e_shoff)) == NULL)
		return (NULL);
	while (i < eh->e_shnum)
	{
		f[i] = *(Elf64_Shdr *)(ptr + (sizeof(Elf64_Shdr) * i));
	       i++;	
	}
	return f;
}

void ft_64(t_elf fle, int y)
{
	Elf64_Ehdr	*eh;
	Elf64_Shdr	*ph;
	unsigned char 	*ptr;
	int 		i;

	i = 0;
	eh = (Elf64_Ehdr *)fle.ptr;
	ptr = (unsigned char *)fle.ptr + eh->e_shoff;
	if ((fle.shdr = getSh(ptr, eh)) == NULL)
			return;
	while (i < eh->e_shnum)
	{
		ph = (Elf64_Shdr *)(ptr + (sizeof(Elf64_Shdr) * i));
		if (ph->sh_type == SHT_SYMTAB)
		{
			y = symb64(fle, ph, y);
			if (y < 0) {
				free(fle.shdr);
				return ;
			}
		}
		i++;
	}
	free(fle.shdr);
}
