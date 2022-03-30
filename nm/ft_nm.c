#include "ft_nm.h"

void failed(char *a)
{
	write(1, a, ft_strlen(a));
	return ;
}


void getstat(t_elf fle)
{
	if (!verif(&fle))
		return (failed("not elf"));
	if (fle.sys != 3) {
		if (!endian(&fle))
			return (failed("not un indien"));
		if (!systems(&fle))
			return (failed("not 64_32"));
		if (fle.sys == 1) {
			ft_32(fle, 0);
		}
		if (fle.sys == 2) {
			ft_64(fle, 0);
		}
	} else {
		ar(fle, 0);
	}
}

void	 ft_nm(char *a)
{
	int	fd;
	t_elf	fle;

	if ((fd = open(a, O_RDONLY)) < 0)
		return failed("error on open file\n");
	if ((fstat(fd, &fle.buf)) < 0)
		return failed("error with fstats");
	fle.ptr = mmap(0, fle.buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (fle.ptr == MAP_FAILED)
		return failed("mmap failed");
	fle.name = a;
	fle.len = fle.buf.st_size;
	getstat(fle);
	if (munmap((void *)fle.ptr, fle.buf.st_size) < 0)
		failed("munmap failed");
	close(fd);
}
