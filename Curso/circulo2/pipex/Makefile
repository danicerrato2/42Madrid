NAME	=	pipex
#BONUS	=	checker

SRC		=	main.c pipex.c
#SRCB	=	main_bonus.c push_swap.c utils.c ft_stack.c push_swap_bonus.c

OBJ		=	$(SRC:.c=.o)
#OBJB	=	$(SRCB:.c=.o)

LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) -o ${NAME} $^

#bonus:		$(OBJB) $(LIBFT)
#			$(CC) $(CFLAGS) -o ${BONUS} $^

$(LIBFT):	
			@make all -C $(LIBFT_DIR) --no-print-directory

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(OBJB)
			@make clean -C $(LIBFT_DIR) --no-print-directory

fclean:		clean
			@$(RM) $(NAME) $(BONUS)
			@make fclean -C $(LIBFT_DIR) --no-print-directory

re:			fclean	all

.PHONY:		all clean fclean re
