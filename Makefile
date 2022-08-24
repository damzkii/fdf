# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahermawa <ahermawa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 11:39:50 by ahermawa          #+#    #+#              #
#    Updated: 2022/08/24 16:20:32 by ahermawa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf

H_FOLDER		=	includes
C_FOLDER		=	src
OBJ_FOLDER		=	obj
FOLDER_LIST		=	$(H_FOLDER) $(C_FOLDER) $(OBJ_FOLDER)

H_FILES			=	$(NAME).h
C_FILES			=	main.c read_map.c utils.c

H_PATHS			=	$(addprefix $(H_FOLDER)/, $(H_FILES))
C_PATHS			=	$(addprefix $(C_FOLDER)/, $(C_FILES))
OBJ_PATHS		=	$(addprefix $(OBJ_FOLDER)/, $(patsubst %.c, %.o, $(C_FILES)))

C_FLAGS			=	-Wall -Wextra -Werror 
C_FLAGS			+=	-g
LIB_A			= 	libft/libft.a

.PHONY: all
all: $(NAME)

$(NAME): pre_requisites $(OBJ_PATHS) Makefile
	@touch pre_requisites
	@make -C libft
	clang $(C_FLAGS) $(LIB_A) -I $(H_FOLDER) -o $@ $(OBJ_PATHS)

$(OBJ_PATHS): $(OBJ_FOLDER)/%.o:$(C_FOLDER)/%.c $(H_PATHS) Makefile
	clang $(C_FLAGS) -I $(H_FOLDER) -c $< -o $@

pre_requisites: $(FOLDER_LIST) $(H_PATHS) $(C_PATHS)

$(FOLDER_LIST):
	mkdir $@

$(H_PATHS):
	touch $@

$(C_PATHS):
	touch $@

.PHONY: print_files
print_files:
	@echo "H paths:   $(H_PATHS)"
	@echo "C paths:   $(C_PATHS)"
	@echo "OBJ paths: $(OBJ_PATHS)"
	@echo "C flags:   $(C_FLAGS)"
	@echo ""

.PHONY: clean
clean:
	-@rm -f $(OBJ_PATHS)
	@echo "All object files are removed!"

.PHONY: fclean
fclean: clean
	-@rm -f $(NAME)
	@echo "$(NAME) file is removed!"

.PHONY: re
re: fclean all