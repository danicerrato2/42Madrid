NAME	=	so_long

SRC		=	main.c so_long.c checker.c ft_stack.c window.c free.c
#SRCB	=

OBJ		=	$(SRC:.c=.o)
#OBJB	=	$(SRCB:.c=.o)

LIBS	=	$(LIBFT) $(PRINTF) $(MLX)

LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_DIR	= libft

PRINTF	=	$(PRINTF_DIR)/libftprintf.a
PRINTF_DIR	= printf

MLX		=	$(MLX_DIR)/libmlx.dylib
MLX_DIR	=	minilibx_mac

GNL		=	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
GNL_DIR	=	getNextLine
GNL_OBJ =	$(GNL:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
LIBFLAGS	=	-lz -framework OpenGL -framework AppKit
L_LIBFLAGS	=	-lmlx -lX11 -lXext
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ) $(GNL_OBJ) $(LIBS)
			$(CC) $(CFLAGS) -o ${NAME} $^ $(LIBFLAGS)

bonus:

#bonus:		$(OBJB) $(LIBFT)
#			$(CC) $(CFLAGS) -o ${BONUS} $^

$(LIBFT):
			@make all -C $(LIBFT_DIR) --no-print-directory

$(PRINTF):
			@make all -C $(PRINTF_DIR) --no-print-directory

$(MLX):
			@make all -C $(MLX_DIR) --no-print-directory
			@cp $(MLX) .

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(GNL_OBJ) $(OBJB)
			@make clean -C $(LIBFT_DIR) --no-print-directory
			@make clean -C $(PRINTF_DIR) --no-print-directory
			@make clean -C $(MLX_DIR) --no-print-directory

fclean:		clean
			@$(RM) $(NAME) $(BONUS)
			@make fclean -C $(LIBFT_DIR) --no-print-directory
			@make fclean -C $(PRINTF_DIR) --no-print-directory
			@rm -rf libmlx.dylib

re:			fclean	all

.PHONY:		all clean fclean re
