#◉────▣───▢◇▢───▣────◉•◉───▣───▢   Colors:   ▢───▣───◉•◉───▣────▢◇▢───▣───◉#

BLACK   := \033[0;30m
RED     := \033[0;31m
GREEN   := \033[0;32m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
CYAN    := \033[0;36m

CURRENT_COLOR := \033[0;34m
RESET   := \033[0m

#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Variables:   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

NAME        := push_swap
CC          := cc
CFLAGS      := -Wall -Wextra -Werror $(SANITIZERS)
RM          := rm -rf

VALGRIND := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-limit=no --log-file=test/valgrind_outputs/valgrind_output_$(shell date +%Y%m%d_%H%M%S).log -s
SANITIZERS := -fsanitize=address -fsanitize=undefined -fsanitize=leak -fsanitize=thread -g

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Libft Variables ▢───▣───◉•◉───▣───▢◇▢───▣──◉#

LIBFT_DIR	:= libft/
LIBFT		:= $(LIBFT_DIR)/libft.a
INCLUDES_LIBFT := -I$(LIBFT_DIR)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ push_swap srcs ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

PUSH_SWAP_SRCS	:= main.c error_utils.c stack_utils.c \
				push_command.c swap_command.c reverse_rotate_command.c rotate_command.c \

PUSH_SWAP_OBJS	:= $(PUSH_SWAP_SRCS:.c=.o)

#◉───▣───▢◇▢───▣───◉•◉───▣───▢     rules      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFT_DEPS)
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(PUSH_SWAP_OBJS) 
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_SWAP_OBJS) -L$(LIBFT_DIR) -lft $(INCLUDES_LIBFT) 
	@echo "$(CURRENT_COLOR) $(NAME) created.\n$(RESET)"

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES_LIBFT) -c $< -o $@ 

clean:
	$(RM) $(PUSH_SWAP_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(CURRENT_COLOR)All object files have been cleaned.\n$(RESET)"

fclean: clean
	$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(CURRENT_COLOR) $(NAME) and libft.a: have been cleaned.\n$(RESET)"

re: fclean all

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    Valgrind    ▢───▣───◉•◉───▣───▢◇▢───▣───◉#


valgrind: $(NAME)

	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──Running Valgrind..──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌──$(RESET)"
#	@-$(VALGRIND) ./$(NAME) "11 22 33 44 55 66 0"
	@-$(VALGRIND) ./$(NAME) 11 22 33 44 55 66 0
	@test/valgrind_outputs/./open_valgrind_log.sh
	@echo "$(CURRENT_COLOR)➵⤐╌╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣── Valgrind completed. Check valgrind_output.log for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"
	
clean_valgrind:
	test/valgrind_outputs/./clean_valgrind.sh

#◉───▣───▢◇▢───▣───◉•◉───▣───▢    Sanitizer   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

sanitizer: $(NAME)
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──Running program with Sanitizers...──╌╌➣⋆➣╌╌──$(RESET)"
	@./$(NAME)
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──Sanitizer run complete! Check your output for errors. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"


#◉───▣───▢◇▢───▣───◉•◉───▣───▢   Norminette   ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

norm:
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Checking Norminette: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@norminette libft $(PUSH_SWAP_SRCS) push_swap.h
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Norminette completed. Check your output for details. ─╌➣⋆➣╌─⤏➵•➵⤐─╌╌➣⋆➣╌╌─$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢      Test      ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

test: 
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting test: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/./test_push_swap.sh
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of test. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢  cheker_linux  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

cheker_linux: 
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── Starting checker_linux: ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"
	@test/./checker_linux
	@echo "$(CURRENT_COLOR)➵⤐──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌── End of checker_linux. ──╌╌➣⋆➣╌╌──⤏➵•➵⤐──╌╌➣⋆➣╌╌➔$(RESET)"

#◉───▣───▢◇▢───▣───◉•◉───▣───▢ Phony targets  ▢───▣───◉•◉───▣───▢◇▢───▣───◉#

.PHONY: all clean fclean re valgrind clean_valgrind sanitizer norm test cheker_linux