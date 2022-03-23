#include "ft_nm.h"
#include <stdio.h>
#include <string.h>

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
	if ((e = nettoie(e, sym, 0)) == NULL)
		return (-1);
	trie(e);
	y = affiche(e, 0);
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
	if ((eh->e_shoff + (sizeof(Elf32_Shdr) * eh->e_shnum)) > fle.len)
	{
		return ;
	}
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
	if (!y)
		ft_printf("no sym\n");
	free(fle.shdr);
}
