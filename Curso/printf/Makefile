NAME		=	libftprintf.a
SRC_LIB		=	$(wildcard src/libft/*)
SRC_PRNT	=	$(wildcard src/printf/*)
OBJ_LIB		=	$(SRC_LIB:.c=.o)
OBJ_PRNT	=	$(SRC_PRNT:.c=.o)
AR			=	ar rcs
CC			=	clang
FLAGS		=	-Wall -Werror -Wextra
RM			=	rm -f

all:		$(NAME)

$(NAME):	obj_dir $(OBJ_LIB) $(OBJ_PRNT)
			@$(AR) $(NAME) $(OBJ_LIB) $(OBJ_PRNT)
			@mv $(OBJ_LIB) $(OBJ_PRNT) obj/

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

obj_dir:
			@mkdir -p obj/

clean:
			@$(RM) -r obj/

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

bonus:		$(OBB)
			@$(AR) $(NAME) $(OBB)

#.PHONY:		all $(NAME) OBJ OBB bonus clean fclean re
