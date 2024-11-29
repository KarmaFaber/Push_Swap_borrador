#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Variables:   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror
RM          := rm -rf
VALGRIND	:= valgrind --leak-check=full --show-leak-kinds=all -s

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Libft Variables ▢───▣───◉•◉───▣───▢◇▢───▣──◉#

LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES_LIBFT := -I$(LIBFT_DIR)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ push_swap srcs ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

PUSH_SWAP_SRCS:= push_swap.c
PUSH_SWAP_OBJS	:= $(PUSH_SWAP_SRCS:.c=.o)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢     rules      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFT_DIR)
	@echo "\033[0;35m$ libft.a created.\n\033[0m"

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT) 
	@echo "\033[0;35m'$(NAME)' created.\n\033[0m"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_LIBFT) -c $< -o $@ 

clean:
	$(RM) $(PUSH_SWAP_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "\033[0;35m$ All object files have been cleaned.\n\033[0m"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "\033[0;35m$(NAME) and libft.a: have been cleaned.\n\033[0m"

re: fclean all

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    Valgrind    ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

valgrind: $(NAME)
	$(VALGRIND) ./$(NAME) 

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Norminette   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

norm:
	@echo "\033[0;35mChecking Norminette:\n\033[0m"
	@norminette libft $(PUSH_SWAP_SRCS) push_swap.h

#◉───▣───▢◇▢───▣───◉•◉───▣───▢      Test      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

test: 
	@echo "\033[0;35mStarting test:\n\033[0m"
	@test/./test.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re valgrind norm test