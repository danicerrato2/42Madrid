NAME	=	libft.a

SRC		=	$(filter-out $(SRB), $(wildcard *.c))
SRB		=	$(wildcard *_bonus.c)

OBJ		=	$(SRC:.c=.o)
OBB		=	$(SRB:.c=.o)

AR		=	ar rcs
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra #-g3 -fsanitize=address
RM		=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ) $(OBB)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean	all

bonus:		$(OBB)
			@$(AR) $(NAME) $(OBB)

#.PHONY:		all $(NAME) OBJ OBB bonus clean fclean re
