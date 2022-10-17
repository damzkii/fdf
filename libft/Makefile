# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/11 17:52:26 by ahermawa          #+#    #+#              #
#    Updated: 2022/09/25 14:57:13 by ahermawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

C_FOLDER = src
H_FOLDER = includes
O_FOLDER = obj
FOLDER_LIST = $(C_FOLDER) $(H_FOLDER) $(O_FOLDER)

H_FILES = libft.h
C_FILES = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memdel.c \
		ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_strcat.c ft_strchr.c \
		ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_striter.c ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c \
		ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_memcpy.c \
		ft_memmove.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_itoa.c ft_intlen.c ft_free_arr.c ft_strsplit.c ft_strnstr.c \
		ft_strlcat.c ft_lstnew.c ft_lstdel.c ft_lstdelone.c ft_lstadd.c ft_lstiter.c \
		ft_lstmap.c ft_strrev.c ft_revprint.c ft_isspace.c get_next_line.c ft_free.c
H_PATHS = $(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS = $(addprefix $(C_FOLDER)/, $(C_FILES))
O_PATHS = $(addprefix $(O_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

CC = gcc
C_FLAGS = -Wall -Wextra -Werror

.PHONY: all
all: $(NAME)

$(NAME): pre_requisites $(O_PATHS)
	@ar rcs $(NAME) $(O_PATHS)

$(O_PATHS): $(O_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS)
	cc $(C_FLAGS) -I $(H_FOLDER) -c $< -o $@

pre_requisites: $(FOLDER_LIST) $(H_PATHS) $(C_PATHS)

$(FOLDER_LIST):
	@mkdir $@

$(H_PATHS):
	@touch $@

$(C_PATHS):
	@touch $@

.PHONY: clean
clean:
	@rm -f $(O_PATHS)

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)
	-@rm -df $(O_FOLDER)

.PHONY: re
re: fclean all

.PHONY: all clean fclean re
