# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzolotar <mzolotar@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/10 23:55:52 by psegura-          #+#    #+#              #
#    Updated: 2025/01/01 11:41:29 by mzolotar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	=	\033c
GREEN	=	\033[1;32m
RED		=	\033[0;31m
CYAN	=	\033[0;36m
WHITE	=	\033[0m

all:
	@make -C ../
	@echo "$(RESET)"
	@ruby srcs/main.rb

re: fclean all test

clean_temp:
	@rm -f .moves .results

fclean: clean clean_temp
	@make fclean -C ../
	@rm -f $(NAME)

clean: clean_temp
	@make clean -C ../

.PHONY: re fclean clean clean_temp
