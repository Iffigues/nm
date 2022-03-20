#include "ft_nm.h"
#include <stdio.h>


void	*ft_memalloc(size_t size)
{
	void	*o;

	if (!(o = (void *)malloc(size)))
		return ((void *)0);
	return (ft_memset(o, 0, size));
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	char	*g;

	if (!(str = ft_memalloc(ft_strlen(s1) + 1)))
		return (NULL);
	g = str;
	while (*s1)
		ft_memset(str++, *s1++, 1);
	ft_memset(str, 0, 1);
	return (g);
}

char  *namer(char *p) {
	int i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	i++;
	char *r = ft_strdup(&p[i]);
	i = 0;
	while (r[i])
	{
		if (r[i] == '\n')
			r[i] = '\0';
		i++;
	}
	return r;	
}

int getElf(const char *ptr) {
	int i = 0;
	
	while (ft_strncmp(&ptr[i], "ELF", 3))
		i++;
	return i - 1;

}

void grab(const char *ptr) {
	t_elf g;

	g.ptr = ptr;
	getStat(g);
}

void ar(t_elf fle)
{
	int i = 0;
	char *str;
	struct ar_hdr	*header;

	str = NULL;	
	fle.ptr += SARMAG;
	header = (struct ar_hdr *)fle.ptr;
	fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	while (fle.ptr)
	{
		header = (struct ar_hdr *)fle.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return ;
		if (i == 0  && ft_strncmp(header->ar_name, "//", 2) == 0) {
			str = namer(header->ar_name);
			i = 0;
		}
		else 
		{
			i = 1;
		}
		if (i) {
			if (header->ar_name[0] == '/')
				printf("%s\n", &str[ft_atoi(&header->ar_name[1])]);
			else	
				printf("%s\n", header->ar_name);
			grab(fle.ptr + getElf(fle.ptr));
		}
		fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	}
	if (str != NULL)
		free(str);
}
