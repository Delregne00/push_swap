# Variables
NAME = push_swap
BONUS_NAME = checker_exec

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_DIR = src
CHECKER_DIR = checker
LIBFT_DIR = libft
FT_PRINTF_DIR = $(LIBFT_DIR)/ft_printf
INCLUDES_DIR = includes
CHECKER_INCLUDES_DIR = $(CHECKER_DIR)/includes

SRCS = main.c \
       $(SRC_DIR)/control.c \
       $(SRC_DIR)/cost.c \
       $(SRC_DIR)/instruccions.c \
       $(SRC_DIR)/list.c \
       $(SRC_DIR)/move_to_a.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/push.c \
       $(SRC_DIR)/put_node.c \
       $(SRC_DIR)/reverse_rotate.c \
       $(SRC_DIR)/rotate.c \
       $(SRC_DIR)/sort.c \
       $(SRC_DIR)/sort_five.c \
       $(SRC_DIR)/parsing.c \
       $(SRC_DIR)/swap.c \
       $(SRC_DIR)/check_list.c \

BONUS_SRCS = $(CHECKER_DIR)/main_bonus.c \
             $(CHECKER_DIR)/list_bonus.c \
             $(CHECKER_DIR)/push_bonus.c \
             $(CHECKER_DIR)/rotate_bonus.c \
             $(CHECKER_DIR)/reverse_rotate_bonus.c \
             $(CHECKER_DIR)/swap_bonus.c \


LIBFT_SRCS = $(LIBFT_DIR)/ft_atoi.c \
             $(LIBFT_DIR)/ft_atoll.c \
             $(LIBFT_DIR)/ft_bzero.c \
             $(LIBFT_DIR)/ft_calloc.c \
             $(LIBFT_DIR)/ft_isacii.c \
             $(LIBFT_DIR)/ft_isalnum.c \
             $(LIBFT_DIR)/ft_isalpha.c \
             $(LIBFT_DIR)/ft_isdigit.c \
             $(LIBFT_DIR)/ft_isprint.c \
             $(LIBFT_DIR)/ft_itoa.c \
             $(LIBFT_DIR)/ft_memchr.c \
             $(LIBFT_DIR)/ft_memcmp.c \
             $(LIBFT_DIR)/ft_memcpy.c \
             $(LIBFT_DIR)/ft_memmove.c \
             $(LIBFT_DIR)/ft_memset.c \
             $(LIBFT_DIR)/ft_putchar_fd.c \
             $(LIBFT_DIR)/ft_putendl_fd.c \
             $(LIBFT_DIR)/ft_putnbr_fd.c \
             $(LIBFT_DIR)/ft_putstr_fd.c \
             $(LIBFT_DIR)/ft_split.c \
             $(LIBFT_DIR)/ft_strchr.c \
             $(LIBFT_DIR)/ft_strdup.c \
             $(LIBFT_DIR)/ft_striteri.c \
             $(LIBFT_DIR)/ft_strjoin.c \
             $(LIBFT_DIR)/ft_strlcat.c \
             $(LIBFT_DIR)/ft_strlcpy.c \
             $(LIBFT_DIR)/ft_strlen.c \
             $(LIBFT_DIR)/ft_strmapi.c \
             $(LIBFT_DIR)/ft_strncmp.c \
             $(LIBFT_DIR)/ft_strncpy.c \
             $(LIBFT_DIR)/ft_strnstr.c \
             $(LIBFT_DIR)/ft_strrchr.c \
             $(LIBFT_DIR)/ft_strtrim.c \
             $(LIBFT_DIR)/ft_substr.c \
             $(LIBFT_DIR)/ft_tolower.c \
             $(LIBFT_DIR)/ft_toupper.c \
             $(LIBFT_DIR)/get_next_line.c \
             $(LIBFT_DIR)/get_next_line_utils.c

FT_PRINTF_SRCS = $(FT_PRINTF_DIR)/src/ft_printf.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_char.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_hex.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_int.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_percent.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_pointer.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_str.c \
                 $(FT_PRINTF_DIR)/src/conversions/print_uint.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_itoa.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_strdup.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_putchar.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_putstr.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_strlen.c \
                 $(FT_PRINTF_DIR)/src/utils/ft_uitoa.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -I$(INCLUDES_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -I$(INCLUDES_DIR) -I$(CHECKER_INCLUDES_DIR)

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF): $(FT_PRINTF_SRCS)
	@$(MAKE) -C $(FT_PRINTF_DIR)

%.o: %.c $(INCLUDES_DIR)/push_swap.h $(INCLUDES_DIR)/checker.h $(INCLUDES_DIR)/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDES_DIR) -I$(CHECKER_INCLUDES_DIR)

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
