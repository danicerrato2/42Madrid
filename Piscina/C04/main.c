#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int	ft_strlen(char *str);
void ft_putstr(char *str);
void ft_putnbr(int nb);
int ft_atoi(char *str);
void ft_putnbr_base(int nbr, char *base);
int ft_atoi_base(char *str, char *base); 

int main(int argc, char *args[]){

	if(argc != 2){
		printf("Error en argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			printf("Resultado esperado 0 (%d)\n", ft_strlen(""));
			printf("Resultado esperado 14 (%d)\n", ft_strlen("Daniel\nCerrato"));
			break;
		case 1:
			ft_putstr("Hola\nque\ttal\\estás?");
			break;
		case 2:
			ft_putnbr(42);
			write(1, "\n", 1);
			ft_putnbr(-33842);
		   	write(1, "\n", 1);
			ft_putnbr(-2147483648);
		   	write(1, "\n", 1);
			break;
		case 3:
			printf("Salida esperada -51234 (%d)\n", ft_atoi("  \t\v\n---+--+051234bn3"));
			break;
		case 4:
			ft_putnbr_base(11192, "0CODIG");
			write(1, "\n", 1);
			ft_putnbr_base(1614142, "0TEROC");
			write(1, "\n", 1);
			ft_putnbr_base(-2147483647, "0123456789");
			write(1, "\n", 1);
			ft_putnbr_base(-2147483648, "0123456789ABCEDF");
            write(1, "\n", 1);
			ft_putnbr_base(-42, "01");
			write(1, "\n", 1);
			break;
		case 5:
			printf("Valor esperado 11192 (%d)\n", ft_atoi_base("CODIGO", "0CODIG"));
			printf("Valor esperado -1614142 (%d)\n", ft_atoi_base("  ---+--CORRECTO", "0TEROC"));
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
