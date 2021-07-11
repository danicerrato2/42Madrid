SRCS = rush_02.c string.c translate_number.c
OBJS = ${SRCS: .c =.o}
NAME = rush_02
CC = cc
rm = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}:
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:	
	rm ${OBJS}

fclean: clean
	${RM} ${NAME}
