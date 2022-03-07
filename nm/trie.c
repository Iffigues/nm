#include "ft_nm.h"

unsigned long ge(char *t)
{
	unsigned long l;

	l = 0;
	while (t[l] && t[l] == '_')
		l++;
	return l;
}

char lo(char t)
{
	if (t >= 'A' && t <= 'Z')
		return (t + ('a' - 'A'));
	return t;
}

int  place(char *s1, char *s2)
{
	while(*s1 && *s2 && (lo(*s1) == lo(*s2)))
	{
		s1++;
		s2++;
	}
	return (lo(*s1) - lo(*s2));
}

void swap(t_tab *e, unsigned long j)
{
	t_tab k;
	unsigned long m;
	unsigned long f;

	m = ge(e[j + 1].name);
	f = ge(e[j].name);
	if (place(&e[j + 1].name[m], &e[j].name[f]) < 0)
	{
		k = e[j];
		e[j] = e[j + 1];
		e[j + 1] = k;
	}
}

unsigned long getSize(t_tab *e)
{
	unsigned long j;

	j = 0;
	while (e[j].end  == 0)
		j++;
	return j;
}

void trie(t_tab *e)
{
	unsigned long h;
	unsigned long j;
	unsigned long k;

	h = getSize(e);
	k = 0;
	while (k < (h - 1))
	{
		j = 0;
		while (j < (h - 1 - k))
		{
			swap(e, j);
			j++;
		}
		k++;
	}
}
