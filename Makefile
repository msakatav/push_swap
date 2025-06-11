# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakata <msakata@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/24 23:21:33 by msakata           #+#    #+#              #
#    Updated: 2025/06/05 02:50:42 by msakata          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
COMMON_SRC =	common_src/error_handling.c \
				common_src/sorted.c

PUSH_SWAP_SRCS =	src/atol.c \
					src/check_num.c \
					src/chunksort_phase1.c \
					src/chunksort_phase2.c \
					src/main.c \
					src/minmun_sort.c \
					src/normalize.c \
					src/push_chunks_to_b.c \
					src/push_to_a.c \
					src/selection_sort.c \
					src/sort.c \
					src/stack_init.c \
					src/rotate.c \
					src/reverse_rotate.c \
					src/push.c \
					src/swap.c

CHECKER_SRC =	bonus_src/execute_command.c \
				bonus_src/main_bonus.c \
				bonus_src/stack_init_bonus.c \
				bonus_src/push_bonus.c \
				bonus_src/reverse_rotate_bonus.c \
				bonus_src/rotate_bonus.c \
				bonus_src/swap_bonus.c \
				get_next_line/get_next_line.c \
				get_next_line/get_next_line_utils.c \

MANDATORY_SRC = $(PUSH_SWAP_SRCS) $(COMMON_SRC)
BONUS_SRC     = $(CHECKER_SRC) $(COMMON_SRC)

LIB_DIR = ft_printf
LIB_NAME = libftprintf.a
LIB_PATH = $(LIB_DIR)/$(LIB_NAME)
LIB_LINK = -L$(LIB_DIR) -lftprintf

INCLUDES = -I. -I$(LIB_DIR) -Ift_printf/libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -g $(INCLUDES)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(LIB_PATH) $(NAME)

$(LIB_PATH):
	$(MAKE) -C $(LIB_DIR)

$(NAME): $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(MANDATORY_OBJ) $(LIB_LINK)

bonus: $(LIB_PATH) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJ) $(LIB_LINK)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(MANDATORY_OBJ) $(BONUS_OBJ)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re
