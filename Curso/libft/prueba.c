#include <stdio.h>
#include <string.h>

void *ft_memmove(void *dst, const void *src,  size_t len)
{
	int i = 0;
	char buff[len];

	while (i < len)
	{
		buff[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = buff[i];
		i++;
	}

	return (dst);
}

int main()
{
	char *str = NULL;
	int len = -1;

	printf("%s\n", str);
	memmove(str, str+5, len);
	printf("%s\n", str);

	strcpy(str, "Holayadios");
	printf("%s\n", str);
	ft_memmove(str+5, str, len);
	printf("%s\n", str);

	return 0;
}
