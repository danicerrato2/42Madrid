void ft_putchar(char c);
void ft_swap(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
int ft_strcmp(char *s1, char *s2);

int	main(void){

	int a = 0, b = 1;

	ft_putchar('H');
	ft_swap(&a, &b);
	ft_putstr("ola\n");
	ft_strlen("mundo");
	ft_strcmp("Hola", "Mundo");
}
