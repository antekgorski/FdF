# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:35:59 by agorski           #+#    #+#              #
#    Updated: 2025/01/09 14:35:46 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cc main.c -L minilibx-linux -lmlx -lX11 -lXext
cc main.c utils.c -L minilibx-linux -lmlx -lX11 -lXext -g -L libft -lft -lm