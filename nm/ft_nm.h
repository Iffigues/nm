/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bordenoy <bordenoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 01:12:48 by bordenoy          #+#    #+#             */
/*   Updated: 2022/04/18 20:14:57 by bordenoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <stdlib.h>  
# include <unistd.h>
# include <fcntl.h>
# include <elf.h>
# include <ar.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include "ft_printf/ft_printf.h"
# include <stdio.h>

typedef struct s_elf
{
	const char	*name;
	const char	*ptr;
	int			endian;
	int			sys;
	struct stat	buf;
	size_t		len;
	Elf32_Ehdr	elf32;
	Elf64_Ehdr	elf64;
	Elf32_Shdr	*shdr;
	Elf64_Shdr	*sihdr;
}	t_elf;

typedef struct s_tab
{
	char		*name;
	long int	exa;
	char		t;
	int			vs;
	int			error;
	int			end;
}			t_tab;

typedef struct s_trente
{
	char			c;
	int				bind;
	long int		ltype;
	uint32_t		flags;
	uint32_t		type;
	unsigned char	info;
	Elf32_Half		shndx;
}			t_trente;

typedef struct s_soixante
{
	char			c;
	int				bind;
	long int		ltype;
	uint64_t		flags;
	uint64_t		type;
	unsigned char	info;
	Elf64_Half		shndx;
}			t_soixante;


int term(t_elf fle, unsigned int size);
void			*ft_memalloc(size_t size);
char			*ft_strdup(const char *s1);
char			*namer(char *p);
int				getelf(const char *ptr);
void			grab(const char *ptr, t_elf fle);
unsigned long	ge(char *t);
char			lo(char t);
int				place(char *s1, char *s2);
void			swap(t_tab *e, unsigned long j);
unsigned long	getsize(t_tab *e);
void			zeze(unsigned long *a, unsigned long *h);
Elf32_Sym		*getsym(t_elf fle, Elf32_Shdr *ph, unsigned int y);
t_tab			symo(t_elf fle, Elf32_Sym sys, Elf32_Shdr *ph);
t_tab			*gettab(unsigned long s, Elf32_Sym *i, t_elf f, Elf32_Shdr *p);
t_tab			*nettoie(t_tab *e, unsigned long sym, unsigned long h);
Elf64_Sym		*getsym64(t_elf fle, Elf64_Shdr *ph, unsigned int y);
t_tab			symo64(t_elf fle, Elf64_Sym sys, Elf64_Shdr *ph);
t_tab			*gettab64(unsigned long s, Elf64_Sym *i, t_elf f,
					Elf64_Shdr *p);
t_tab			*nettoie64(t_tab *e, unsigned long sym, unsigned long h);
void			getstat(t_elf fle);
void			ar(t_elf fle, int i);
void			ft_64(t_elf fle, int y);
char			sletter(t_elf fle, Elf64_Sym *sys);
char			letter(t_elf fle, Elf32_Sym *sys);
int				affiche(t_tab *c, int ii);
void			ft_32(t_elf fle, int y);
int				ft_help(void);
void			ft_nm(char *a);
void			trie(t_tab *e);
int				verif(t_elf *e);
int				endian(t_elf *e);
int				systems(t_elf *e);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
#endif
