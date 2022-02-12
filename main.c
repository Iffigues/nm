#include <elf.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>

int mn(char *ptr)
{
	return *(int *) ptr;
}

int nm(char *ptr) {
	int d;

	d = *(int *) ptr;
	printf("%d\n%s\n", d, ptr);
	return 0;
}

int get_nmap(char *a, char **ptr, struct stat *buf)
{
	int fd;
	
	if ((fd = open(a, O_RDONLY)) < 0)
	{
		return (0);
	}

	if ((fstat(fd, buf)) < 0)
	{
		return (0);
	}

	*ptr = mmap(0, buf->st_size, PROT_READ, MAP_PRIVATE, fd, 0);
	if (*ptr == MAP_FAILED)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int mm(char *p)
{
	char		*ptr;
	struct stat	buf;

	if (get_nmap(p, &ptr, &buf) < 1)
		return (EXIT_FAILURE);

	nm(ptr);
	if (munmap(ptr, buf.st_size) < 0)
		return (EXIT_FAILURE);
	return 0;
}

int main (int argc, char **argv) {
	char		*ptr;
	struct  stat 	buf;

	if (argc == 1)
	{
		return (EXIT_SUCCESS);
	}
	argv++;
	while (*argv) {
		mm(*argv++);
	}
	return (EXIT_SUCCESS);
}
