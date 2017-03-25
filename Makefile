# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thou <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/07 16:17:53 by thou              #+#    #+#              #
#    Updated: 2017/03/25 11:04:47 by thou             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK					=	\033[30;1m
RED						=	\033[31;1m
GREEN					=	\033[32;1m
YELLOW					=	\033[33;1m
BLUE					=	\033[34;1m
PURPLE					=	\033[35;1m
CYAN					=	\033[36;1m
WHITE					=	\033[37;1m
RESET					=	\033[0m
CLEAR					=	\033[H\e[J

NAME		=	libftprintf.a
FLAG		=	-Wall -Wextra -Werror
INC			=	-Iincludes -Ilibft/includes
SRC_DIR		=	src/
SRC_BASE	=	ft_printf.c ft_vfprintf.c ft_printf0.c
SRC			=	$(addprefix $(SRC_DIR), $(SRC_BASE))
OBJ_DIR		=	obj/
OBJ			=	$(addprefix $(OBJ_DIR), $(SRC_BASE:.c=.o))
LIB			=	libft
LIB_SRC_DIR	=	$(LIB)/src/
LIB_SRC_BASE=	libc/ft_tolower.c\
				libc/ft_strlen.c\
				supplementaire/ft_putnbr.c\
				supplementaire/ft_putchar.c\
				supplementaire/ft_putchar_fd.c\
				autres/ft_itoa_base.c
LIB_OBJ_DIR	=	$(LIB)/obj/
LIB_SRC		=	$(addprefix $(LIB_SRC_DIR), $(LIB_SRC_BASE))
LIB_OBJ		=	$(addprefix $(LIB_OBJ_DIR), $(LIB_SRC_BASE:.c=.o))


all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	@ar rvc $(NAME) $(OBJ) $(LIB_OBJ)
	@ranlib $(NAME)
	@echo "\033[48;5;15;38;5;25;1mMAKE $(NAME) DONE$(RESET)"

$(LIB_OBJ_DIR)%.o : $(LIB_SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAG) -o $@ -c $< $(INC)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAG) -o $@ -c $< $(INC)

clean:
	@rm -rf $(LIB_OBJ_DIR)
	@rm -rf $(OBJ_DIR)
	@echo "$(YELLOW)Clean	./obj$(GREEN)			[ OK ]$(RESET)"


fclean: clean
	@rm -rf $(NAME)
	@echo "$(YELLOW)Clean	$(NAME)$(GREEN)		[ OK ]$(RESET)"

re: fclean all
