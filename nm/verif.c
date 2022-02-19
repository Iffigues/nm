#include "ft_nm.h"

int verif(t_elf *e) {
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
