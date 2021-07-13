#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *ft_strdup(char *src);
int *ft_range(int min, int max);
int ft_ultimate_range(int **range, int min, int max);
char *ft_strjoin(int size, char **strs, char *sep);
char *ft_convert_base(char *nbr, char *base_from, char *base_to);
char **ft_split(char *str, char *charset);

int main(int argc, char *args[]){

	char *dest, *str1 = "Hola", *str2 = "que", *str3 = "tal?", *strs[3] = {str1, str2, str3};
	int *range = NULL, **p = &range;
	char **strings;

	if(argc != 2){
		printf("Error en argumentos\n");
		return -1;
	}

	switch (atoi(args[1])){
		case 0:
			dest = ft_strdup("Hola mundo!");
			printf("Salida esperada \"Hola mundo!\" (%s)\n", dest);
			free(dest);
			dest = ft_strdup("");
			printf("Salida esperada \"\" (%s)\n", dest);
			free(dest);
			break;
		case 1:
			range = ft_range(2, 8);
			printf("Del 2 al 8 (no incluido): ");
			for (int i = 0; i < 6; i++)
				printf("%d ", range[i]);
			free(range);
			range = ft_range(0, 3);
			printf("\nDel 0 al 3 (no incluido): ");
			for (int i = 0; i < 3; i++)
                printf("%d ", range[i]);
			free(range);
			range = ft_range(-4, 2);
            printf("\nDel -4 al 2 (no incluido): ");
            for (int i = 0; i < 6; i++)
                printf("%d ", range[i]);
            free(range);
			range = ft_range(-5, -10);
			if (range == NULL)
				printf("\nRange nulo correcto\n");
			else
				printf("\nRange nulo incorrecto\n");
			break;
		case 2:
			ft_ultimate_range(p, 2, 8);
            printf("Del 2 al 8 (no incluido): ");
            for (int i = 0; i < 6; i++)
                printf("%d ", range[i]);
            free(range);
            ft_ultimate_range(p, 0, 3);
			printf("\nDel 0 al 3 (no incluido): ");
            for (int i = 0; i < 3; i++)
                printf("%d ", range[i]);
            free(range);
        	ft_ultimate_range(p, -4, 2);
            printf("\nDel -4 al 2 (no incluido): ");
            for (int i = 0; i < 6; i++)
                printf("%d ", range[i]);
            free(range);
            printf("\nResultado esperado = 0 (%d) ", ft_ultimate_range(p, -5, -10));
            if (*p == NULL)
                printf("Range nulo correcto\n");
            else
                printf("Range nulo incorrecto\n");
			break;
		case 3:
			printf("Salida esperada \"Hola - que - tal?\" (%s)\n", ft_strjoin(3, strs, " - "));
			printf("Salida esperada \"Holaquetal?\" (%s)\n", ft_strjoin(3, strs, ""));
			break;
		case 4:
			dest = ft_convert_base("-1101101", "01", "0123456789ABCDEF");
			printf("Salida esperada \"-6D\" (%s)\n", dest);
			dest = ft_convert_base("30", "0123456789abcdef", "0123456789");
            printf("Salida esperada \"48\" (%s)\n", dest);
			dest = ft_convert_base("0", "0123456789", "abcdef");
			printf("Salida esperada \"a\" (%s)\n", dest);
			break;
		case 5:
			strings = ft_split("Hola|mundo|,|que|tal|?", "|");
			for (int i = 0; strings[i][0] != '\0'; i++)
				printf("%s ", strings[i]);
			printf("\n");
			strings = ft_split("", "|");
			for (int i = 0; strings[i][0] != '\0'; i++)
				printf("%s ", strings[i]);
			printf("\n");
			strings = ft_split("|,|", "|,");
			for (int i = 0; strings[i][0] != '\0'; i++)
				printf("%s ", strings[i]);
			printf("\n");
			strings = ft_split("Esta\ncadena esta\tdividida.&|por\"algunos%%caracteres", ", \n.|&\"%%\t");
			for (int i = 0; strings[i][0] != '\0'; i++)
				printf("%s ", strings[i]);
			printf("\n");
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
