# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/03 13:12:40 by josemigu          #+#    #+#              #
#    Updated: 2026/04/03 13:54:03 by josemigu         ###   ########.fr        #
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

# Compiler and Flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Add -DDEBUG flag when DEBUG=1
ifdef DEBUG
    CFLAGS += -DDEBUG -g
endif

# Handle different OS configurations
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	MLX_DIR		= ./libs/minilibx-linux
	MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
	INCLUDES	= -I./includes -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -I/usr/include/X11
	CFLAGS_EXTRA = -L. -lXext -L. -lX11 -lm
endif
ifeq ($(UNAME_S),Darwin)
	MLX_DIR		= ./libs/minilibx-opengl
	MINILIBX_REPO = https://github.com/42Paris/minilibx-linux.git
	INCLUDES	= -I./includes -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -I/usr/X11/include
	CFLAGS_EXTRA = -L/usr/X11/lib -lX11 -lXext -lm
endif

# Sources and Objects
#SRCS		= $(wildcard $(SRC_DIR)/*/*.c) $(wildcard $(SRC_DIR)/*.c)
SRCS		= $(addprefix $(SRC_DIR)/, \
				algebraMath/matrixOperations.c \
				algebraMath/matrixOperations2.c \
				algebraMath/matrixOperations3.c \
				algebraMath/matrixTupleOperations.c \
				algebraMath/transformation.c \
				algebraMath/transformation2.c \
				algebraMath/tupleOperations.c \
				algebraMath/tupleOperations2.c \
				algebraMath/tupleOperations3.c \
				lighting/color.c \
				lighting/color2.c \
				lighting/lighting.c \
				lighting/shadows.c \
				main/miniRT.c \
				mlx/controls_rebuild.c \
				mlx/controls_resize.c \
				mlx/controls_rotate.c \
				mlx/controls_selection.c \
				mlx/controls_selection2.c \
				mlx/controls_transform.c \
				mlx/mlx_handlers.c \
				mlx/mlx_handlers2.c \
				mlx/mlx_utils.c \
				objects/cylinder.c \
				objects/plan.c \
				objects/sphere.c \
				objects/transform_build.c \
				parser/parse_elements.c \
				parser/parse_objects.c \
				parser/parse_objects2.c \
				parser/parse_utils.c \
				parser/parse_utils2.c \
				parser/parser.c \
				ray/create_camera_ray.c \
				ray/ray_hit_cylinder.c \
				ray/ray_hit_cylinder2.c \
				ray/ray_hit_plane.c \
				ray/ray_hit_sphere.c \
				ray/rayOperations.c \
				ray/rayTransform.c \
				render/intersection.c \
				render/render.c \
				utils/free.c \
				utils/operations_utils.c \
				utils/scene_utils.c \
				utils/utils.c \
				)
OBJS		= $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRCS:.c=.o))

# Libraries
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft
MLX			= $(MLX_DIR)/libmlx.a

# Valgrind
SCENE			?= ./scenes/amongus.rt
VALGRIND		?= valgrind
VALGRIND_SUPP	= valgrind-minilibx.supp
VALGRIND_FLAGS	= --leak-check=full --show-leak-kinds=all --track-origins=yes --suppressions=$(VALGRIND_SUPP)

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
	@if [ "$(UNAME_S)" = "Darwin" ]; then \
		open -a XQuartz 2>/dev/null || true; \
		sleep 2; \
		echo "$(YELLOW)XQuartz opened. Run: export DISPLAY=:0 && ./bin/miniRT <scene>$(RESET)"; \
	fi

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
