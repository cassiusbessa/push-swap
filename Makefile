# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caqueiro <caqueiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/20 19:50:42 by caqueiro          #+#    #+#              #
#    Updated: 2024/02/08 19:48:42 by caqueiro         ###   ########.fr        #
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
					handle_error.c\
					main.c\

CHECKERS_SRCS =	input_handler.c\
					circular_list.c\
					moviments.c\
					handle_circular_list.c\
					sort_utils.c\
					sort_big.c\
					sort_small.c\
					handle_error.c\
					checker.c

LIBFT = utils/libft/libft.a

PUSH_SWAP = push_swap

CHECKER = checker

CC	= cc
RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror

OBJS	= ${PUSH_SWAP_SRCS:.c=.o}

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(PUSH_SWAP): clean
		@make -C utils/libft
		${CC} ${PUSH_SWAP_SRCS} ${LIBFT} -o ${PUSH_SWAP}
		@make fclean -C utils/libft
		@printf "$(GREEN)    - Executable ready.\n$(RESET)"

all: $(PUSH_SWAP) clean
		@make fclean -C utils/libft
		${RM} ${OBJS} ${BONUS_OBJS}

$(CHECKER):
		@make -C utils/libft
		${CC} ${CHECKERS_SRCS} ${LIBFT} -o ${CHECKER}
		@make fclean -C utils/libft
		@printf "$(GREEN)    - Bonus Executable ready.\n$(RESET)"

bonus: $(CHECKER)

clean:
		@make fclean -C utils/libft
		${RM} ${OBJS} ${BONUS_OBJS}
		@printf "$(YELLOW)    - Objects removed.$(RESET)\n"

fclean: clean
	${RM} ${PUSH_SWAP} ${CHECKER}
	@printf "$(YELLOW)    - Executable removed.$(RESET)\n"

re:	fclean all
	@make fclean -C utils/libft
	${RM} ${OBJS} ${BONUS_OBJS}
	@printf "$(YELLOW)    - Objects removed.$(RESET)\n"
	@printf "$(GREEN)    - Makefile recompiled.$(RESET)\n"

.PHONY:	all clean fclean re
