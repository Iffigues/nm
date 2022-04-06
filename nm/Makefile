NAME=ft_nm
SRC=main.c ft_help.c ft_nm.c verif.c 32.c trie.c aff.c letter.c 64.c sletter.c ar.c 32s.c 64s.c utils.c tries.c ars.c
OBJ=$(SRC:.c=.o)
CC=gcc -g -fsanitize=address -Wall -Wextra -Werror
INCLUDE= -I ./
all:$(NAME)
$(NAME):$(OBJ)
	@make -C ft_printf/
	$(CC) $(INCLUDE) $(OBJ) -o $(NAME) ft_printf/libftprintf.a
%.o:%.c
	$(CC) $(INCLUDE) -c $< 
clean:
	@make clean -C ft_printf/ 
	rm -f *.o
fclean:clean
	@make fclean -C ft_printf/
	rm -f $(NAME)
re:fclean all
.PHONY:all clean fclean re
