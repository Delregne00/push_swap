NAME = checker_exec

CC = gcc
CFLAGS = -g -Wall -Wextra -Werror

SRC_DIR = .
INCLUDES_DIR = ../includes
CHECKER_INCLUDES_DIR = includes
LIBFT_DIR = ../libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf

SRCS = main_bonus.c \
       list_bonus.c \
       push_bonus.c \
       rotate_bonus.c \
       reverse_rotate_bonus.c \
       swap_bonus.c \

OBJS = $(SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -I$(INCLUDES_DIR) -I$(CHECKER_INCLUDES_DIR)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c $(CHECKER_INCLUDES_DIR)/checker.h $(INCLUDES_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES_DIR) -I$(CHECKER_INCLUDES_DIR)

clean:
	rm -f $(OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
