NAME = push_swap
BNS = checker 
CC = cc
FLAGS = -Wall -Wextra -Werror
SRC = check_push.c ft_strjoin.c push_b_to_a.c rotate.c libft.c push_swap.c sort_it.c ft_atio.c sort_three.c best_move_to_b.c ft_split.c push.c reverse_rotate.c swap.c main.c
SRCB = checker.c ft_strjoin.c rotate.c libft.c push_swap.c get_next_line.c get_next_line_utils.c ft_split.c push.c reverse_rotate.c swap.c ft_atio.c 
OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

bonus : $(BNS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(BNS) : $(OBJB)
		$(CC) $(FLAGS) -o $(BNS) $(OBJB)
$(OBJB) : %.o : %.c
		$(CC) $(FLAGS) -c $< -o $@

clean :
		rm -f $(OBJ) $(OBJB)

fclean : clean
		rm -f $(NAME) $(BNS)

re: fclean all                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           