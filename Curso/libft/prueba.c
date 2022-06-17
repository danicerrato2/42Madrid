#include <stdio.h>
#include <string.h>

void *ft_memcpy(void *dst, const void *src,  size_t len)
{
	int i = 0;
	while (i != len)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}

	return (dst);
}

int main()
{
	char str[10];
	char dst[10];
	int len = 10;

	memset(str, 'a', 10);
	memcpy(str, str, len);
	if (str[9] == 'a')
		printf("Correcto\n");
	else
		printf("Incorrecto\n");

	memset(str, 'a', 10);
	ft_memcpy(str, str, len);
	if (str[9] == 'a')
		printf("Correcto\n");
	else
		printf("Incorrecto\n");

	return 0;
}
