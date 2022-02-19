#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <stdlib.h>  
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/stat.h>
#include <sys/mman.h>

typedef struct		s_elf
{
	const char	*ptr;
	int		endian;
	int		sys;
	struct stat	buf;
	Elf32_Ehdr	elf32;
	Elf64_Ehdr	elf64;
}			t_elf;

int	ft_help(void);
void	ft_nm(char *a);
size_t	ft_strlen(const char *s);
int verif(t_elf *e);
int endian(t_elf *e);
int systems(t_elf *e);
#endif
