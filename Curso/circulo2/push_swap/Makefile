NAME	=	push_swap

SRC		=	push_swap.c utils.c ft_stack.c

OBJ		=	$(SRC:.c=.o)

LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) -o ${NAME} $^

bonus:		$(NAME)

$(LIBFT):	
			@make all -C $(LIBFT_DIR) --no-print-directory

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(LIBFT)
			@make clean -C $(LIBFT_DIR) --no-print-directory

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

.PHONY:		all clean fclean re
