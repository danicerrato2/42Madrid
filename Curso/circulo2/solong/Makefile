NAME	=	so_long

SRC		=	main.c so_long.c checker.c ft_stack.c
#SRCB	=	

MAPS	=	valid_map.ber no_paths.ber no_rewards.ber two_exits.ber wrong_extension.txt \
			no_rectangular.ber open.ber two_players.ber wrong_char.ber
MAPS_DIR	= maps

OBJ		=	$(SRC:.c=.o)
#OBJB	=	$(SRCB:.c=.o)

LIBS	=	$(LIBFT) $(PRINTF) $(MINILIBX)

LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft

PRINTF	=	$(PRINTF_DIR)/libftprintf.a
PRINTF_DIR	= printf

MINILIBX	= $(MINILIBX_DIR)/libmlx.a $(MINILIBX_DIR)/libmlx_Linux.a
MINILIBX_DIR	= minilibx-linux

GNL		=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_DIR	=	getNextLine
GNL_OBJ =	$(GNL:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(GNL_OBJ) $(LIBS)
			$(CC) $(CFLAGS) -o ${NAME} $^

bonus:

#bonus:		$(OBJB) $(LIBFT)
#			$(CC) $(CFLAGS) -o ${BONUS} $^

$(LIBFT):	
			@make all -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
			@make all -C $(PRINTF_DIR) --no-print-directory

$(MINILIBX):
			@make all -C $(MINILIBX_DIR) --no-print-directory

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(GNL_OBJ) $(OBJB)
			@make clean -C $(LIBFT_DIR) --no-print-directory
			@make clean -C $(PRINTF_DIR) --no-print-directory
			@make clean -C $(MINILIBX_DIR) --no-print-directory

fclean:		clean
			@$(RM) $(NAME) $(BONUS)
			@make fclean -C $(LIBFT_DIR) --no-print-directory
			@make fclean -C $(PRINTF_DIR) --no-print-directory

re:			fclean	all

.PHONY:		all clean fclean re
