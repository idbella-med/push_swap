NAME = push_swap
bonus = checker
COMP = cc
FLAGS = -Wall -Wextra -Werror
SRC = ./mandatory/main.c ./mandatory/handle_args.c ./mandatory/push.c ./mandatory/rotate.c ./mandatory/rev_rotate.c ./mandatory/swap.c ./mandatory/stacks_tools.c \
	./mandatory/utils.c ./mandatory/sort.c ./mandatory/sort_tools.c 

SRCBONUS = ./bonus/checker_bonus.c ./bonus/get_next_line_bonus.c ./bonus/handle_args_bonus.c ./bonus/push_bonus.c ./bonus/rev_rotate_bonus.c ./bonus/stacks_tools_bonus.c \
	./bonus/swap_bonus.c ./bonus/utils_bonus.c ./bonus/creat_list_bonus.c ./bonus/rotate_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@make re -C libft
	$(COMP) $(OBJ) $(FLAGS) ./libft/libft.a -o $(NAME)

bonus : $(bonus)

$(bonus) : $(OBJBONUS)
	@make re -C libft
	$(COMP) $(OBJBONUS) $(FLAGS) ./libft/libft.a -o $(bonus)

%.o: %.c push_swap.h ./bonus/checker_bonus.h
	@$(COMP) $(FLAGS) -c -o $@ $<

clean:
	@make clean -C libft
	@rm -rf $(OBJ)
	@rm -rf $(OBJBONUS)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)
	@rm -rf $(bonus)

re: fclean all

.PHONY: clean