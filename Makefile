NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_puthexa.c ft_putptr.c ft_putunsigned.c

OBJS = ${SRC:.c=.o}

CC = cc

RM = rm -f

CFLAGS = -Wall -Werror -Wextra

INCLUDE = -I .

%.o:%.c
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
