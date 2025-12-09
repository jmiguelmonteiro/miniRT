# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/06 15:17:48 by josemigu          #+#    #+#              #
#    Updated: 2025/12/09 12:48:31 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RED		= \033[0;31m
GREEN	= \033[0;32m
BLUE	= \033[0;34m
D_BLUE	= \033[34m
WHITE	= \033[0;37m
YELLOW	= \033[0;33m
MAGENTA	= \033[0;35m
CYAN	= \033[3;36m
RESET	= \033[0m

# Program's name
NAME		= bin/miniRT

# Directories
SRC_DIR		= ./srcs
OBJ_DIR		= objs
BIN_DIR		= bin
LIBFT_DIR	= ./libs/libft
MLX_DIR		= ./libs/minilibx-linux

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
INCLUDES	= -I./includes -I$(LIBFT_DIR)/includes -I$(MLX_DIR)

# Handle different OS configurations
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	INCLUDES += -I/usr/include/X11
	CFLAGS_EXTRA = -L. -lXext -L. -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	INCLUDES += -I/opt/X11/include
	CFLAGS_EXTRA = -L/opt/X11/lib -lX11 -lXext -lXrandr -lXcursor -lXinerama -lXxf86vm -lXrender -lX11-xcb -lXfixes -lm
endif

# Sources and Objects
SRCS		= $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft
MLX			= $(MLX_DIR)/libmlx.a

# MinilibX
MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git

# ASCII Art
define ART
$(MAGENTA)${D_BLUE}
	███╗   ███╗██╗███╗   ██╗██╗██████╗ ████████╗
	████╗ ████║██║████╗  ██║██║██╔══██╗╚══██╔══╝
	██╔████╔██║██║██╔██╗ ██║██║██████╔╝   ██║
	██║╚██╔╝██║██║██║╚██╗██║██║██╔══██╗   ██║
	██║ ╚═╝ ██║██║██║ ╚████║██║██║  ██║   ██║
	╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═╝  ╚═╝   ╚═╝
  $(CYAN)━━━━━━━━━━━━━━━━━━━━━━━━━━━[$(RESET)Ray Tracing Engine$(CYAN)]━━━━━━━━━━━━━━━━━━━━━━━━━━━$(RESET)
endef
export ART

# Rules
all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS)
	@mkdir -p $(BIN_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(LIBFT) $(INCLUDES) $(LIBFT_FLAGS) $(CFLAGS_EXTRA) -o $(NAME)
	@clear
	@echo "$$ART"
	@echo "$(CYAN)miniRT compiled successfully!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@sleep 0.02
	@clear
	@echo "$(RED)Compiling miniRT sources $<$(RESET)"

clone_mlbx:
	@if [ ! -d "$(MLX_DIR)" ]; then \
		mkdir -p ./libs; \
		echo "$(YELLOW)Cloning MiniLibX...$(RESET)"; \
		git clone $(MINILIBX_REPO) $(MLX_DIR); \
		echo "$(GREEN)MiniLibX cloned successfully!$(RESET)"; \
	fi

$(LIBFT):
	@echo "$(YELLOW)Making libft...$(RESET)"
	@make --silent -C $(LIBFT_DIR)

$(MLX): clone_mlbx
	@if [ ! -f "$(MLX)" ]; then \
		echo "$(YELLOW)Making MiniLibX...$(RESET)"; \
		make --silent -C $(MLX_DIR) > /dev/null 2>&1; \
	fi

clean:
	@clear
	@make --silent -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then make --silent -C $(MLX_DIR) > /dev/null 2>&1 clean; fi
	@rm -rf $(OBJ_DIR)
	@rm -rf $(MLX_DIR)
	@echo "$(GREEN)Object files removed!$(RESET)"

fclean: clean
	@make --silent -C $(LIBFT_DIR) fclean
	@rm -rf $(BIN_DIR)
	@echo "$(GREEN)miniRT removed!$(RESET)"

re: fclean all

.PHONY: all clean fclean re clone_mlbx
