#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_rev_int_tab(int *tab, int size);
void ft_sort_int_tab(int *tab, int size);

int main(int argc, char *args[]){

	int nbr = 0, cero = 0,  uno = 1, a = -5, b = 2, div = 0, mod = 0, error = 0;
	int tab[9] = {1, 2, 3, 4, 5, 6, 7, 8 ,9}, tab2[10] = {20, 100, 2, 200, -55, 157, -1, 4, 2, -30}, *null = NULL ;
	char *str = "Hola mundo", *strerr = NULL;
		
	if(argc < 2 || argc > 3){
		printf("Faltan argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			ft_ft(&nbr);
			printf("%d\n", nbr);
			break;
		case 1:
			printf("Mirar en codigo si tiene *********nbr = 42\n");
			break;
		case 2:
			ft_swap(&cero, &uno);
			printf("cero era 0 ahora es %d, uno era 1 ahora es %d\n", cero, uno);
			break;
		case 3:
			ft_div_mod(a, b, &div, &mod);
			printf("a = %d, b = %d, div = %d, mod = %d\n", a, b, div, mod);
			ft_div_mod(a, error, &div, &mod);
			printf("a = %d, b = %d, div = %d, mod = %d\n", a, error, div, mod);
			break;
		case 4:
            ft_ultimate_div_mod(&a, &b);
            printf("a era -5, b era 2, div = %d, mod = %d\n", a, b);
            ft_ultimate_div_mod(&a, &error);
            printf("a era -2, b era 0, div = %d, mod = %d\n", a, error);
			break;
		case 5:
			ft_putstr(str);
			printf("\n");
			ft_putstr(strerr);
			printf("\n");
			break;
		case 6:
			printf("La cadena \"%s\" tiene %d caracteres\n", str, ft_strlen(str));
			printf("Aqui se espera un 0 (%d)\n", ft_strlen(strerr)); 
			break;
		case 7:
			ft_rev_int_tab(tab, 9);
			for (int i = 0; i < 9; i++)
				printf("%d ", tab[i]);
			printf("\n");
			ft_rev_int_tab(null, 0);
			printf("\n");
			break;
		case 8:
			ft_sort_int_tab(tab2, 10);
			for (int i = 0; i < 10; i++)
                printf("%d ", tab2[i]);
            printf("\n");
			ft_sort_int_tab(null, 0);
			printf("\n");
	}

}
