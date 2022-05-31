# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jseijo-p <jseijo-p@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/17 19:10:17 by jseijo-p          #+#    #+#              #
#    Updated: 2022/05/31 15:24:33 by jseijo-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

HEAD := -I inc/

FLAGS = -Wall -Wextra -Werror -g -Og
#FLAGS = -fsanitize=address -Wall -Wextra -Werror
#FLAGS = -Wall -Wextra -Werror
#FLAGS = -fsanitize=address

SOURCES = src/array_functions.c \
					src/ft_push.c \
					src/ft_reverse_rotate.c \
					src/ft_rotate.c \
					src/ft_swap.c \
					src/helpers.c \
					src/initialize.c \
					src/op_functions.c \
					src/parser.c \
					src/push_swap.c \
					src/sort.c \
					src/sort_case.c \
					src/stack_functions.c

BONUS_SOURCES = src/array_functions.c \
					src/ft_push.c \
					src/ft_reverse_rotate.c \
					src/ft_rotate.c \
					src/ft_swap.c \
					src/helpers.c \
					src/initialize.c \
					src/op_functions.c \
					src/parser.c \
					src/checker.c

OBJECTS	=	$(addprefix objs/, $(SOURCES:.c=.o))
BONUS_OBJECTS	=	$(addprefix bonus_objs/, $(BONUS_SOURCES:.c=.o))

FLAGS_DEBUG = -Wall -Wextra -Werror -g3
INC_LIBS = -Llibft -lft
LINKS = -I libft -L libft -L inc

all: $(NAME) bonus

objs/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) $(HEAD) -c $< -o $@

bonus_objs/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) $(HEAD) -c $< -o $@

$(NAME):	$(OBJECTS)
	@$(MAKE) -C libft
	@gcc $(OBJECTS) $(INC_LIBS) -o $(NAME)
	@echo "Makefile: build success, happy coding!"

bonus: $(BONUS_OBJECTS)
	@$(MAKE) -C libft
	@gcc $(BONUS_OBJECTS) $(INC_LIBS) -o checker

clean:
	@rm -rf $(OBJECTS)
	@rm -rf $(BONUS_OBJECTS)

fclean: clean
	@rm -f $(NAME)
	@rm -f checker

re: fclean
	@$(MAKE)

norme:
	norminette -R CheckForbiddenSourceHeader ${wildcard *.c} ${wildcard *.h} ${wildcard libft/*.c} ${wildcard libft/*.h}

.PHONY: clean fclean re all
