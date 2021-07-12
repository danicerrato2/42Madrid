SRCS = rush_02.c string.c translate_number.c search.c
OBJS = ${SRCS:.c=.o}
NAME = rush-02
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
