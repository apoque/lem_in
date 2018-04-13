# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: srossi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/05 18:08:37 by srossi            #+#    #+#              #
#    Updated: 2018/04/13 11:35:54 by srossi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC = gcc
CFLAGS = -Wall -Wextra -Werror
ADDFLAGS =

# DEFAULT RULE
DEFRULE = all

# BINARY
NAME = lem-in
DST =


# PATHS
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
LIBFT_PATH = ./libft/
MLX_PATH = ./minilibx/
INC_PATH = includes\
		   minilibx\
		   libft/includes


# SOURCES
SRC_NAME = \
		   main.c \
		   ft_error.c \
		   ft_parse.c

OBJ_NAME = $(SRC_NAME:.c=.o)


# PREFIXES
SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))


# FLAGS
MLX = -lmlx -framework OpenGL -framework AppKit
CPPFLAGS = -I./includes/
LDFLAGS = -L./libft/
LFT = -lft
LIBFT = $(LDFLAGS) $(LFT)

# **************************************************************************** #
# SPECIAL CHARS

LOG_CLEAR= \033[2K
LOG_UP= \033[A
LOG_NOCOLOR= \033[0m
LOG_BOLD= \033[1m
LOG_UNDERLINE= \033[4m
LOG_BLINKING= \033[5m
LOG_BLACK= \033[1;30m
LOG_RED= \033[1;31m
LOG_GREEN= \033[1;32m
LOG_YELLOW= \033[1;33m
LOG_BLUE= \033[1;34m
LOG_MAGENTA= \033[1;35m
LOG_CYAN= \033[1;36m
LOG_WHITE= \033[1;37m
LOG_ORANGE= \033[1;38;5;208m

# **************************************************************************** #

# RULES

# MAIN RULES
default:
	@make $(DEFRULE)

.PHONY: all
all: libftcomp $(OBJ_PATH) $(NAME)
#all: $(OBJ_PATH) $(NAME)
#all: mlibxcomp libftcomp $(OBJ_PATH) $(NAME)

libftcomp:
	@make all -C $(LIBFT_PATH)

#mlibxcomp:
#	@make all -C $(MLX_PATH)

$(NAME): $(OBJ)
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)....................... $(LOG_ORANGE)assembling$(LOG_NOCOLOR)$(LOG_UP)"
	@$(CC) $(CFLAGS) $(ADD_FLAGS) $(LIBFT) $(OBJ) $(MLX) -o $@
	@echo -e "--$(LOG_CLEAR)$(LOG_CYAN)$(NAME)$(LOG_NOCOLOR) compiled................. $(LOG_GREEN)✓$(LOG_NOCOLOR)"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo -e "--$(LOG_CLEAR)$(LOG_MAGENTA)$(NAME)$(LOG_NOCOLOR)........................ $(LOG_YELLOW)$<$(LOG_NOCOLOR)$(LOG_UP)"
	@sleep 2
	@$(CC) $(CFLAGS) $(CPPFLAGS) $(ADDFLAGS) -c -o $@ $^

$(OBJ_PATH):
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)build $(NAME)$(LOG_NOCOLOR)"
	@mkdir -p $(OBJ_PATH)

.PHONY: clean
clean:
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -rf $(OBJDIR)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)clean libft$(LOG_NOCOLOR)"
	@make clean -C $(LIBFT_PATH)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: fclean
fclean: clean
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean libft$(LOG_NOCOLOR)"
	@make fclean -C $(LIBFT_PATH)
	@echo -e "$(LOG_CLEAR)$(LOG_BLUE)fclean $(NAME)$(LOG_NOCOLOR)"
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Objects$(LOG_NOCOLOR) deleted.............. $(LOG_RED)×$(LOG_NOCOLOR)"
	@rm -f $(NAME)
	@echo -e "--$(LOG_CLEAR)$(LOG_YELLOW)Binary$(LOG_NOCOLOR) deleted............... $(LOG_RED)×$(LOG_NOCOLOR)"

.PHONY: re
re: fclean all

norme:
	norminette $(SRC)
	norminette ./includes/*.h

