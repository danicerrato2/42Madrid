#include <stdio.h>
#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    void    *mem;
    int        i;

    if (count <= 0 || size <= 0)
        return (NULL);
    mem = malloc(count * size);
    if (mem == NULL)
        return (NULL);
    i = 0;
    while (i < count * size)
    {
        ((char *)mem)[i] = 0;
        i++;
    }
    return (mem);
}

int main()
{
    char *m = NULL, *n = NULL;
    int size = -1,  count = -2, i = 0;

    m = calloc(count, size);
    n = ft_calloc(count, size);
    while(i < size * count)
    {
        if (m[i] != n[i])
        {
            printf("Error %d\n", i);
            return 0;
        }
        i++;
    }
    printf("Correcto\n");

    return 0;
}
