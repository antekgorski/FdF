NAME = libftprintf.a
SOURCES = \
		ft_printf.c ft_putchar.c ft_puthex_lower.c\
		ft_puthex_upper.c ft_putnbr.c ft_putptr.c\
		ft_putstr.c ft_putunbr.c

OBJECTS = $(SOURCES:.c=.o)

CC =gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
