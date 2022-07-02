NAME	=	libftprintf.a
SRC		=	$(wildcard src/*)
OBJ		=	$(SRC:.c=.o)
OBJ_DIR	=	obj/
AR		=	ar rcs
CC		=	gcc
FLAGS	=	-Wall -Werror -Wextra
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			@mkdir -p $(OBJ_DIR)
			@$(AR) $@ $^
			@mv $^ $(OBJ_DIR)

%.o:		%.c
			@$(CC) $(FLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

bonus:		$(OBJ)
			@$(AR) $(NAME) $^

#.PHONY:		all $(NAME) OBJ OBJ_DIR bonus clean fclean re
