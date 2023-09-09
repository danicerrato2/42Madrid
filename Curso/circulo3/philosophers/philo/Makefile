NAME	=	philo

SRC		=	main.c philo.c ft_atoi.c ft_list.c
#SRCB	=

OBJ		=	$(SRC:.c=.o)
#OBJB	=	$(SRCB:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra# -g3 -fsanitize=address -static-libsan
RM		=	rm -f

LIBS	=	-lpthread

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $^ $(LIBS) -o ${NAME}

#bonus:		$(OBJB) $(LIBFT)
#			$(CC) $(CFLAGS) -o ${BONUS} $^

%.o:		%.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -r $(OBJ) $(GNL_OBJ) $(OBJB)

fclean:		clean
			@$(RM) $(NAME) $(BONUS)

re:			fclean	all

.PHONY:		all clean fclean re
