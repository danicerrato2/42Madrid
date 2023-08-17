#include <stdio.h>

#include "pipex.h"

int main()
{
    char *cmd = "awk \'{printf \"Hola que tal\"}\'";
    char **args = 0;
    int i;

    args = ft_pipex_split(cmd, ' ');
    for (i = 0; args[i] != 0; i++)
    {
        printf("Argumento %d: %s\n", i+1, args[i]);
        free(args[i]);
    }
    free(args);

    return (0);
}