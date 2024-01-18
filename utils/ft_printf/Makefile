SRCS = utils.c ft_printf.c
OBJS = ${SRCS:.c=.o}
LIBFT = ../libft/libft.a
LIBFT_TEMP = libft_temp.a
NAME = ft_printf.a
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I../libft/includes

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(LIBFT_TEMP): ${OBJS} ${LIBFT}
	ar -rvs ${LIBFT_TEMP} ${OBJS} ${LIBFT}

$(NAME): $(LIBFT_TEMP)
	cp $(LIBFT_TEMP) $(NAME)

all: $(NAME)

clean:
	${RM} ${OBJS} $(LIBFT_TEMP)

fclean: clean
	${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re

