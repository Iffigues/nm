#include "ft_nm.h"

int symb64(t_elf fle, Elf64_Shdr *ph, int y)
{
	unsigned int sym;
	Elf64_Sym *sys; 
	t_tab *e;

	sym = ph->sh_size / sizeof(Elf64_Sym);
	if ((sys = getSym64(fle, ph, sym)) == NULL)
		return (-1);
	if ((e = getTab64(sym, sys, fle, ph)) == NULL)
	{
		free(sys);
		return (-1);
	}
	if ((e = nettoie64(e, sym, 0)) == NULL)
		return (-1);
	trie(e);
	y = affiche(e, 1);
	free(sys);
	free(e);
	return (y);
}

 Elf64_Shdr *getSh64( unsigned char *ptr, Elf64_Ehdr *eh)
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
	if ((eh->e_shoff + (sizeof(Elf64_Shdr) * eh->e_shnum)) > fle.len)
	{
		return ;
	}
	ptr = (unsigned char *)fle.ptr + eh->e_shoff;
	if ((fle.sihdr = getSh64(ptr, eh)) == NULL)
			return;
	y = 0;
	while (i < eh->e_shnum)
	{
		ph = (Elf64_Shdr *)(ptr + (sizeof(Elf64_Shdr) * i));
		if (ph->sh_type == SHT_SYMTAB)
		{
			y = symb64(fle, ph, y);
			if (y < 0) {
				free(fle.sihdr);
				return ;
			}
		}
		i++;
	}
	if (!y)
		ft_printf("no sym\n");
	free(fle.sihdr);
}
