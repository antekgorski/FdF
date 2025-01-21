# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:35:59 by agorski           #+#    #+#              #
#    Updated: 2025/01/21 01:22:50 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./fdf ./.test_maps/mars.fdf

NAME = fdf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS =	draw_utils.c draw.c free_utils.c main.c map_reader.c mlx_utils.c \
		resampling_tools.c resampling_usr.c resampling.c utils.c resampling_math.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I minilibx-linux -I $(LIBFT_DIR) -I headers
LDFLAGS = -L minilibx-linux -lmlx -L $(LIBFT_DIR) -lft -lX11 -lXext -lm

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.phony: all clean fclean re
