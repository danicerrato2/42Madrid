#!/bin/bash/
gcc -c -Wall -Wextra -Werror ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c; ar rc libft.a *.o; ranlib libft.a
