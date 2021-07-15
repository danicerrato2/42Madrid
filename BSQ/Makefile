SRCS = main.c init_board.c manage_file.c handle_board.c resolve_table.c checker.c utils.c
OBJS = ${SRCS:.c=.o}
NAME = bsq
CC = cc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	rm ${OBJS}

fclean: clean
	${RM} ${NAME}
