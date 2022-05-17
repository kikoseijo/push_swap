# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:10:17 by jseijo-p          #+#    #+#              #
#    Updated: 2022/05/17 19:14:58 by jseijo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g -Og

SOURCES = push_swap.c helpers.c

OBJECTS = $(subst .c,.o,$(SOURCES))

FLAGS = -Wall -Wextra -Werror
FLAGS_DEBUG = -Wall -Wextra -Werror -g3
INC_LIBS = -Llibft -lft
LINKS = -I libft -L libft

all: $(NAME)

%.o: %.c
	gcc $(FLAGS_DEBUG) -c $< -o $@

$(NAME): $(OBJECTS)
	$(MAKE) -C libft
	gcc $(OBJECTS) $(INC_LIBS) -o $(NAME)

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean
	$(MAKE)

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard *.c} ${wildcard *.h} ${wildcard libft/*.c} ${wildcard libft/*.h}

.PHONY: clean fclean re all
