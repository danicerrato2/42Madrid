SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = ${SRCS:.c=.o}
HEAD = includes/ft.h
NAME = libft.a
CC = gcc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rc ${NAME} ${HEAD} ${OBJS}

clean:
	rm ${OBJS}

fclean: clean
	${RM} ${NAME}

re:	fclean all

all: ${NAME}
