NAME = libftprintf.a
CC = cc
AR = ar
ARFLAGS = rcs
CFILES = ft_printf.c ft_printf_utils.c
OBJS = $(CFILES:.c=.o)
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus