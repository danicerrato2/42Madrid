NAME	=	libftprintf.a

SRC		=	ft_printf.c \
			printf_libft.c \
			printf_utils.c \
			printf_flags.c

OBJ		=	$(SRC:.c=.o)

AR		=	ar rcs
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $@ $^

bonus:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re
