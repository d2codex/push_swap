# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diade-so <diade-so@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/18 15:38:17 by diade-so          #+#    #+#              #
#    Updated: 2025/07/06 16:48:02 by diade-so         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                               Compiler & Flags                               #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -g3
INCLUDES = -I./libft -I./includes

# **************************************************************************** #
#                                 Target Name                                  #
# **************************************************************************** #

NAME = push_swap

# **************************************************************************** #
#                                 Directories                                  #
# **************************************************************************** #

SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
BONUS_DIR = bonus

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, main.c parse.c validate.c array_utils.c \
      duplicate.c stack_utils.c memory_utils.c swap.c push.c push_utils.c \
      rotate.c reverse_rotate.c sort_small.c sort_large.c calculations1.c\
      calculations2.c calculations3.c)

SHARED = parse.c validate.c array_utils.c duplicate.c \
	 stack_utils.c memory_utils.c swap.c push.c push_utils.c rotate.c \
	 reverse_rotate.c 

BONUS_SRC = $(addprefix $(BONUS_DIR)/, main_bonus.c checker_bonus.c \
	    operations_bonus.c)

# **************************************************************************** #
#                                Object Files                                  #
# **************************************************************************** #

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

SHARED_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SHARED:.c=.o)))

BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

ALL_BONUS_OBJ = $(BONUS_OBJ) $(SHARED_OBJ)

# **************************************************************************** #
#                                    Libft                                     #
# **************************************************************************** #

LIBFT = $(LIBFT_DIR)/libft.a

# **************************************************************************** #
#                                   Rules                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(ALL_BONUS_OBJ)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(ALL_BONUS_OBJ) $(LIBFT) -o my_checker

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) my_checker

re: fclean all

.PHONY: all clean fclean re bonus
