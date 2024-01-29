# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caqueiro <caqueiro@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 19:50:42 by caqueiro          #+#    #+#              #
#    Updated: 2024/01/09 20:06:50 by caqueiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP_SRCS =	input_handler.c\
					circular_list.c\
					moviments.c\
					handle_circular_list.c\
					sort_utils.c\
					sort_big.c\
					sort_small.c

CHECKERS_SRCS = checker.c

SERVER_SRCS_BONUS = server_bonus.c
CLIENT_SRCS_BONUS = client_bonus.c

LIBFT = utils/libft/libft.a

PUSH_SWAP = push_swap

CHECKER = checker

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -g

$(PUSH_SWAP):
		@make -C utils/libft
		@make -C utils/ft_printf
		${CC} ${PUSH_SWAP_SRCS} ${LIBFT} -o ${PUSH_SWAP}
		@printf "$(GREEN)    - Executable ready.\n$(RESET)"

all: $(PUSH_SWAP)

$(CHECKER):
		@make -C utils/libft
		@make -C utils/ft_printf
		${CC} ${SERVER_SRCS_BONUS} ${LIBFT} -o ${PUSH_SWAP_BONUS}
		${CC} ${CLIENT_SRCS_BONUS} ${LIBFT} -o ${PUSH_SWAP_BONUS}

bonus: $(CHECKER)

clean:
		@make fclean -C utils/libft
		@make fclean -C utils/ft_printf
		@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

fclean: clean
	${RM} ${PUSH_SWAP} ${CHECKER}
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re:	fclean all

.PHONY:	all clean fclean re
