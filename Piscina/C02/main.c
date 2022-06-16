#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);
void *ft_print_memory(void *addr, unsigned int size);

int main(int argc, char *args[]){

	char src[] = {'H', 'o', 'l', 'a', '\0'}, dest[6], dest2[10], nonprint1 = 10, nonprint2 = 127, str[] = {'h', '0', 'l', 'A', '_', '\0'}, str2[] = {'H', '0', 'L', 'a', '\0'};
	char capi[40] = ".Ehdnmbd}I#a~Jp@F ?Dyi%:Lofu:8q`*N6xts[";
	char hexa[7] = {'\n', '\t', '\1' , -128, -45, -30, '\0'};
	unsigned int tam = 0;
	char ex12[93] = "Bonjour les aminches\t\t\tc est fo\nu\ttout\tce qu on peut faire avec\t\t\tprint_memory\t\t\t\tlol\tlol\t";
	char pruebas = 'P';
	void *p = &pruebas;

	if(argc != 2){
		printf("Error en argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			ft_strcpy(dest, src);
			printf("el src era \"%s\" y el dest es \"%s\"\n", src, dest);
			break;
		case 1:
			ft_strncpy(dest, src, 4);
			printf("el src era \"%s\" y el dest es \"%s\" con n = 4\n", src, dest);
			ft_strncpy(dest2, src, 10);
			printf("el src era \"%s\" y el dest es \"%s\" con n = 10\n", src, dest2);
			break;
		case 2:
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_alpha("HoLa"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_alpha("H0lA"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_alpha("Ho|a"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_alpha("Ho[a"));
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_alpha(dest));
			break;
		case 3:
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_numeric("1234567890"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_numeric("0123S6"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_numeric("012345&7"));
            printf("Este caso debe devolver 1 (%d)\n", ft_str_is_numeric(dest));
			break;
		case 4:
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_lowercase("hola"));
            printf("Este caso debe devolver 0 (%d)\n", ft_str_is_lowercase("hoLa"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_lowercase("ho|a"));
            printf("Este caso debe devolver 1 (%d)\n", ft_str_is_lowercase(dest));
			break;
		case 5:
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_uppercase("HOLA"));
            printf("Este caso debe devolver 0 (%d)\n", ft_str_is_uppercase("HOlA"));
			printf("Este caso debe devolver 0 (%d)\n", ft_str_is_uppercase("HO1A"));
            printf("Este caso debe devolver 1 (%d)\n", ft_str_is_uppercase(dest));
			break;
		case 6:
			printf("Este caso debe devolver 1 (%d)\n", ft_str_is_printable("! \"#$%%&\'()*+,-./:;<=>?@[\\]^_`{|}~"));
            printf("Este caso debe devolver 0 (%d)\n", ft_str_is_printable(&nonprint1));
            printf("Este caso debe devolver 0 (%d)\n", ft_str_is_printable(&nonprint2));
            printf("Este caso debe devolver 1 (%d)\n", ft_str_is_printable(dest));
			break;
		case 7:
			ft_strupcase(str);
			printf("Todo mayus: \"%s\"\n", str);
			break;
		case 8:
			ft_strlowcase(str2);
			printf("Todo minus: \"%s\"\n", str2);
			break;
		case 9:
			printf("Capitalize: \"%s\"\n", ft_strcapitalize(capi));
			break;
		case 10:
			tam = ft_strlcpy(dest2, str, 0);
			printf("Salida esperada un 5 (%u) y cadena esperada \"\": \"%s\"\n", tam, dest2);
			tam = ft_strlcpy(dest2, str, 1);
            printf("Salida esperada un 5 (%u) y cadena esperada \"\": \"%s\"\n", tam, dest2);
			tam = ft_strlcpy(dest2, str, 4);
            printf("Salida esperada un 5 (%u) y cadena esperada \"h0l\": \"%s\"\n", tam, dest2);
			tam = ft_strlcpy(dest2, str, 6);
            printf("Salida esperada un 5 (%u) y cadena esperada \"h0lA_\": \"%s\"\n", tam, dest2);
			tam = ft_strlcpy(dest, str, 10);
            printf("Salida esperada un 5 (%u) y cadena esperada \"h0lA_\": \"%s\"\n", tam, dest);
			break;
		case 11:
			printf("Salida esperada \"\\0a\\09\\01\\80\\d3\\e2: ");
			fflush(stdout);
			ft_putstr_non_printable(hexa);
			printf("\n");
			break;
		case 12:
			ft_print_memory(ex12, 91);
			printf("\n\n");
			fflush(stdout);
			ft_print_memory(p, 1);
			printf("\n\n");
			printf("Salida esperada hexa \"0a09 0180 d3e2 00  \": ");
			fflush(stdout);
			ft_print_memory(hexa, 7);
			break;
	}
}
