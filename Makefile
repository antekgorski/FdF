# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:35:59 by agorski           #+#    #+#              #
#    Updated: 2025/01/09 20:28:41 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRCS = draw_utils.c free_utils.c main.c map_reader.c mlx_utils.c utils.c
CC = cc
CFLAGS = -Wall -Wextra -Werror -L minilibx-linux -lmlx -lX11 -lXext -L libft -lft -lm
TESTFLAGS = -g

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

test:
	$(CC) $(CFLAGS) $(TESTFLAGS) $(SRCS) -o $(NAME)

retest: fclean test

.phony: all clean fclean re test retest
