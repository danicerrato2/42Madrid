NAME	=	pipex
#BONUS	=	checker

SRC		=	main.c pipex.c
#SRCB	=	main_bonus.c push_swap.c utils.c ft_stack.c push_swap_bonus.c

OBJ		=	$(SRC:.c=.o)
#OBJB	=	$(SRCB:.c=.o)

LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_DIR = libft

PRINTF	=	$(PRINTF_DIR)/libftprintf.a
PRINTF_DIR = printf

LIBS	=	$(LIBFT) $(PRINTF)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(LIBS)
			$(CC) $(CFLAGS) -o ${NAME} $^

#bonus:		$(OBJB) $(LIBS)
#			$(CC) $(CFLAGS) -o ${BONUS} $^

$(LIBS):	
			@make all -C $(LIBFT_DIR) --no-print-directory
			@make all -C $(PRINTF_DIR) --no-print-directory

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(OBJB) $(LIBS)
			@make clean -C $(LIBFT_DIR) --no-print-directory
			@make clean -C $(PRINTF_DIR) --no-print-directory

fclean:		clean
			@$(RM) $(NAME) $(BONUS)

re:			fclean	all

.PHONY:		all clean fclean re
