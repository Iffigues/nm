NAME=ft_nm
SRC=main.c ft_help.c ft_nm.c ft_utils.c verif.c
OBJ=$(SRC:.c=.o)
CC=gcc -Wall -Wextra -Werror -m64
INCLUDE= -I ./
all:$(NAME)
$(NAME):$(OBJ)
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME)
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	rm -f *.o
fclean:clean
	rm -f $(NAME)
re:fclean all
.PHONY:all clean fclean re
