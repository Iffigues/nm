#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <stdlib.h>  
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <ar.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "ft_printf/ft_printf.h"

typedef struct		s_elf
{
	const char	*ptr;
	int		endian;
	int		sys;
	struct stat	buf;
	Elf32_Ehdr	elf32;
	Elf64_Ehdr	elf64;
	Elf32_Shdr	*shdr;
}			t_elf;

typedef struct		s_tab
{
	char		*name;
	long int	exa;
	char 		t;
	int		vs;
	int		error;
	int		end;
}			t_tab;

typedef struct		s_trente
{
	char		c;
	int		bind;
	long int	ltype;
	uint32_t	flags;
	uint32_t	type;
	unsigned char	info;
	Elf32_Half	shndx;
}			t_trente;

typedef struct		s_soixante
{
	int		bind;
	uint64_t	sh_flags;
	uint64_t	sh_type;
	unsigned char	st_info;
	Elf64_Half	st_shndx;
}			t_soixante;

char			letter(t_elf fle, Elf32_Sym *sys);
void			affiche(t_tab *c);
void			ft_32(t_elf fle, int y);
int			ft_help(void);
void			ft_nm(char *a);
void			trie(t_tab *e);
int			verif(t_elf *e);
int			endian(t_elf *e);
int			systems(t_elf *e);
#endif
