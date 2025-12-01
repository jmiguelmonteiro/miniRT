# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: josemigu <josemigu@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/01 13:04:36 by josemigu          #+#    #+#              #
#    Updated: 2025/07/09 12:53:45 by josemigu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Paths
LIBFT_PATH		= libft
GNL_PATH		= gnl
PRINTF_PATH		= ft_printf
INCLUDES_PATH	= includes
BUILD_PATH		= build

# Sources
SRCS_LIBFT = $(addprefix $(LIBFT_PATH)/, \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
		ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
		ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
		ft_lstbeforelast.c ft_atof.c ft_isspace.c ft_strjoin_free.c)
SRCS_GNL = $(addprefix $(GNL_PATH)/, \
		get_next_line_bonus.c )
SRCS_PRINTF = $(addprefix $(PRINTF_PATH)/, \
		ft_printf_base.c ft_printf_chr.c ft_printf_int.c ft_printf_ptr.c \
		ft_printf_str.c	ft_printf.c )

# Objects
OBJS_LIBFT	= $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS_LIBFT:.c=.o)))
OBJS_GNL	= $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS_GNL:.c=.o)))
OBJS_PRINTF	= $(addprefix $(BUILD_PATH)/, $(notdir $(SRCS_PRINTF:.c=.o)))
OBJS		= $(OBJS_LIBFT) $(OBJS_GNL) $(OBJS_PRINTF)

# Commands
CC			= cc
INCLUDES	= -I$(INCLUDES_PATH)
CFLAGS		= -Wall -Wextra -Werror $(INCLUDES) -g
AR			= ar crs
RM			= rm -f
MKDIR-P		= mkdir -p

# Rules
all: ${NAME}

$(BUILD_PATH):
	$(MKDIR-P) $(BUILD_PATH)

$(BUILD_PATH)/%.o: $(LIBFT_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(GNL_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_PATH)/%.o: $(PRINTF_PATH)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(BUILD_PATH) $(OBJS)
	@echo "* $(YEL)Archiving $(NAME) archive$(D)"
	$(AR) $(NAME) $(OBJS)
	@echo "✅ Libft created with success."
		
clean: 
	${RM} ${OBJS}
	@echo "✅ Cleaned objects with success."

fclean: clean
	${RM} ${NAME}
	@echo "✅ Cleaned library with success."

re: fclean all

.PHONY: all clean fclean re
