# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 16:20:14 by psanguna          #+#    #+#              #
#    Updated: 2024/05/07 16:20:18 by psanguna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB = ar -rcs
RM = rm -f

NAME = libftprintf.a

SOURCE_FILES = ft_printf.c ft_analyze_structure.c ft_display_structure.c ft_display_chars.c\
	ft_display_str.c ft_display_digit.c ft_helpers.c
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
