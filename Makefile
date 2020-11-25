# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaye <kaye@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/25 22:45:37 by kaye              #+#    #+#              #
#    Updated: 2020/11/26 00:18:20 by kaye             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION

CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror
IFLAGS 		= -I./inc_pf -I./libft/inc

# DIRECTORIES

LIBFT_DIR 	:= libft
INC_DIR	 	:= inc_pf
SRC_DIR  	:= src_pf
SUB_DIR		:= printf_family
OBJ_DIR	 	:= .obj_pf
DIRS		:= $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SRC_DIR)) \
			   $(addprefix $(OBJ_DIR)/$(SRC_DIR)/, $(SUB_DIR))

# FILES
LIBFT 		:= $(LIBFT_DIR)/libft.a
NAME 		:= libftprintf.a
SRC			:= ft_printf.c
SUB_SRC 	:= ft_convert_utils.c \
			   ft_convert.c \
			   ft_parse_char.c \
			   ft_parse_flag_width.c \
			   ft_parse_flag.c \
			   ft_parse_hex.c \
			   ft_parse_int.c \
			   ft_parse_pointer.c \
			   ft_parse_string.c \
			   ft_parse_uint.c \
			   ft_parse.c \
			   ft_process.c \
			   ft_utils_pf.c
SRC			+= $(addprefix $(SRC_DIR)/, $(SUB_SRC))
SUB_SRC		:= ft_vprintf.c
SRC			+= $(addprefix $(SRC_DIR)/printf_family/, $(SUB_SRC))
OBJ			:= $(SRC:%.c=$(OBJ_DIR)/%.o)


# COLORS

DEFAULT_COLOR	= \033[0m
BLACK_COLOR		= \033[1;30m
RED_COLOR		= \033[1;31m
GREEN_COLOR		= \033[1;32m
YELLOW_COLOR	= \033[1;33m
BLUE_COLOR		= \033[1;34m
MAGENTA_COLOR 	= \033[1;35m
CYAN_COLOR 		= \033[1;36m
WHITE_COLOR 	= \033[1;107m

# MAKEFILE

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "Copy and rename $(RED_COLOR)libft.a $(DEFAULT_COLOR)on $(RED_COLOR)$@ $(DEFAULT_COLOR)..."
	@cp $(LIBFT) $@
	@echo "Updating $(RED_COLOR)$@ $(DEFAULT_COLOR)..."
	@ar -rcs $@ $^
	@echo "$(GREEN_COLOR)Update $(YELLOW_COLOR)of $(RED_COLOR)$@ $(BLUE_COLOR)done$(DEFAULT_COLOR)"

all: $(NAME)

clean:
	@echo "$(CYAN_COLOR)Do $(DEFAULT_COLOR)-> $(CYAN_COLOR)clean $(DEFAULT_COLOR)of libft"
	@make clean -C $(LIBFT_DIR)
	@echo "$(CYAN_COLOR)Remove $(DEFAULT_COLOR)-> $(CYAN_COLOR)$(OBJ_DIR)$(DEFAULT_COLOR)"
	rm -Rf $(OBJ_DIR)

fclean: clean
	@echo "$(CYAN_COLOR)Do $(DEFAULT_COLOR)-> $(CYAN_COLOR)fclean $(DEFAULT_COLOR)of libft"
	@make fclean -C $(LIBFT_DIR)
	@echo "$(CYAN_COLOR)Remove $(DEFAULT_COLOR)-> $(CYAN_COLOR)$(NAME)$(DEFAULT_COLOR)"
	rm -Rf $(NAME)

re: fclean all

$(OBJ_DIR):
	@echo "Creating $(RED_COLOR)$@ $(DEFAULT_COLOR)..."
	@mkdir $(DIRS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@echo "Compiling $(MAGENTA_COLOR)$< $(DEFAULT_COLOR)..."
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

.PHONY: all clean fclean re