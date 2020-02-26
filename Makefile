# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hvromman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/19 11:36:12 by hvromman          #+#    #+#              #
#    Updated: 2018/10/19 11:36:15 by hvromman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

HEADER_PATH = includes/
HEADER_FILES_NAMES = ft_printf.h
HEADER_FILES = $(addprefix $(HEADER_PATH), $(HEADER_FILES_NAMES))

LIBFT_PATH = libft/
LIBFT_HEADER_PATH = $(LIBFT_PATH)$(HEADER_PATH)

IS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
ft_isspace.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix is/, $(IS)))

STR = ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c \
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c \
ft_strstr.c ft_strsub.c ft_strtrim.c ft_strnjoin.c ft_indexof.c \
ft_last_indexof.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix str/, $(STR)))

LST = ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix lst/, $(LST)))

PUT = ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c \
ft_putstr_fd.c ft_putchar.c ft_putchar_fd.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix put/, $(PUT)))

MEM = ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_bzero.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_memrcpy.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix mem/, $(MEM)))

INT = ft_atoi.c ft_itoa.c ft_min.c ft_max.c ft_pow.c ft_tolower.c ft_toupper.c \
ft_atoi_base.c ft_swap.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix int/, $(INT)))

TAB = ft_tablen.c ft_free_tab.c
LIBFT_FILES += $(addprefix $(LIBFT_PATH), $(addprefix tab/, $(TAB)))

LIBFT_OBJ = $(LIBFT_FILES:.c=.o)

SRC_PATH = src/
SRC_FILES_NAMES = ft_printf.c
SRC_FILES = $(addprefix $(SRC_PATH), $(SRC_FILES_NAMES))

OBJ_FILES_NAMES = $(SRC_FILES_NAMES:.c=.o)
OBJ_FILES = $(addprefix $(SRC_PATH), $(OBJ_FILES_NAMES)) $(LIBFT_OBJ)

MAIN = main.c
MAIN_OBJ = $(MAIN:.c=.o)

RED=\033[0;91m
GREEN=\033[0;92m
CYAN=\033[0;96m
NC=\033[0m

all: $(NAME)

%.o: %.c $(HEADER_FILES)
	@$(CC) $(CFLAGS) -c -o $@ $< -I $(HEADER_PATH) -I $(LIBFT_HEADER_PATH)

$(NAME): $(OBJ_FILES)
	ar rcs $@ $^
	@echo "$(RED)$(NAME) compiled$(NC)"

main: $(MAIN_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o test $(MAIN_OBJ) $(NAME)

clean:
	@rm -f $(OBJ_FILES)
	@rm -f $(MAIN_OBJ)
	@echo "$(GREEN)$(NAME) cleaned$(NC)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) fcleaned$(NC)"

debug: $(MAIN_OBJ) $(NAME)
	$(CC) $(CFLAGS) -o $@ $(MAIN_OBJ) $(NAME) -fsanitize=address
	@echo "$(RED)$@ compiled$(NC)"

re: fclean all
