NAME		=	libftprintf.a
SRC_LIB		=	$(wildcard src/libft/*)
SRC_PRNT	=	$(wildcard src/printf/*)
OBJ_DIR		= 	obj/
OBJ_LIB		=	$(addprefix $(OBJ_DIR), SRC_LIB:.c=.o)
OBJ_PRNT	=	$(addprefix $(OBJ_DIR), SRC_PRNT:.c=.o)
AR			=	ar rcs
CC			=	clang
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

all:		$(NAME)

$(NAME):	obj_dir $(OBJ_LIB) $(OBJ_PRNT)
			@$(AR) $(NAME) $(OBJ_LIB) $(OBJ_PRNT)

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

obj_dir:
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) -r $(OBJ_LIB) $(OBJ_PRNT)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

bonus:		$(OBB)
			@$(AR) $(NAME) $(OBB)

#.PHONY:		all $(NAME) OBJ OBB bonus clean fclean re
