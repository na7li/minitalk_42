NAME = libftprintf.a

SOURCE = ft_printf.c ft_putchar.c ft_putstr.c ft_putint.c ft_putuns.c ft_putxlow.c ft_putxup.c ft_putp.c 

OBJ = $(SOURCE:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c libftprintf.h
	@cc -Wall -Wextra -Werror -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME);

re: fclean all

.PHONY: clean