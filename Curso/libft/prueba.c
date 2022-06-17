#include <stdio.h>
#include <string.h>



void *ft_memmove(void *dst, const void *src,  size_t len)
{
	int i = 0;
	char buff[len];

	while (i < len && src + i > dst)
	{
		((char *)dst)[i] = ((char *)src)[i];
		i++;
	}
	while (i < len && src + i < dst + len)
	{
		((char *)dst)[len - 1] = ((char *)src)[len - 1];
		len--;
	}

	return (dst);
}

int main()
{
	char str[] = "0123456789";
	char src[] = "0123456789";
	int len = 5;

	printf("%s\n", str);
	memmove(str+5, str+3, len);
	printf("%s\n", str);

	printf("%s\n", src);
	memmove(src+5, src+3, len);
	printf("%s\n", src);

	return 0;
}
