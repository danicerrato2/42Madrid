NAME	=	pipex

SRC		=	pipex.c

OBJ		=	$(SRC:.c=.o)

LIBS	=	libftprintf.a libft.a

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o ${NAME} ${OBJ} ${LIBS}

bonus:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re
