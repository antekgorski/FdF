# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:35:59 by agorski           #+#    #+#              #
#    Updated: 2025/01/10 16:40:21 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = draw_utils.c free_utils.c main.c map_reader.c mlx_utils.c utils.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I minilibx-linux -I $(LIBFT_DIR)
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
