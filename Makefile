NAME= minitalk
CC= gcc
CFLAGS= -Wall -Wextra -Werror
RM= rm -rf

LIBFTDIR= libft
LIBFT= $(LIBFTDIR)/libft.a
FT_PRINTF_DIR= ft_printf
FT_PTINF= $(FT_PRINTF_DIR)/libftprintf.a
SRC= server.c client.c
OBJ= $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): server client

server: $(LIBFT) $(FT_PTINF) server.o
	@$(CC) $(CFLAGS) $^ -o $@

client: $(LIBFT) $(FT_PTINF) client.o
	@$(CC) $(CFLAGS) $^ -o $@

$(LIBFT):
	@make -C $(LIBFTDIR)

$(FT_PTINF):
	@make -C $(FT_PRINTF_DIR)

%.o: %.c minitalk.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(FT_PRINTF_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@make fclean -C $(FT_PRINTF_DIR)
	@$(RM) server client

re: fclean all

.Phony: clean $(LIBFT) $(FT_PTINF)