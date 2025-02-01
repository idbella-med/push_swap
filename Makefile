GREEN = \033[32m
RED = \033[31m
RESET = \033[0m

NAME = push_swap
COMP = cc
# FLAGS = -Wall -Wextra -Werror
src = push_swap.c swap.c push.c revers_rotate.c rotate.c handle_args.c sort.c index.c position.c sort_tools.c
obj = $(src:.c=.o)

all : $(NAME)

$(NAME) : $(obj)
	@echo "$(RED)start compailing....$(RESET)"
	@make re -C libft
	@make bonus -C libft
	@$(COMP) $(obj) ./libft/libft.a -o $(NAME)
	@echo "$(GREEN)DONE :)$(RESET)"

%.o: %.c push_swap.h
	@$(COMP) $(FLAGS) -c -o $@ $<

clean:
	@echo "$(RED)start command 'clean'....$(RESET)"
	@make clean -C libft
	@rm -rf $(obj)
	@echo "$(GREEN)DONE :)$(RESET)"

fclean: clean
	@echo "$(RED)start command 'fclean'....$(RESET)"
	@make fclean -C libft
	@rm -rf $(NAME)
	@echo "$(GREEN)DONE :)$(RESET)"

re: fclean all

.PHONY: clean