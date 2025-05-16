NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Werror -Wextra
AR		= ar rcs
SRC		= ft_printf.c ft_printf_char_utils.c ft_printf_nbr_utils.c ft_printf_hex_utils.c
OBJS	= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re