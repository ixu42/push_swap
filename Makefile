# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ixu <ixu@student.hive.fi>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/13 10:59:00 by ixu               #+#    #+#              #
#    Updated: 2023/12/20 15:23:38 by ixu              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the programs
NAME := push_swap
NAME_BONUS := checker

# Compiler and flags
CC := cc
CFLAGS := -Wall -Wextra -Werror

# Color scheme
COLOR_BLUE := \033[0;34m
COLOR_WHITE := \033[0;37m
COLOR_BRIGHT_WHITE := \033[0;97m
COLOR_END := \033[0m

# Directory locations
SRCS_DIR := srcs/
OBJS_DIR := objs/
LIBFT_DIR := libft/

SRCS := main.c \
		split.c \
		str_to_long.c \
		input_validation.c \
		stack_init.c \
		free_mem.c \
		cmd_swap.c \
		cmd_rotate.c \
		cmd_r_rotate.c \
		cmd_push.c \
		sort.c \
		sort_utils.c \
		min_cost_node.c \
		min_cost_node_utils.c

SRCS_BONUS := checker.c \
				split.c \
				str_to_long.c \
				input_validation.c \
				stack_init.c \
				free_mem.c \
				cmd_swap.c \
				cmd_rotate.c \
				cmd_r_rotate.c \
				cmd_push.c \
				sort_utils.c

OBJS := $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS := $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

LIBFT := $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(CC) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft
	@echo "$(COLOR_BRIGHT_WHITE)$(NAME) created$(COLOR_END)"

bonus: .bonus

.bonus: $(OBJS_DIR) $(OBJS_BONUS)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) -L$(LIBFT_DIR) -lft
	@touch .bonus
	@echo "$(COLOR_BRIGHT_WHITE)$(NAME_BONUS) created$(COLOR_END)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(COLOR_WHITE)$(OBJS_DIR) directory created$(COLOR_END)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -fr $(OBJS_DIR)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean
	@rm -f .bonus
	@echo "$(COLOR_BLUE)$(OBJS_DIR) directory and object files removed$(COLOR_END)"
	@echo "$(COLOR_BLUE)$(LIBFT) and libft object files removed$(COLOR_END)"
 
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(COLOR_BLUE)$(NAME) and/or $(NAME_BONUS) removed$(COLOR_END)"

re: fclean all