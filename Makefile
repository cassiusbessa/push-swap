# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 19:50:42 by caqueiro          #+#    #+#              #
#    Updated: 2024/01/31 22:22:32 by caqueiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

PUSH_SWAP_SRCS =	input_handler.c\
					circular_list.c\
					moviments.c\
					handle_circular_list.c\
					sort_utils.c\
					sort_big.c\
					sort_small.c\
					utils.c\
					main.c

CHECKERS_SRCS = checker.c

SERVER_SRCS_BONUS = server_bonus.c
CLIENT_SRCS_BONUS = client_bonus.c

LIBFT = utils/libft/libft.a

PUSH_SWAP = push_swap

CHECKER = checker

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${PUSH_SWAP_SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(PUSH_SWAP):
		@make -C utils/libft
		${CC} ${PUSH_SWAP_SRCS} ${LIBFT} -o ${PUSH_SWAP}
		@printf "$(GREEN)    - Executable ready.\n$(RESET)"

all: $(PUSH_SWAP)

$(CHECKER):
		@make -C utils/libft
		${CC} ${SERVER_SRCS_BONUS} ${LIBFT} -o ${PUSH_SWAP_BONUS}
		${CC} ${CLIENT_SRCS_BONUS} ${LIBFT} -o ${PUSH_SWAP_BONUS}

bonus: $(CHECKER)

clean:
		@make fclean -C utils/libft
		${RM} ${OBJS} ${BONUS_OBJS}
		@printf "$(YELLOW)    - Objects removed.$(RESET)\n"

fclean: clean
	${RM} ${PUSH_SWAP} ${CHECKER}
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re:	fclean all

.PHONY:	all clean fclean re
