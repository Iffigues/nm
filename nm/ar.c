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
	int i;
	char *r;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	i++;
	if (p[i])
		r = ft_strdup(&p[i]);
	else
		return (NULL);
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

void grab(const char *ptr, t_elf fle) {
	t_elf g;

	g.ptr = ptr;
	g.len = fle.len;
	getStat(g);
}

void affer(char *t) 
{
	int i;

	i = 0;
	write(1, "\n" , 1);
	while (t[i] && t[i] != '/')
		i++;
	write(1, t, i);
	write(1, ":\n", 2);
}

static void fr(char *str)
{
	if (str != NULL)
		free(str);
}

static void wily(t_elf fle, int i, char *str, struct ar_hdr *header)
{
	while (fle.ptr)
	{
		header = (struct ar_hdr *)fle.ptr;
		if (ft_atoi(header->ar_size) <= 0)
			return (fr(str));
		if (i == 0  && ft_strncmp(header->ar_name, "//", 2) == 0) {
			str = namer(header->ar_name);
			if (str == NULL)
				return ;
			i = 0;
		}
		else {
			i = 1;
			if (header->ar_name[0] == '/')
				affer(&str[ft_atoi(&header->ar_name[1])]);
			else
				affer(header->ar_name);
			grab(fle.ptr + getElf(fle.ptr), fle);
		}
		fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	}
	fr(str);
}

void ar(t_elf fle, int i)
{
	char *str;
	struct ar_hdr	*header;

	str = NULL;
	fle.ptr += SARMAG;
	header = (struct ar_hdr *)fle.ptr;
	fle.ptr += ft_atoi(header->ar_size) + sizeof(struct ar_hdr);
	wily(fle, i, str, header);
}
