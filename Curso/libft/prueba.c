#include <stdio.h>
#include <string.h>
#include <xlocale.h>

char *ft_strnstr(const char *str, const char *sub, size_t n)
{
    int i = 0, j;

	if (str == NULL || sub == NULL || n <= 0)
        return ((char *)str);
    while (str + i != NULL && i < n){
        j = 0;
        while (str[i + j] == sub[j]){
			printf("Hola\n");
            if (sub + j + 1 == NULL)
			{
				printf("Encontrado: %s\n", (char *)str + i);
                return (char *)str + i;
			}
            j++;
        }
        i++;
    }
    return NULL;
}

int main()
{
    char str[] = "abcdefghij";
    char sub[] = "efgh";
    int n = 10;

	printf("%s\n", strnstr(str, sub, n));
	printf("%s\n", ft_strnstr(str, sub, n));

    if (strnstr(str, sub, n) == ft_strnstr(str, sub, n))
        printf("Correcto\n");
    else
        printf("Incorrecto\n");

    return 0;
}
