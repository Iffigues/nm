#include "ft_nm.h"

int	ft_strncmp(const char *s1, const  char *s2, size_t n)
{

	if (n == 0)
		return (0);
	while (--n && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int verif(t_elf *e) {
	if (ft_strncmp(e->ptr, ARMAG,SARMAG) == 0)
	{
		e->sys = 3;
		return 1;
	}
	if (((unsigned char)e->ptr[EI_MAG0] ==  ELFMAG0) != 1)
		return 0;
	if (((unsigned char)e->ptr[EI_MAG1] ==  ELFMAG1) != 1)
		return 0;
	if (((unsigned char)e->ptr[EI_MAG2] ==  ELFMAG2) != 1)
		return 0;
	if (((unsigned char)e->ptr[EI_MAG3] ==  ELFMAG3) != 1)
		return 0;
	return 1;
}

int endian(t_elf *e)
{
	if ((unsigned char)e->ptr[EI_DATA] == ELFDATA2MSB)
		e->endian = 1;
	else if ((unsigned char)e->ptr[EI_DATA] == ELFDATA2LSB) 
		 e->endian = 2;
	else 
		return 0;
	return 1;
}

int systems(t_elf *e)
{
	if ((unsigned char)e->ptr[EI_CLASS] == ELFCLASS32)
		e->sys = 1;
	else if ((unsigned char)e->ptr[EI_CLASS] == ELFCLASS64)
		e->sys = 2;
	else
		return 0;
	return 1;
}
