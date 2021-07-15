#include <stdio.h>

char **ft_split(char *str, char *charset);

int main(void)
{
	char **strings;
			strings = ft_split("Hola|mundo|,|que|tal|?", "|");
            for (int i = 0; strings[i] != 0; i++)
                printf("%s ", strings[i]);
            printf("\n");
            strings = ft_split("", "|");
            for (int i = 0; strings[i] != 0; i++)
                printf("%s ", strings[i]);
            printf("\n");
            strings = ft_split("|,|", "|,");
            for (int i = 0; strings[i] != 0; i++)
                printf("%s ", strings[i]);
            printf("\n");
            strings = ft_split("Esta\ncadena esta\tdividida.&|por\"algunos%%caracteres", ", \n.|&\"%%\t");
            for (int i = 0; strings[i] != 0; i++)
                printf("%s ", strings[i]);
            printf("\n");
}
