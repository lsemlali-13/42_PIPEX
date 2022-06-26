SRCS = pipex.c pipex_outils.c put_error.c pipex_outils2.c
BSRCS = pipex_bonus.c pipex_outils.c put_error.c pipex_outils2.c
CFLAGS = -Wall -Wextra -Werror
NAME = pipex
OBJ = $(SRCS:.c=.o)
BOBJ = $(BSRCS:.c=.o)

lbft = lbft/libft.a

$(NAME) : $(OBJ) $(lbft)
	@cc $(CFLAGS) $(OBJ) $(lbft) -o $(NAME)
$(lbft) :
	@cd lbft && make && cd .. 

all : $(NAME)

bonus : $(BOBJ) $(lbft)
	@cc $(CFLAGS) $(BOBJ) $(lbft) -o $(NAME)
clean :
	@rm -rf *.o && cd lbft && make fclean
fclean : clean
	@rm -rf $(NAME)
re : fclean all
