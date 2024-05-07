# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 16:09:00 by psanguna          #+#    #+#              #
#    Updated: 2024/05/07 16:09:08 by psanguna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

NAME = libftprintf.a

SOURCE_FILES = ft_printf_bonus.c ft_analyze_structure_bonus.c ft_display_structure_bonus.c ft_display_char_bonus.c\
	ft_display_str_bonus.c ft_display_digit_bonus.c ft_helpers_bonus.c ft_digit_helper_bonus.c ft_print_chars_bonus.c
OBJECT_FILES = $(SOURCE_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECT_FILES)
	@$(LIB) $(NAME) $(OBJECT_FILES)


clean:
	$(RM) $(OBJECT_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
