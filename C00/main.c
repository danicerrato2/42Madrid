#include <stdio.h>
#include <stdlib.h>

void ft_putchar(char c);
void ft_print_alphabet(void);
void ft_print_reverse_alphabet(void);
void ft_print_numbers(void);
void ft_is_negative(int n);
void ft_print_comb(void);
void ft_print_comb2(void);
void ft_putnbr(int nb);
void ft_print_combn(int n);

int main(int argc, char *args[]){

	if(argc < 2 || argc > 3){
		printf("Faltan argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			ft_putchar('a');
			ft_putchar('\n');
			ft_putchar('<');
			break;
		case 1:
			ft_print_alphabet();
			break;
		case 2:
			ft_print_reverse_alphabet();
			break;
		case 3:
			ft_print_numbers();
			break;
		case 4:
			ft_is_negative(5);
			ft_is_negative(0);
			ft_is_negative(-5);
			break;
		case 5:
			ft_print_comb();
			break;
		case 6:
			ft_print_comb2();
			break;
		case 7:
			ft_putnbr(42);
			printf("\n");
			ft_putnbr(-55);
			break;
		case 8:
			ft_print_combn(atoi(args[2]));
	}

}
