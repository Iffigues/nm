#include "ft_nm.h"

void exa(long int e, char *b)
{
	char *t;

	if ((t = (char *)malloc(sizeof(char) * 8)) == NULL)
		return;
	free(t);
}

int main () {
	exa(16, "01234567789abcdef");
}
