#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char *ft_strcat(char *dest, char *src);
char *ft_strncat(char *dest, char *src, unsigned int nb);
/*char *ft_strstr(char *str, char *to_find);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);
*/
int main(int argc, char *args[]){

	char dest[20] = "Hola ", src[10] = "mundo_";

	if(argc != 2){
		printf("Error en argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			printf("Resultado esperado = 0 (%d)\n", ft_strcmp("", ""));
			printf("Resultado esperado = 0 (%d)\n", ft_strcmp("lo que quieras", "lo que quieras"));
			printf("Resultado esperado > 0 (%d)\n", ft_strcmp("pepito", "pepa"));
			printf("Resultado esperado < 0 (%d)\n", ft_strcmp("grillo", "grito"));
            printf("Resultado esperado > 0 (%d)\n", ft_strcmp("papaya", "papa"));
            printf("Resultado esperado < 0 (%d)\n", ft_strcmp("tinto", "tintoreria"));
			break;
		case 1:
            printf("Resultado esperado = 0 (%d)\n", ft_strncmp("lo que quieras tu", "lo que quiera yo", 13));
            printf("Resultado esperado > 0 (%d)\n", ft_strncmp("pepito", "pepa", 4));
            printf("Resultado esperado < 0 (%d)\n", ft_strncmp("grillo", "grito", 5));
            printf("Resultado esperado > 0 (%d)\n", ft_strncmp("papaya", "papa", 6));
            printf("Resultado esperado < 0 (%d)\n", ft_strncmp("tinto", "tintoreria", 10));
			break;
		case 2:
			printf("dest era \"%s\" y src es \"%s\", ahora dest es: ", dest, src);
			ft_strcat(dest, src);
			printf("%s\n", dest);
			break;
		case 3:
            ft_strncat(dest, src, 3);
			printf("Salida esperada \"Hola mun\" (%s)\n", dest);
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
	}

}
