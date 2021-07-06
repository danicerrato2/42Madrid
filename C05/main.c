#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int ft_iterative_factorial(int nb);
int ft_recursive_factorial(int nb);
int ft_iterative_power(int nb, int power);
int ft_recursive_power(int nb, int power);
int ft_fibonacci(int index);
int ft_sqrt(int nb);
int ft_is_prime(int nb);
int ft_find_next_prime(int nb);
//int ft_ten_queens_puzzle(void);

int main(int argc, char *args[]){

	if(argc != 2){
		printf("Error en argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			printf("Salida esperada 0 (%d)\n", ft_iterative_factorial(-2134));
			printf("Salida esperada 1 (%d)\n", ft_iterative_factorial(0));
			printf("Salida esperada 1 (%d)\n", ft_iterative_factorial(1));
			printf("Salida esperada 120 (%d)\n", ft_iterative_factorial(5));
			break;
		case 1:
			printf("Salida esperada 0 (%d)\n", ft_recursive_factorial(-2134));
            printf("Salida esperada 1 (%d)\n", ft_recursive_factorial(0));
            printf("Salida esperada 1 (%d)\n", ft_recursive_factorial(1));
            printf("Salida esperada 120 (%d)\n", ft_recursive_factorial(5));
			break;
		case 2:
			printf("Salida esperada 0 (%d)\n", ft_iterative_power(1, -1));
            printf("Salida esperada 1 (%d)\n", ft_iterative_power(0, 0));
            printf("Salida esperada 1 (%d)\n", ft_iterative_power(1, 0));
            printf("Salida esperada 36 (%d)\n", ft_iterative_power(6, 2));
			printf("Salida esperada -3375 (%d)\n", ft_iterative_power(-15, 3));
			break;
		case 3:
			printf("Salida esperada 0 (%d)\n", ft_recursive_power(1, -1));
            printf("Salida esperada 1 (%d)\n", ft_recursive_power(0, 0));
            printf("Salida esperada 1 (%d)\n", ft_recursive_power(1, 0));
            printf("Salida esperada 36 (%d)\n", ft_recursive_power(6, 2));
            printf("Salida esperada -3375 (%d)\n", ft_recursive_power(-15, 3));
			break;
		case 4:
			printf("Salida esperada -1 (%d)\n", ft_fibonacci(-4));
			printf("Salida esperada 0 (%d)\n", ft_fibonacci(0));
            printf("Salida esperada 1 (%d)\n", ft_fibonacci(1));
            printf("Salida esperada 1 (%d)\n", ft_fibonacci(2));
            printf("Salida esperada 55 (%d)\n", ft_fibonacci(10));
			break;
		case 5:
			printf("Salida esperada -1 (%d)\n", ft_sqrt(-3));
			printf("Salida esperada 0 (%d)\n", ft_sqrt(0));
			printf("Salida esperada 1 (%d)\n", ft_sqrt(1));
			printf("Salida esperada 12 (%d)\n", ft_sqrt(144));
			printf("Salida esperada 0 (%d)\n", ft_sqrt(120));
			break;
		case 6:
			printf("Salida esperada 0 (%d)\n", ft_is_prime(-3));
			printf("Salida esperada 0 (%d)\n", ft_is_prime(0));
			printf("Salida esperada 0 (%d)\n", ft_is_prime(1));
			printf("Salida esperada 1 (%d)\n", ft_is_prime(97));
			printf("Salida esperada 0 (%d)\n", ft_is_prime(91));
			break;
		case 7:
			printf("Salida esperada 2 (%d)\n", ft_find_next_prime(-3));
			printf("Salida esperada 2 (%d)\n", ft_find_next_prime(0));
			printf("Salida esperada 2 (%d)\n", ft_find_next_prime(1));
			printf("Salida esperada 2 (%d)\n", ft_find_next_prime(2));
			printf("Salida esperada 5 (%d)\n", ft_find_next_prime(4));
			printf("Salida esperada 97 (%d)\n", ft_find_next_prime(91));
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
