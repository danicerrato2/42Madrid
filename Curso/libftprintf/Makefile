NAME	=	libftprintf.a
SRC		=	$(wildcard src/*)
INC		=	$(wildcard inc/*)
OBJ		=	$(wildcard obj/*)
AR		=	ar rcs
CC		=	clang
FLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

all:		$(NAME)

$(NAME):	libft printf
			@$(AR) $(NAME) $(OBJ)

%.o:		%.c
			@$(CC) $(FLAGS) -c $(SRC) -o $(OBJ)

libft:
			@mkdir obj
			@$(CC) $(FLAGS) -c $(SRC) -o $(OBJ)

clean:
			@$(RM) $(OBJ) $(OBB)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

bonus:		$(OBB)
			@$(AR) $(NAME) $(OBB)

#.PHONY:		all $(NAME) OBJ OBB bonus clean fclean re
